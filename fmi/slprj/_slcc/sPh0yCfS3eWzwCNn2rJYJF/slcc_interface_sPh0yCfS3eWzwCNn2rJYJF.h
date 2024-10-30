#include "customcode_sPh0yCfS3eWzwCNn2rJYJF.h"
#ifdef __cplusplus
extern "C" {
#endif


/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
DLL_EXPORT_CC extern const char_T *get_dll_checksum_sPh0yCfS3eWzwCNn2rJYJF(void);
DLL_EXPORT_CC extern void fmu_can_init_sPh0yCfS3eWzwCNn2rJYJF(int32_T fixedstep_us, int32_T can_speed_bps, int32_T canfd_speed_bps);
DLL_EXPORT_CC extern int32_T fmu_can_arbitration_sPh0yCfS3eWzwCNn2rJYJF(int32_T sof, int32_T id, int32_T fd, int32_T dlc, const uint8_T *data);
DLL_EXPORT_CC extern int32_T fmu_can_transmit_sPh0yCfS3eWzwCNn2rJYJF(int32_T *sof, int32_T *id, int32_T *fd, int32_T *dlc, uint8_T *data);

/* Function Definitions */
DLL_EXPORT_CC const uint8_T *get_checksum_source_info(int32_T *size);
#ifdef __cplusplus
}
#endif

