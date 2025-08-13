#include "canBusModel_macros.h"
#include "canBusModel.h"
#include <stdio.h>
#include <string.h>
#include "rtwtypes.h"

B_canBusModel_T canBusModel_B;
ExtU_canBusModel_T canBusModel_U;
ExtY_canBusModel_T canBusModel_Y;
static RT_MODEL_canBusModel_T canBusModel_M_;
RT_MODEL_canBusModel_T *const canBusModel_M = &canBusModel_M_;
void canBusModel_step(void)
{
  int32_T rtb_Decode_o1;
  int32_T rtb_Decode_o2;
  int32_T rtb_Decode_o3;
  int32_T rtb_Decode_o4;
  char_T rtb_ASCIItoString_0[256];
  char_T y4[256];
  char_T y4_0[256];
  char_T y4_1[256];
  char_T y4_10[256];
  char_T y4_11[256];
  char_T y4_12[256];
  char_T y4_13[256];
  char_T y4_14[256];
  char_T y4_15[256];
  char_T y4_16[256];
  char_T y4_17[256];
  char_T y4_18[256];
  char_T y4_19[256];
  char_T y4_1a[256];
  char_T y4_1b[256];
  char_T y4_1c[256];
  char_T y4_1d[256];
  char_T y4_1e[256];
  char_T y4_1f[256];
  char_T y4_1g[256];
  char_T y4_1h[256];
  char_T y4_1i[256];
  char_T y4_1j[256];
  char_T y4_1k[256];
  char_T y4_1l[256];
  char_T y4_1m[256];
  char_T y4_1n[256];
  char_T y4_1o[256];
  char_T y4_1p[256];
  char_T y4_1q[256];
  char_T y4_1r[256];
  char_T y4_1s[256];
  char_T y4_1t[256];
  char_T y4_1u[256];
  char_T y4_1v[256];
  char_T y4_1w[256];
  char_T y4_1x[256];
  char_T y4_1y[256];
  char_T y4_2[256];
  char_T y4_3[256];
  char_T y4_4[256];
  char_T y4_5[256];
  char_T y4_6[256];
  char_T y4_7[256];
  char_T y4_8[256];
  char_T y4_9[256];
  char_T y4_a[256];
  char_T y4_b[256];
  char_T y4_c[256];
  char_T y4_d[256];
  char_T y4_e[256];
  char_T y4_f[256];
  char_T y4_g[256];
  char_T y4_h[256];
  char_T y4_i[256];
  char_T y4_j[256];
  char_T y4_k[256];
  char_T y4_l[256];
  char_T y4_m[256];
  char_T y4_n[256];
  char_T y4_o[256];
  char_T y4_p[256];
  char_T y4_q[256];
  char_T y4_r[256];
  char_T y4_s[256];
  char_T y4_t[256];
  char_T y4_u[256];
  char_T y4_v[256];
  char_T y4_w[256];
  char_T y4_x[256];
  char_T y4_y[256];
  char_T y4_z[256];
  uint8_T rtb_StringtoASCII[200];
  rtb_Decode_o4 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o1 = 0;
  y4[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_1[0], "%d-%d-%d-%d-%s", &rtb_Decode_o4,
         &rtb_Decode_o3, &rtb_Decode_o2, &rtb_Decode_o1, &y4[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4[0], 200U);
  fmu_can_arbitration(rtb_Decode_o4, rtb_Decode_o3, rtb_Decode_o2, rtb_Decode_o1,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_0[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_2[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_0[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_0[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_3[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_2[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_4[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_2[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_2[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_3[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_5[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_3[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_3[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_4[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_6[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_4[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_4[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_5[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_7[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_5[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_5[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_6[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_8[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_6[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_6[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_7[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_9[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_7[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_7[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_8[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_10[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_8[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_8[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_9[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_11[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_9[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_9[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_a[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_12[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_a[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_a[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_b[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_13[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_b[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_b[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_c[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_14[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_c[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_c[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_d[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_15[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_d[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_d[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_e[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_16[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_e[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_e[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_f[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_17[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_f[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_f[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_g[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_18[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_g[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_g[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_h[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_19[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_h[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_h[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_i[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_20[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_i[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_i[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_j[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_21[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_j[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_j[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_k[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_22[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_k[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_k[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_l[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_23[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_l[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_l[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_m[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_24[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_m[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_m[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_n[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_25[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_n[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_n[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_o[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_26[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_o[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_o[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_p[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_27[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_p[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_p[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_q[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_28[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_q[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_q[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_r[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_29[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_r[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_r[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_s[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_30[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_s[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_s[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_t[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_31[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_t[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_t[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_u[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_32[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_u[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_u[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_v[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_33[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_v[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_v[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_w[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_34[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_w[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_w[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_x[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_35[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_x[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_x[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_y[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_36[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_y[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_y[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_z[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_37[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_z[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_z[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_10[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_38[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_10[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_10[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_11[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_39[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_11[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_11[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_12[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_40[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_12[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_12[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_13[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_41[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_13[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_13[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_14[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_42[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_14[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_14[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_15[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_43[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_15[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_15[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_16[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_44[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_16[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_16[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_17[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_45[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_17[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_17[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_18[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_46[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_18[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_18[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_19[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_47[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_19[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_19[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1a[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_48[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1a[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1a[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1b[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_49[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1b[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1b[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1c[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_50[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1c[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1c[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1d[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_51[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1d[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1d[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1e[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_52[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1e[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1e[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1f[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_53[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1f[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1f[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1g[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_54[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1g[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1g[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1h[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_55[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1h[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1h[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1i[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_56[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1i[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1i[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1j[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_57[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1j[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1j[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1k[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_58[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1k[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1k[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1l[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_59[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1l[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1l[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1m[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_60[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1m[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1m[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1n[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_61[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1n[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1n[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1o[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_62[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1o[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1o[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1p[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_63[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1p[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1p[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1q[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_64[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1q[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1q[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1r[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_65[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1r[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1r[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1s[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_66[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1s[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1s[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1t[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_67[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1t[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1t[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1u[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_68[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1u[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1u[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1v[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_69[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1v[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1v[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1w[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_70[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1w[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1w[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1x[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_71[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1x[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1x[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  rtb_Decode_o1 = 0;
  rtb_Decode_o2 = 0;
  rtb_Decode_o3 = 0;
  rtb_Decode_o4 = 0;
  y4_1y[0] = '\x00';
  sscanf(&canBusModel_U.CAN_IN_72[0], "%d-%d-%d-%d-%s", &rtb_Decode_o1,
         &rtb_Decode_o2, &rtb_Decode_o3, &rtb_Decode_o4, &y4_1y[0]);
  strncpy((char_T *)&rtb_StringtoASCII[0], &y4_1y[0], 200U);
  fmu_can_arbitration(rtb_Decode_o1, rtb_Decode_o2, rtb_Decode_o3, rtb_Decode_o4,
                      &rtb_StringtoASCII[0]);
  fmu_can_transmit(&canBusModel_B.Transmit_o2, &canBusModel_B.Transmit_o3,
                   &canBusModel_B.Transmit_o4, &canBusModel_B.Transmit_o5,
                   &canBusModel_B.Transmit_o6[0]);
  for (rtb_Decode_o4 = 0; rtb_Decode_o4 < 200; rtb_Decode_o4++) {
    rtb_ASCIItoString_0[rtb_Decode_o4] = (int8_T)
      canBusModel_B.Transmit_o6[rtb_Decode_o4];
  }

  for (rtb_Decode_o4 = 0; rtb_Decode_o4 < 56; rtb_Decode_o4++) {
    rtb_ASCIItoString_0[rtb_Decode_o4 + 200] = '\x00';
  }

  snprintf(&canBusModel_Y.CAN_OUT[0], 256U, "%d-%d-%d-%d-%s",
           canBusModel_B.Transmit_o2, canBusModel_B.Transmit_o3,
           canBusModel_B.Transmit_o4, canBusModel_B.Transmit_o5,
           &rtb_ASCIItoString_0[0]);
  fmu_LogOutput();
}

void canBusModel_initialize(void)
{
  (void) memset((void *)canBusModel_M, 0,
                sizeof(RT_MODEL_canBusModel_T));
  (void) memset(((void *) &canBusModel_B), 0,
                sizeof(B_canBusModel_T));
  (void) memset((void *)&canBusModel_U, 0,
                sizeof(ExtU_canBusModel_T));
  (void) memset(&canBusModel_Y.CAN_OUT[0], 0,
                256U*sizeof(char_T));
  fmu_can_init(canBusModel_P.FixedStep_us * canBusModel_P.Constant1_Value,
               canBusModel_P.CanSpeed_bps * canBusModel_P.Constant_Value,
               canBusModel_P.CanFDSpeed_bps * canBusModel_P.Constant2_Value);
}

void canBusModel_terminate(void)
{
}
