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
#include "D3D12xGPU.h"
#include "MainD3D12xGPU.h"

_Use_decl_annotations_
int WINAPI WinMainD3D12xGPU(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    // Declare this process to be high DPI aware, and prevent automatic scaling 
    HINSTANCE hUser32 = LoadLibrary(L"user32.dll");
    if (hUser32)
    {
        typedef BOOL(WINAPI * LPSetProcessDPIAware)(void);
        LPSetProcessDPIAware pSetProcessDPIAware = (LPSetProcessDPIAware)GetProcAddress(hUser32, "SetProcessDPIAware");
        if (pSetProcessDPIAware)
        {
            pSetProcessDPIAware();
        }
        FreeLibrary(hUser32);
    }

    D3D12xGPU sample(1280, 720, L"D3D12 xGPU sample");
    return Win32Application::Run(&sample, hInstance, nCmdShow);
}

bool MainD3D12xGPU::run(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    // Declare this process to be high DPI aware, and prevent automatic scaling 
    HINSTANCE hUser32 = LoadLibrary(L"user32.dll");
    if (hUser32)
    {
        typedef BOOL(WINAPI* LPSetProcessDPIAware)(void);
        LPSetProcessDPIAware pSetProcessDPIAware = (LPSetProcessDPIAware)GetProcAddress(hUser32, "SetProcessDPIAware");
        if (pSetProcessDPIAware)
        {
            pSetProcessDPIAware();
        }
        FreeLibrary(hUser32);
    }

    D3D12xGPU sample(1280, 720, L"D3D12 xGPU sample");
    Win32Application::Run(&sample, hInstance, nCmdShow);
    //    WinMainRaytracingProceduralGeometry(0, 0, "", 0);
    return true;
}

bool MainD3D12xGPU::Do(void)
{
    run(hInstance, 0, "", SW_NORMAL);
    return true;
}

bool MainD3D12xGPU::create(HINSTANCE _hInstance)
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

bool MainD3D12xGPU::destroy(void)
{
    // Wait for thread to finish execution
//    WaitForSingleObject(hThread, INFINITE);

    // Thread handle must be closed when no longer needed
    CloseHandle(hThread);
    return true;
}
