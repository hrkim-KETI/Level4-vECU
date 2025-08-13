#ifndef canBusModel_h_
#define canBusModel_h_
#ifndef canBusModel_COMMON_INCLUDES_
#define canBusModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif

#include "canBusModel_types.h"
#include <string.h>

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#include "../src/canBus.h";
#include "string.h";

typedef struct {
  int32_T Transmit_o2;
  int32_T Transmit_o3;
  int32_T Transmit_o4;
  int32_T Transmit_o5;
  uint8_T Transmit_o6[200];
} B_canBusModel_T;

typedef struct {
  char_T CAN_IN_1[256];
  char_T CAN_IN_2[256];
  char_T CAN_IN_3[256];
  char_T CAN_IN_4[256];
  char_T CAN_IN_5[256];
  char_T CAN_IN_6[256];
  char_T CAN_IN_7[256];
  char_T CAN_IN_8[256];
} ExtU_canBusModel_T;

typedef struct {
  char_T CAN_OUT[256];
} ExtY_canBusModel_T;

struct P_canBusModel_T_ {
  int32_T CanFDSpeed_bps;
  int32_T CanSpeed_bps;
  int32_T FixedStep_us;
  int32_T Constant1_Value;
  int32_T Constant_Value;
  int32_T Constant2_Value;
};

struct tag_RTM_canBusModel_T {
  const char_T *errorStatus;
};

extern P_canBusModel_T canBusModel_P;
extern B_canBusModel_T canBusModel_B;
extern ExtU_canBusModel_T canBusModel_U;
extern ExtY_canBusModel_T canBusModel_Y;
extern void canBusModel_initialize(void);
extern void canBusModel_step(void);
extern void canBusModel_terminate(void);
extern RT_MODEL_canBusModel_T *const canBusModel_M;
extern void fmu_LogOutput(void);

#endif
