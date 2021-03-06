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

#include "..\D3D12Raytracing\D3D12RaytracingProceduralGeometry\stdafx.h"
#include "..\D3D12xGPU\stdafx.h"

#include "D3D12RaytracingProceduralGeometry.h"

_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
//    D3D12RaytracingProceduralGeometry sample(1280, 720, L"D3D12 Raytracing - Procedural Geometry");
    D3D12RaytracingProceduralGeometry sample(1024, 768, L"D3D12 Raytracing - Procedural Geometry");
//    D3D12RaytracingProceduralGeometry sample(1920, 1080, L"D3D12 Raytracing - Procedural Geometry");
    return Win32Application::Run(&sample, hInstance, nCmdShow);
}


/*
#include "D3D12xGPU.h"


_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
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
    return Win32Application::Run(&sample, hInstance, nCmdShow);
}
*/