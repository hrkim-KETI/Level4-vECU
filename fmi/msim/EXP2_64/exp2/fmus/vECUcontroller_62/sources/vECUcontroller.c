#include "vECUcontroller_macros.h"
#include "vECUcontroller.h"
#include <string.h>
#include "rtwtypes.h"

B_vECUcontroller_T vECUcontroller_B;
ExtU_vECUcontroller_T vECUcontroller_U;
ExtY_vECUcontroller_T vECUcontroller_Y;
static RT_MODEL_vECUcontroller_T vECUcontroller_M_;
RT_MODEL_vECUcontroller_T *const vECUcontroller_M = &vECUcontroller_M_;
void vECUcontroller_step(void)
{
  int32_T i;
  uint8_T rtb_StringtoASCII[255];
  strncpy((char_T *)&rtb_StringtoASCII[0], &vECUcontroller_U.In1[0], 255U);
  FMIToSocket(vECUcontroller_P.stepSize, &rtb_StringtoASCII[0],
              vECUcontroller_P.fmuNum);
  SocketToFMI(&vECUcontroller_B.CCaller_o2[0], vECUcontroller_P.fmuNum);
  for (i = 0; i < 255; i++) {
    vECUcontroller_Y.Out1[i] = (int8_T)vECUcontroller_B.CCaller_o2[i];
  }

  vECUcontroller_Y.Out1[255] = '\x00';
  fmu_LogOutput();
}

void vECUcontroller_initialize(void)
{
  (void) memset((void *)vECUcontroller_M, 0,
                sizeof(RT_MODEL_vECUcontroller_T));
  (void) memset(((void *) &vECUcontroller_B), 0,
                sizeof(B_vECUcontroller_T));
  (void) memset(vECUcontroller_U.In1, 0,
                256U*sizeof(char_T));
  (void) memset(&vECUcontroller_Y.Out1[0], 0,
                256U*sizeof(char_T));
  initSocket(vECUcontroller_P.portVal, vECUcontroller_P.fmuNum);
}

void vECUcontroller_terminate(void)
{
  deinitSocket();
}
