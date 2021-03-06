/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
// Original file Copyright Crytek GMBH or its affiliates, used under license.

// Description : Shared parameters manager interface.


#ifndef CRYINCLUDE_CRYACTION_ISHAREDPARAMSMANAGER_H
#define CRYINCLUDE_CRYACTION_ISHAREDPARAMSMANAGER_H
#pragma once

#include <SmartPointersHelpers.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Forward declaration of shared parameters type information class.
////////////////////////////////////////////////////////////////////////////////////////////////////
class CSharedParamsTypeInfo;

////////////////////////////////////////////////////////////////////////////////////////////////////
// Forward declaration of shared parameters interface class.
////////////////////////////////////////////////////////////////////////////////////////////////////
class ISharedParams;

////////////////////////////////////////////////////////////////////////////////////////////////////
// Shared parameters pointers.
////////////////////////////////////////////////////////////////////////////////////////////////////
DECLARE_SMART_POINTERS(ISharedParams);

////////////////////////////////////////////////////////////////////////////////////////////////////
// Shared parameters manager interface class.
////////////////////////////////////////////////////////////////////////////////////////////////////
class ISharedParamsManager
{
public:
    virtual ~ISharedParamsManager(){}
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Generate unique 32 bit crc.
    //
    // Params: pName - unique name
    //
    // Return: unique 32 bit crc
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual uint32 GenerateCRC32(const char* pName) = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Register shared parameters.
    //
    // Params: crc32        - unique 32 bit crc
    //               sharedParams - shared parameters
    //
    // Return: pointer to shared parameters
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ISharedParamsConstPtr Register(uint32 crc32, const ISharedParams& sharedParams) = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Register shared parameters.
    //
    // Params: pName        - unique name
    //               sharedParams - shared parameters
    //
    // Return: pointer to shared parameters
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ISharedParamsConstPtr Register(const char* pName, const ISharedParams& sharedParams) = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Remove shared parameters.
    //
    // Params: crc32 - unique 32 bit crc
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void Remove(uint32 crc32) = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Remove shared parameters.
    //
    // Params: pName - unique name
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void Remove(const char* pName) = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Remove all shared parameters by type.
    //
    // Params: typeInfo - type information of to be removed
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void RemoveByType(const CSharedParamsTypeInfo& typeInfo) = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Get shared parameters.
    //
    // Params: crc32 - unique 32 bit crc
    //
    // Return: pointer to shared parameters
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ISharedParamsConstPtr Get(uint32 crc32) const = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Get shared parameters.
    //
    // Params: pName - unique name
    //
    // Return: pointer to shared parameters
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ISharedParamsConstPtr Get(const char* pName) const = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Reset.
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void Reset() = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Release.
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void Release() = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    // Get memory statistics.
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void GetMemoryStatistics(ICrySizer* pSizer) = 0;
};

#endif // CRYINCLUDE_CRYACTION_ISHAREDPARAMSMANAGER_H
