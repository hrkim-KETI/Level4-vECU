#include "customcode_veqPQ6t7OguU0or0NkrbRE.h"
#ifdef __cplusplus
extern "C" {
#endif


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC extern const char_T *get_dll_checksum_veqPQ6t7OguU0or0NkrbRE(void);
DLL_EXPORT_CC extern int32_T initSocket_veqPQ6t7OguU0or0NkrbRE(int32_T portNumber, int32_T fmuNum);
DLL_EXPORT_CC extern void deinitSocket_veqPQ6t7OguU0or0NkrbRE(void);
DLL_EXPORT_CC extern int32_T SocketToFMI_veqPQ6t7OguU0or0NkrbRE(uint8_T *canFrame, int32_T fmuNum);
DLL_EXPORT_CC extern int32_T FMIToSocket_veqPQ6t7OguU0or0NkrbRE(real_T stepSize, const uint8_T *canFrame, int32_T fmuNum);

/* Function Definitions */
DLL_EXPORT_CC const uint8_T *get_checksum_source_info(int32_T *size);
#ifdef __cplusplus
}
#endif

