#include "vECUwrapperModel_macros.h"
#include "vECUwrapperModel.h"
#include <string.h>
#include "rtwtypes.h"

B_vECUwrapperModel_T vECUwrapperModel_B;
ExtU_vECUwrapperModel_T vECUwrapperModel_U;
ExtY_vECUwrapperModel_T vECUwrapperModel_Y;
static RT_MODEL_vECUwrapperModel_T vECUwrapperModel_M_;
RT_MODEL_vECUwrapperModel_T *const vECUwrapperModel_M = &vECUwrapperModel_M_;
void vECUwrapperModel_step(void)
{
  int32_T i;
  uint8_T rtb_StringtoASCII[256];
  SocketToFMI(&vECUwrapperModel_B.CCaller_o2[0]);
  for (i = 0; i < 255; i++) {
    vECUwrapperModel_Y.Out1[i] = (int8_T)vECUwrapperModel_B.CCaller_o2[i];
  }

  vECUwrapperModel_Y.Out1[255] = '\x00';
  strncpy((char_T *)&rtb_StringtoASCII[0], &vECUwrapperModel_U.In1[0], 256U);
  FMIToSocket(vECUwrapperModel_P.stepSize, &rtb_StringtoASCII[0]);
  fmu_LogOutput();
}

void vECUwrapperModel_initialize(void)
{
  (void) memset((void *)vECUwrapperModel_M, 0,
                sizeof(RT_MODEL_vECUwrapperModel_T));
  (void) memset(((void *) &vECUwrapperModel_B), 0,
                sizeof(B_vECUwrapperModel_T));
  (void) memset(vECUwrapperModel_U.In1, 0,
                256U*sizeof(char_T));
  (void) memset(&vECUwrapperModel_Y.Out1[0], 0,
                256U*sizeof(char_T));
}

void vECUwrapperModel_terminate(void)
{
}
