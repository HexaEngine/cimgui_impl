#ifndef CIMGUI_IMPL_SDLGPU3_H
#define CIMGUI_IMPL_SDLGPU3_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_SDLGPU3
#include "backends/imgui_impl_sdlgpu3.h"
#include "backends/imgui_impl_sdlgpu3_shaders.h"

CIMGUI_API bool CImGui_ImplSDLGPU3_Init(ImGui_ImplSDLGPU3_InitInfo *info);
CIMGUI_API void CImGui_ImplSDLGPU3_Shutdown();
CIMGUI_API void CImGui_ImplSDLGPU3_NewFrame();
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
