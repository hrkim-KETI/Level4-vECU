#include "canBus.h"
#include "string.h"

int sim_step_us;
int can_bit_time_ns;
int canfd_bit_time_ns;

can_arbi_info_t can_arbi_info;

TxState_t tx_state;
can_frame_t tx_can_frame;
int tx_delay_cnt;
int tx_delay;
int intermission_delay_cnt;
int intermission_delay;

int insert_can_frame(can_frame_t *p_can_frame)
{
    int ret;

    if(can_arbi_info.frame_num == 0)
    {
        memcpy(&can_arbi_info.frame_buf[0], p_can_frame, sizeof(can_frame_t));
        can_arbi_info.frame_num++;

        ret = 0;
    }
    else if((can_arbi_info.frame_num > 0) && (can_arbi_info.frame_num < CAN_ARBI_FRAME_MAXLEN))
    {
        int target_node_num = can_arbi_info.frame_num + 1;
        int parent_node_num = target_node_num / 2;

        while(parent_node_num != 0)
        {
            if(can_arbi_info.frame_buf[parent_node_num-1].id > p_can_frame->id)
            {
                memcpy(&can_arbi_info.frame_buf[target_node_num-1], &can_arbi_info.frame_buf[parent_node_num-1], sizeof(can_frame_t));
                target_node_num = parent_node_num;
                parent_node_num = target_node_num / 2;
            }
            else
            {
                break;
            }
        }

        memcpy(&can_arbi_info.frame_buf[target_node_num-1], p_can_frame, sizeof(can_frame_t));
        can_arbi_info.frame_num++;

        ret = 0;
    }
    else
    {
        ret = 1;
    }

    return ret;
}

int remove_can_frame(can_frame_t *p_can_frame)
{
    int ret;

    if((can_arbi_info.frame_num > 0) && (can_arbi_info.frame_num <= CAN_ARBI_FRAME_MAXLEN))
    {
        memcpy(p_can_frame, &can_arbi_info.frame_buf[0], sizeof(can_frame_t));
        can_arbi_info.frame_num--;

        int target_node_num = 1;
        int child_node_left_num = target_node_num * 2;
        int child_node_right_num = (target_node_num * 2) + 1;

        while(!(child_node_left_num > can_arbi_info.frame_num))
        {
            if(child_node_right_num > can_arbi_info.frame_num)
            {
                if(can_arbi_info.frame_buf[child_node_left_num-1].id < can_arbi_info.frame_buf[can_arbi_info.frame_num].id)
                {
                    memcpy(&can_arbi_info.frame_buf[target_node_num-1], &can_arbi_info.frame_buf[child_node_left_num-1], sizeof(can_frame_t));
                    target_node_num = child_node_left_num;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(can_arbi_info.frame_buf[child_node_left_num-1].id < can_arbi_info.frame_buf[child_node_right_num-1].id)
                {
                    if(can_arbi_info.frame_buf[child_node_left_num-1].id < can_arbi_info.frame_buf[can_arbi_info.frame_num].id)
                    {
                        memcpy(&can_arbi_info.frame_buf[target_node_num-1], &can_arbi_info.frame_buf[child_node_left_num-1], sizeof(can_frame_t));
                        target_node_num = child_node_left_num;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if(can_arbi_info.frame_buf[child_node_right_num-1].id < can_arbi_info.frame_buf[can_arbi_info.frame_num].id)
                    {
                        memcpy(&can_arbi_info.frame_buf[target_node_num-1], &can_arbi_info.frame_buf[child_node_right_num-1], sizeof(can_frame_t));
                        target_node_num = child_node_right_num;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            child_node_left_num = target_node_num * 2;
            child_node_right_num = (target_node_num * 2) + 1;
        }

        memcpy(&can_arbi_info.frame_buf[target_node_num-1], &can_arbi_info.frame_buf[can_arbi_info.frame_num], sizeof(can_frame_t));

        ret = 0;
    }
    else
    {
        ret = 1;
    }

    return ret;
}

void fmu_can_init(int fixedstep_us, int can_speed_bps, int canfd_speed_bps)
{
    sim_step_us = fixedstep_us;
    can_bit_time_ns = 1000000000 / can_speed_bps;
    canfd_bit_time_ns = 1000000000 / canfd_speed_bps;

    can_arbi_info.frame_num = 0;

    tx_state = Idle;    
    tx_delay_cnt = 0;
    tx_delay = 0;
    intermission_delay_cnt = 0;
    intermission_delay = 0;

    tx_can_frame.sof = 0;
    tx_can_frame.id = 0;
    tx_can_frame.fd = 0;
    tx_can_frame.dlc = 0;
    tx_can_frame.data[0] = 0;
}

int fmu_can_arbitration(int sof, int id, int fd, int dlc, const unsigned char *data)
{
    can_frame_t new_can_frame;
    int ret;

    if(sof == 1)
    {
        printf("id in CAN BUS FMU : %d\n", id);
        new_can_frame.sof = sof;
        new_can_frame.id = id;
        new_can_frame.fd = fd;
        new_can_frame.dlc = dlc;
        memcpy(new_can_frame.data, data, strlen(data)+1);

        ret = insert_can_frame(&new_can_frame);
    }
    else
    {
        // No CAN Frame
        ret = 0;
    }

    return ret;
}

int fmu_can_transmit(int *sof, int *id, int *fd, int *dlc, unsigned char *data)
{
    int ret;
    int frame_len;
    int frame_time_us;
    int intermission_time_us;
    int tx_data_set = 0;

    if(tx_state == Transmit)
    {
        tx_delay_cnt++;
        if(tx_delay_cnt >= tx_delay)
        {
            *sof = tx_can_frame.sof;
            *id = tx_can_frame.id;
            *fd = tx_can_frame.fd;
            *dlc = tx_can_frame.dlc;
            memcpy(data, tx_can_frame.data, strlen(tx_can_frame.data)+1);

            tx_data_set = 1;
            tx_delay_cnt = 0;
            tx_delay = 0;

            intermission_time_us = (3 * can_bit_time_ns) / 1000;
            intermission_delay = intermission_time_us / sim_step_us;
            if((intermission_time_us % sim_step_us) != 0)
            {
                intermission_delay = intermission_delay + 1;
            }
            intermission_delay_cnt = 0;
            tx_state = Intermission;
        }
        else
        {
            // Tx Delay
        }
    }
    else if(tx_state == Intermission)
    {
        intermission_delay_cnt++;
        if(intermission_delay_cnt >= intermission_delay)
        {
            intermission_delay_cnt = 0;
            intermission_delay = 0;
            tx_state = Idle;
        }
        else
        {
            // Intermission Delay
        }
    }

    if(tx_state == Idle)
    {
        ret = remove_can_frame(&tx_can_frame);
        if(ret != 0)
        {
            // No Pending CAN Frame
        }
        else
        {
            if(tx_can_frame.fd == 1)
            {
                frame_len = (tx_can_frame.id > 0x7ff) ? 30 : 11;
                frame_len = frame_len + 14;
                frame_time_us = (frame_len * can_bit_time_ns) / 1000;

                frame_len = (tx_can_frame.dlc > 10) ? 21 : 17;
                frame_len = frame_len + (tx_can_frame.dlc * 8) + 7;
                frame_time_us = frame_time_us + ((frame_len * canfd_bit_time_ns) / 1000);
            }
            else
            {
                frame_len = (tx_can_frame.id > 0x7ff) ? 31 : 11;
                frame_len = frame_len + (tx_can_frame.dlc * 8) + 33;
                frame_time_us = (frame_len * can_bit_time_ns) / 1000;

            }
            
            tx_delay = frame_time_us / sim_step_us;
            if((frame_time_us % sim_step_us) != 0)
            {
                tx_delay = tx_delay + 1;
            }

            tx_delay_cnt = 0;
            tx_state = Transmit;
        }
    }

    if(tx_data_set != 1)
    {
        *sof = 0;
        *id = 0;
        *dlc = 0;
        data[0] = 0;
    }

    return 0;
}
