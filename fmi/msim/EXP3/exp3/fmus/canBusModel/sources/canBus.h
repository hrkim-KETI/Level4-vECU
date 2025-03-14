#ifndef _CANBUS_H_
#define _CANBUS_H_

#define CAN_FRAME_DATA_MAXLEN 200
#define CAN_ARBI_FRAME_MAXLEN 32

typedef struct
{
    int sof;
    int id;
    int fd;
    int dlc;
    unsigned char data[CAN_FRAME_DATA_MAXLEN];
} can_frame_t;

typedef struct
{
    int frame_num;
    can_frame_t frame_buf[CAN_ARBI_FRAME_MAXLEN];
} can_arbi_info_t;

typedef enum
{
    Idle = 0,
    Transmit,
    Intermission
} TxState_t;

void fmu_can_init(int fixedstep_us, int can_speed_bps, int canfd_speed_bps);
int fmu_can_arbitration(int sof, int id, int fd, int dlc, const unsigned char *data);
int fmu_can_transmit(int *sof, int *id, int *fd, int *dlc, unsigned char *data);

#endif
