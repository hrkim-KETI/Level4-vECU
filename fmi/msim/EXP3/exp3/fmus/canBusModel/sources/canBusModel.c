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
  char_T y4_2[256];
  char_T y4_3[256];
  char_T y4_4[256];
  char_T y4_5[256];
  char_T y4_6[256];
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
