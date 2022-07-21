//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

#include "stdafx.h"
#include "D3D12RaytracingProceduralGeometry.h"
#include "MainRaytracingProceduralGeometry.h"

_Use_decl_annotations_
int WINAPI WinMainRaytracingProceduralGeometry(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    D3D12RaytracingProceduralGeometry sample(1280, 720, L"D3D12 Raytracing - Procedural Geometry");
    return Win32Application::Run(&sample, hInstance, nCmdShow);
}

bool MainRaytracingProceduralGeometry::run(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    D3D12RaytracingProceduralGeometry sample(1280, 720, L"D3D12 Raytracing - Procedural Geometry");
    Win32Application::Run(&sample, hInstance, nCmdShow);
//    WinMainRaytracingProceduralGeometry(0, 0, "", 0);
    return true;
}

bool MainRaytracingProceduralGeometry::Do(void)
{
    run(hInstance, 0, "", 0);
    return true;
}

bool MainRaytracingProceduralGeometry::create(HINSTANCE _hInstance)
{
    hInstance = _hInstance;
    // Create a new thread which will start at the DoStuff function
    hThread = CreateThread(
        NULL,    // Thread attributes
        0,       // Stack size (0 = use default)
        staticDo, // Thread start address
        this,    // Parameter to pass to the thread
        0,       // Creation flags
        NULL);   // Thread id
    if (hThread == NULL)
    {
        // Thread creation failed.
        // More details can be retrieved by calling GetLastError()
        return false;
    }

    return true;
}

bool MainRaytracingProceduralGeometry::destroy(void)
{
    // Wait for thread to finish execution
//    WaitForSingleObject(hThread, INFINITE);

    // Thread handle must be closed when no longer needed
    CloseHandle(hThread);
    return true;
}
