#ifndef vECUwrapperModel_h_
#define vECUwrapperModel_h_
#ifndef vECUwrapperModel_COMMON_INCLUDES_
#define vECUwrapperModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif

#include "vECUwrapperModel_types.h"
#include <string.h>

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#include "../src/vECUwrapper.h";

typedef struct {
  uint8_T CCaller_o2[256];
} B_vECUwrapperModel_T;

typedef struct {
  char_T In1[256];
} ExtU_vECUwrapperModel_T;

typedef struct {
  char_T Out1[256];
} ExtY_vECUwrapperModel_T;

struct P_vECUwrapperModel_T_ {
  real_T stepSize;
};

struct tag_RTM_vECUwrapperModel_T {
  const char_T *errorStatus;
};

extern P_vECUwrapperModel_T vECUwrapperModel_P;
extern B_vECUwrapperModel_T vECUwrapperModel_B;
extern ExtU_vECUwrapperModel_T vECUwrapperModel_U;
extern ExtY_vECUwrapperModel_T vECUwrapperModel_Y;
extern void vECUwrapperModel_initialize(void);
extern void vECUwrapperModel_step(void);
extern void vECUwrapperModel_terminate(void);
extern RT_MODEL_vECUwrapperModel_T *const vECUwrapperModel_M;
extern void fmu_LogOutput(void);

#endif
