/* Copyright 2021-2022 The MathWorks, Inc. */
/*
 * @file: RTWCG_FMU_util.h
 *  
 * @brief FMU path handling util function. This file is included during FMU code generation.
 *      
 */

#ifndef RTWCG_FMU_util_h
#define RTWCG_FMU_util_h

#ifdef __cplusplus
extern "C" {
#endif

#include "FMUCG_Target.h"

const char* raccelDeployLocation(void);
//current FMU unzip directory
#if FMU_CG_TARGET == FMUCG_PROTECTED_MODEL
int saveRapidSimulationMode(int);
const char* fmu_resourceLocation(void);
#elif FMU_CG_TARGET == FMUCG_MCC || FMU_CG_TARGET == FMUCG_GRT
const char* fmu_resourceLocation(void);
//rapid accel deployment dll and reosurce location
char* fmu_deploymentDLLLocation(const char* deploy, const char* uid, const char* model, const char* dllName, int x64Format);
char* fmu_deploymentResourceLocation(const char* deploy, const char* uid, const char* model, int root, int fmuVersion);
#else
extern const char* fmu_resourceLocation(void);
#endif

#if FMU_CG_TARGET == FMUCG_NESTEDFMU
extern const void* fmu_callback(int fmuVersion);
extern int fmu_fmuVisible(void);
extern int fmu_fmuLogging(void);
extern char* fmu_instanceName(void);
extern int fmu_parameterUpdated(void);
extern void fmu_clearParameterUpdated(void);
#endif

//nested FMU dll and resources directory
char* fmu_nestedDLLLocation(const char* uid, const char* model, const char* dllName, int x64Format);
char* fmu_nestedResourceLocation(const char* uid, const char* model, int root, int fmuVersion);

//convert uri to local path
char* uriToLocal(const char *uri);

extern int fmu_restoreSimScapeInitialState(void);

#ifdef __cplusplus
}
#endif

#endif
