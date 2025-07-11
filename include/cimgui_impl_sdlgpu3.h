#ifndef CIMGUI_IMPL_SDLGPU3_H
#define CIMGUI_IMPL_SDLGPU3_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_SDLGPU3
#include "backends/imgui_impl_sdlgpu3.h"
#include "backends/imgui_impl_sdlgpu3_shaders.h"

// Initialization data, for ImGui_ImplSDLGPU_Init()
// - Remember to set ColorTargetFormat to the correct format. If you're rendering to the swapchain, call SDL_GetGPUSwapchainTextureFormat to query the right value
CIMGUI_API bool CImGui_ImplSDLGPU3_Init(ImGui_ImplSDLGPU3_InitInfo *info);
CIMGUI_API void CImGui_ImplSDLGPU3_Shutdown();
CIMGUI_API void CImGui_ImplSDLGPU3_NewFrame();
// - Unlike other backends, the user must call the function ImGui_ImplSDLGPU_PrepareDrawData BEFORE issuing a SDL_GPURenderPass containing ImGui_ImplSDLGPU_RenderDrawData.
//   Calling the function is MANDATORY, otherwise the ImGui will not upload neither the vertex nor the index buffer for the GPU. See imgui_impl_sdlgpu3.cpp for more info.
CIMGUI_API void CImGui_ImplSDLGPU3_PrepareDrawData(ImDrawData *draw_data, SDL_GPUCommandBuffer *command_buffer);
CIMGUI_API void CImGui_ImplSDLGPU3_RenderDrawData(ImDrawData *draw_data, SDL_GPUCommandBuffer *command_buffer, SDL_GPURenderPass *render_pass, SDL_GPUGraphicsPipeline *pipeline);
CIMGUI_API void CImGui_ImplSDLGPU3_CreateDeviceObjects();
CIMGUI_API void CImGui_ImplSDLGPU3_DestroyDeviceObjects();
CIMGUI_API void CImGui_ImplSDLGPU3_GetSPIRVVertexShader(const void** ptr, size_t* size);
CIMGUI_API void CImGui_ImplSDLGPU3_GetSPIRVFragmentShader(const void** ptr, size_t* size);
CIMGUI_API void CImGui_ImplSDLGPU3_GetDXBCVertexShader(const void** ptr, size_t* size);
CIMGUI_API void CImGui_ImplSDLGPU3_GetDXBCPixelShader(const void** ptr, size_t* size);

#endif // CIMGUI_USE_SDLGPU3

#endif // CIMGUI_IMPL_SDLGPU3_H
