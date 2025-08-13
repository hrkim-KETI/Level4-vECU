#ifndef vECUcontroller_h_
#define vECUcontroller_h_
#ifndef vECUcontroller_COMMON_INCLUDES_
#define vECUcontroller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif

#include "vECUcontroller_types.h"
#include <string.h>

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#include "../src/vECUwrapper.h";

typedef struct {
  uint8_T CCaller_o2[255];
} B_vECUcontroller_T;

typedef struct {
  char_T In1[256];
} ExtU_vECUcontroller_T;

typedef struct {
  char_T Out1[256];
} ExtY_vECUcontroller_T;

struct P_vECUcontroller_T_ {
  real_T stepSize;
  int32_T fmuNum;
  int32_T portVal;
};

struct tag_RTM_vECUcontroller_T {
  const char_T *errorStatus;
};

extern P_vECUcontroller_T vECUcontroller_P;
extern B_vECUcontroller_T vECUcontroller_B;
extern ExtU_vECUcontroller_T vECUcontroller_U;
extern ExtY_vECUcontroller_T vECUcontroller_Y;
extern void vECUcontroller_initialize(void);
extern void vECUcontroller_step(void);
extern void vECUcontroller_terminate(void);
extern RT_MODEL_vECUcontroller_T *const vECUcontroller_M;
extern void fmu_LogOutput(void);

#endif
