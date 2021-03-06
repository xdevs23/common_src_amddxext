/*
***************************************************************************************************
*
*  Copyright (c) 2012-2016 Advanced Micro Devices, Inc. All rights reserved.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  AmdDxExtASICInfo.h
*
* @brief
*    AMD D3D ASIC Info Extension API include file.
***************************************************************************************************
*/

#ifndef _AMDDXEXTASICINFO_H_
#define _AMDDXEXTASICINFO_H_

const unsigned int AmdDxASICInfoMaxGPUCount      = 8;   ///< Maximum GPU Count

/**
***************************************************************************************************
* @brief
*    AmdDxASICInfoChipFamily - Enumerates chip family.
*
***************************************************************************************************
*/
enum AmdDxASICInfoChipFamily
{
    AmdDxChipFamily_Unknown,
    AmdDxChipFamily_GFX6,
    AmdDxChipFamily_GFX7,
    AmdDxChipFamily_GFX8,
    AmdDxChipFamily_GFX9,
    AmdDxChipFamily_GFX10,
};

/**
***************************************************************************************************
* @brief
*    AmdDxExtASICInfoHWInfo - Structure for video graphics hardware info.
*
***************************************************************************************************
*/
struct AmdDxASICInfoHWInfo
{
    AmdDxASICInfoChipFamily  chipFamily;    ///< Chip family
    UINT        chipID;                     ///< Chip ID
    UINT        revisionID;                 ///< Revision ID
    UINT64      gpuCounterFrequency;        ///< GPU counter frequency
    UINT64      coreClockInHz;              ///< Core clock in Hz
    UINT64      memClockInHz;               ///< Memory clock in Hz
    UINT64      videoMemSize;               ///< Size of video memory
    UINT        numShaderEngines;           ///< Total shader engine
    UINT        numShaderArraysPerSE;       ///< Number of shader arrays per shader engine
    UINT        totalCU;                    ///< Total compute unit
    UINT        numSimdsPerCU;              ///< Number of SIMDs per CU
    UINT        reserved[512];              ///< Reserved for further extensions
};

/**
***************************************************************************************************
* @brief
*    AmdDxASICInfo struct - Structure filled by driver to provide video graphics hardware and
*    driver info.
*
***************************************************************************************************
*/
struct AmdDxASICInfo
{
    AmdDxASICInfoHWInfo     hwInfo[AmdDxASICInfoMaxGPUCount];  ///< Hardware specific information
    UINT        gpuCount;                                      ///< Number of active GPUs
    UINT        reserved[512];                                 ///< Reserved for further extensions
};

/**
***************************************************************************************************
* @brief
*    AmdDxASICInfoParam struct - Structure filled by the application to pass current extension
*    version and pointer to AmdDxASICInfo structure object.
*
***************************************************************************************************
*/
struct AmdDxASICInfoParam
{
    AmdDxASICInfo*  pASICInfo;                  ///< Pointer to the info object
};

#endif //_AMDDXEXTASICINFO_H_
