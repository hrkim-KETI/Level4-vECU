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
  char_T CAN_IN_9[256];
  char_T CAN_IN_10[256];
  char_T CAN_IN_11[256];
  char_T CAN_IN_12[256];
  char_T CAN_IN_13[256];
  char_T CAN_IN_14[256];
  char_T CAN_IN_15[256];
  char_T CAN_IN_16[256];
  char_T CAN_IN_17[256];
  char_T CAN_IN_18[256];
  char_T CAN_IN_19[256];
  char_T CAN_IN_20[256];
  char_T CAN_IN_21[256];
  char_T CAN_IN_22[256];
  char_T CAN_IN_23[256];
  char_T CAN_IN_24[256];
  char_T CAN_IN_25[256];
  char_T CAN_IN_26[256];
  char_T CAN_IN_27[256];
  char_T CAN_IN_28[256];
  char_T CAN_IN_29[256];
  char_T CAN_IN_30[256];
  char_T CAN_IN_31[256];
  char_T CAN_IN_32[256];
  char_T CAN_IN_33[256];
  char_T CAN_IN_34[256];
  char_T CAN_IN_35[256];
  char_T CAN_IN_36[256];
  char_T CAN_IN_37[256];
  char_T CAN_IN_38[256];
  char_T CAN_IN_39[256];
  char_T CAN_IN_40[256];
  char_T CAN_IN_41[256];
  char_T CAN_IN_42[256];
  char_T CAN_IN_43[256];
  char_T CAN_IN_44[256];
  char_T CAN_IN_45[256];
  char_T CAN_IN_46[256];
  char_T CAN_IN_47[256];
  char_T CAN_IN_48[256];
  char_T CAN_IN_49[256];
  char_T CAN_IN_50[256];
  char_T CAN_IN_51[256];
  char_T CAN_IN_52[256];
  char_T CAN_IN_53[256];
  char_T CAN_IN_54[256];
  char_T CAN_IN_55[256];
  char_T CAN_IN_56[256];
  char_T CAN_IN_57[256];
  char_T CAN_IN_58[256];
  char_T CAN_IN_59[256];
  char_T CAN_IN_60[256];
  char_T CAN_IN_61[256];
  char_T CAN_IN_62[256];
  char_T CAN_IN_63[256];
  char_T CAN_IN_64[256];
  char_T CAN_IN_65[256];
  char_T CAN_IN_66[256];
  char_T CAN_IN_67[256];
  char_T CAN_IN_68[256];
  char_T CAN_IN_69[256];
  char_T CAN_IN_70[256];
  char_T CAN_IN_71[256];
  char_T CAN_IN_72[256];
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
