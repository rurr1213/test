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