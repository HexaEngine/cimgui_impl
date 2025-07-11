#ifndef CIMGUI_IMPL_DX11_H
#define CIMGUI_IMPL_DX11_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_D3D11
typedef struct ID3D11Device ID3D11Device;
typedef struct ID3D11DeviceContext ID3D11DeviceContext;
#include "backends/imgui_impl_dx11.h"
CIMGUI_API bool CImGui_ImplDX11_Init(ID3D11Device *device, ID3D11DeviceContext *device_context);
CIMGUI_API void CImGui_ImplDX11_Shutdown();
CIMGUI_API void CImGui_ImplDX11_NewFrame();
CIMGUI_API void CImGui_ImplDX11_RenderDrawData(ImDrawData *draw_data);
CIMGUI_API void CImGui_ImplDX11_InvalidateDeviceObjects();
CIMGUI_API bool CImGui_ImplDX11_CreateDeviceObjects();
#endif

#endif // CIMGUI_IMPL_DX11_H
