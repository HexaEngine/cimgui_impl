#ifndef CIMGUI_IMPL_DX12_H
#define CIMGUI_IMPL_DX12_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_D3D12
#include <d3d12.h>
#include "backends/imgui_impl_dx12.h"
CIMGUI_API bool CImGui_ImplDX12_Init(ImGui_ImplDX12_InitInfo *info);
CIMGUI_API void CImGui_ImplDX12_Shutdown();
CIMGUI_API void CImGui_ImplDX12_NewFrame();
CIMGUI_API void CImGui_ImplDX12_RenderDrawData(ImDrawData *draw_data, ID3D12GraphicsCommandList *graphics_command_list);
CIMGUI_API void CImGui_ImplDX12_InvalidateDeviceObjects();
CIMGUI_API bool CImGui_ImplDX12_CreateDeviceObjects();
#endif

#endif // CIMGUI_IMPL_DX12_H
