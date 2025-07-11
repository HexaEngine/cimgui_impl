#ifndef CIMGUI_IMPL_DX10_H
#define CIMGUI_IMPL_DX10_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_D3D10
typedef struct ID3D10Device ID3D10Device;
#include "backends/imgui_impl_dx10.h"
CIMGUI_API bool CImGui_ImplDX10_Init(ID3D10Device *device);
CIMGUI_API void CImGui_ImplDX10_Shutdown();
CIMGUI_API void CImGui_ImplDX10_NewFrame();
CIMGUI_API void CImGui_ImplDX10_RenderDrawData(ImDrawData *draw_data);
CIMGUI_API bool CImGui_ImplDX10_CreateDeviceObjects();
CIMGUI_API void CImGui_ImplDX10_InvalidateDeviceObjects();
#endif

#endif // CIMGUI_IMPL_DX10_H
