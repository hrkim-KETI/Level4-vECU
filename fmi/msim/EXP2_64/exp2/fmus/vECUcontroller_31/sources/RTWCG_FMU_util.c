#include "vECUcontroller_macros.h"
/* Copyright 2021-2024 The MathWorks, Inc. */
/*
 * @file: RTWCG_FMU_util.c
 *  
 * @brief Definition of FMU path handling util function.
 *      
 */

#include "RTWCG_FMU_util.h"
#include <stdlib.h>
#include <string.h>

#ifdef _WIN64
    const char* separator = "\\";
    const char* x64platform = "x86_64-windows";
    const char* platform = "win64";
#elif defined(_WIN32)
    const char* separator = "\\";
    const char* x64platform = "x86-windows";
    const char* platform = "win32";
#elif defined(__APPLE__) && defined(__aarch64__)
    const char* separator = "/";
    const char* x64platform = "aarch64-darwin";
    const char* platform = "aarch64-darwin";
#elif defined(__APPLE__) && defined(__x86_64__)
    const char* separator = "/";
    const char* x64platform = "x86_64-darwin";
    const char* platform = "darwin64";
#elif defined(__linux__)
    const char* separator = "/";
    const char* x64platform = "x86_64-linux";
    const char* platform = "linux64";
#elif defined(__QNXNTO__)
    const char* separator = "/";
    const char* x64platform = "x86_64-slrt";
    const char* platform = "slrt_x64";
#else
    //# error Must specify OS.
#endif
    
#ifdef _WIN32
#include <windows.h> //GetModuleFileNameW
#elif __APPLE__ // maca64/maci64
#include <mach-o/dyld.h>// _NSGetExecutablePath
#else
#include <limits.h>
#include <unistd.h> //readlink
#endif
const char* raccelDeployLocation(void)
{
    static char exePath[1024];
#ifdef _WIN32
    wchar_t path[1024] = { 0 };
    GetModuleFileNameW(NULL, path, 1024);
    int sizeneeded = WideCharToMultiByte(CP_UTF8, 0, path, 1024, NULL, 0, NULL, NULL);
    WideCharToMultiByte(CP_UTF8, 0, path, 1024, &exePath[0], sizeneeded, NULL, NULL);
#elif __APPLE__
     uint32_t size = 1024;
    _NSGetExecutablePath(exePath, &size);
#else
    readlink("/proc/self/exe", exePath, 1024);
#endif
    return &exePath[0];
}


//protected model cg
#if FMU_CG_TARGET == FMUCG_PROTECTED_MODEL
#include "mex.h"
int saveRapidSimulationMode(int flag)
{
    static int rapidSimFlag;
    if(flag >= 0) {
        rapidSimFlag = flag;
    }
    return rapidSimFlag;
}

const char* fmu_resourceLocation(void) {
    static char dllPath[1024];
    const char* postFix = "/slprj/_fmu";
    memset(&dllPath[0], 0, sizeof(dllPath));
    if (saveRapidSimulationMode(-1) > 0) {
        const char* raccelPath = raccelDeployLocation();
        strcpy(dllPath, raccelPath);
#ifdef _WIN32
        char* pbase = strstr(&dllPath[0], "\\slprj\\raccel");
        *pbase = '\0';
#else
        char* pbase = strstr(&dllPath[0], "/slprj/raccel");
        *pbase = '\0';
#endif
        strcat(dllPath, postFix);
    }
    else {
        mxArray * output = NULL;
        mexCallMATLAB(1,&output, 0, NULL,"Simulink.ModelReference.ProtectedModel.getSimBuildDir");
        char* basePath = mxArrayToUTF8String(output);
        strcat(dllPath, basePath);
        strcat(dllPath, postFix);
        mxFree(basePath);
        mxDestroyArray(output);
    }
    return &dllPath[0];
}
#elif FMU_CG_TARGET == FMUCG_MCC || FMU_CG_TARGET == FMUCG_GRT
const char* fmu_resourceLocation(void) {
    return raccelDeployLocation();
}
#endif
    
     
char* fmu_nestedDLLLocation(const char* uid, const char* model, const char* dllName, int x64Format) {
    static char dllPath[1024];
    memset(&dllPath[0], 0, sizeof(dllPath));
    const char* unziplocation = fmu_resourceLocation();
    strcat(dllPath, unziplocation);
    strcat(dllPath, separator);
    strcat(dllPath, uid);
    if (model != NULL) {
        strcat(dllPath, separator);
        strcat(dllPath, model);
    }
    strcat(dllPath, separator);
    strcat(dllPath, "binaries");
    strcat(dllPath, separator);
    if (x64Format == 1) {
        strcat(dllPath, x64platform);
    }
    else {
        strcat(dllPath, platform);
    }
    strcat(dllPath, separator);
    strcat(dllPath, dllName);
    return dllPath;
}

char* fmu_nestedResourceLocation(const char* uid, const char* model, int root, int fmuVersion)
{
    static char nestedResourcesPath[1024];
    memset(&nestedResourcesPath[0], 0, sizeof(nestedResourcesPath));
    const char* resourceLoc = fmu_resourceLocation();
    if(fmuVersion <= 2) {
#ifdef _WIN32
        strcat(nestedResourcesPath, "file:///");
#else
        strcat(nestedResourcesPath, "file://");
#endif
    }
    strcat(nestedResourcesPath, resourceLoc);  
    strcat(nestedResourcesPath, separator);
    strcat(nestedResourcesPath, uid);
    if (model != NULL) {
        strcat(nestedResourcesPath, separator);
        strcat(nestedResourcesPath, model);
    }
    if (root == 0) {
        strcat(nestedResourcesPath, separator);
        strcat(nestedResourcesPath, "resources");
    }
    return nestedResourcesPath;
}

char* fmu_deploymentDLLLocation(const char* deploy, const char* uid, const char* model, const char* dllName, int x64Format)
{
    static char dllPath[1024];
    memset(&dllPath[0], 0, sizeof(dllPath));
    const char* unziplocation = raccelDeployLocation();
    strcat(dllPath, unziplocation);
    char* pbase = strrchr(dllPath, *separator);
    *pbase = '\0';
    if (deploy != NULL) {
    	strcat(dllPath, separator);
        strcat(dllPath, deploy);
    }
    strcat(dllPath, separator);
    strcat(dllPath, "_fmu");
    strcat(dllPath, separator);
    strcat(dllPath, uid);
    if (model != NULL) {
        strcat(dllPath, separator);
        strcat(dllPath, model);
    }
    strcat(dllPath, separator);
    strcat(dllPath, "binaries");
    strcat(dllPath, separator);
    if (x64Format == 1) {
        strcat(dllPath, x64platform);
    }
    else {
        strcat(dllPath, platform);
    }
    strcat(dllPath, separator);
    strcat(dllPath, dllName);
    return dllPath;
}

char* fmu_deploymentResourceLocation(const char* deploy, const char* uid, const char* model, int root, int fmuVersion)
{
    static char raccelResourcesPath[1024];
    memset(&raccelResourcesPath[0], 0, sizeof(raccelResourcesPath));
    const char* unziplocation = raccelDeployLocation();
    if(fmuVersion <= 2) {
#ifdef _WIN32
    strcat(raccelResourcesPath, "file:///");
#else
    strcat(raccelResourcesPath, "file://");
#endif
    }
    strcat(raccelResourcesPath, unziplocation);
    char* pbase = strrchr(raccelResourcesPath, *separator);
    *pbase = '\0';
    if (deploy != NULL) {
    	strcat(raccelResourcesPath, separator);
        strcat(raccelResourcesPath, deploy);
    }
    strcat(raccelResourcesPath, separator);
    strcat(raccelResourcesPath, "_fmu");
    strcat(raccelResourcesPath, separator);
    strcat(raccelResourcesPath, uid);
    if (model != NULL) {
        strcat(raccelResourcesPath, separator);
        strcat(raccelResourcesPath, model);
    }
    if (root == 0) {
        strcat(raccelResourcesPath, separator);
        strcat(raccelResourcesPath, "resources");
    }
    return raccelResourcesPath;
}

int hex2Dec(char c) {
    if(c<= '9' && c >= '0') {
        return c - '0';
    }
    else if(c <= 'F' && c>= 'A') {
        return c - 'A' + 10;
    }
    else if(c <= 'f' && c>= 'a') {
        return c - 'a' + 10;
    }
    return -1;
}

char URIEncoding(const char enc[3]) {
    int dig1 = hex2Dec(enc[1]);
    int dig2 = hex2Dec(enc[2]);
    //handle 00 - FF
    if( dig1 < 0 || dig1 > 15  || dig2 < 0 || dig2 > 15) {
        return'\0';
    }
    return dig1 * 16 + dig2;
}

void copyToString(const char* c, char* s) {
    const char* begin = c;
    while (*c != '\0') {
        if (*c == '%' && (*(c + 1) !='\0') && (*(c + 2) != '\0')) {
            *s = URIEncoding(c);
            c += 3;
        }
#ifdef _WIN32
        else if(*c == '/') {
            *s = *separator;
            c++;
        }
#endif
        else {
            *s = *c;
            c++;
        }
        if (*s == '\0') {
            return;
        }
        s++;
    }
    s--;
    c--;
    while (*s == *separator && c != begin) {
        *s = '\0';
        s--;
        c--;
    }
}

/*uriToLocal is capable to handle paths with percent encoding:
 *      file://localhost/path/to/fmu
 *      file:/path/to/fmu
 *      file:///path/to/fmu
 */

char* uriToLocal(const char *uri) {

	const char *scheme1 = "file:///";
	const char *scheme2 = "file:/";
	const char* scheme3 = "http";
	const char* scheme4 = "ftp";
	const char* localhost = "/localhost/";
	char* path = (char*)calloc(1024, sizeof(char));

	if (strncmp(uri, scheme1, strlen(scheme1)) == 0) {
        const char *c = &uri[strlen(scheme1)];        
#if defined(__APPLE__) || defined(__linux__) || defined(__QNXNTO__)
        c--;
#endif
		copyToString(c, path);
	} else if (strncmp(uri, scheme2, strlen(scheme2)) == 0) {
		const char *c = &uri[strlen(scheme2)];
        if(strncmp(c, localhost, strlen(localhost)) == 0) {
			c = &uri[strlen(scheme2) + strlen(localhost)];
		}
#if defined(__APPLE__) || defined(__linux__) || defined(__QNXNTO__)
        c--;
#endif
		copyToString(c, path);
	} else if(strncmp(uri, scheme3, strlen(scheme3)) == 0) {
		//do not handle
	} else if(strncmp(uri, scheme4, strlen(scheme4)) == 0) {
		//do not handle
	} else {
		strcpy(path, uri);
	}

	return path;
}
