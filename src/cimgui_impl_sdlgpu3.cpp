#include "cimgui_impl_sdlgpu3.h"

CIMGUI_API bool CImGui_ImplSDLGPU3_Init(ImGui_ImplSDLGPU3_InitInfo *info) 
{
    return ImGui_ImplSDLGPU3_Init(info);
}
CIMGUI_API void CImGui_ImplSDLGPU3_Shutdown() 
{
    ImGui_ImplSDLGPU3_Shutdown();
}
CIMGUI_API void CImGui_ImplSDLGPU3_NewFrame() 
{
    ImGui_ImplSDLGPU3_NewFrame();
}
CIMGUI_API void CImGui_ImplSDLGPU3_PrepareDrawData(ImDrawData *draw_data, SDL_GPUCommandBuffer *command_buffer)
{
    ImGui_ImplSDLGPU3_PrepareDrawData(draw_data, command_buffer);
}
CIMGUI_API void CImGui_ImplSDLGPU3_RenderDrawData(ImDrawData *draw_data, SDL_GPUCommandBuffer *command_buffer, SDL_GPURenderPass *render_pass, SDL_GPUGraphicsPipeline *pipeline) 
{
    ImGui_ImplSDLGPU3_RenderDrawData(draw_data, command_buffer, render_pass, pipeline);
}
CIMGUI_API void CImGui_ImplSDLGPU3_CreateDeviceObjects() 
{
    ImGui_ImplSDLGPU3_CreateDeviceObjects();
}
CIMGUI_API void CImGui_ImplSDLGPU3_DestroyDeviceObjects()
{
    ImGui_ImplSDLGPU3_DestroyDeviceObjects();
}

// Shader pointer/size C API (merged signature)
CIMGUI_API void CImGui_ImplSDLGPU3_GetSPIRVVertexShader(const void** ptr, size_t* size) 
{
    if (ptr) *ptr = (const void*)spirv_vertex;
    if (size) *size = sizeof(spirv_vertex);
}
CIMGUI_API void CImGui_ImplSDLGPU3_GetSPIRVFragmentShader(const void** ptr, size_t* size) 
{
    if (ptr) *ptr = (const void*)spirv_fragment;
    if (size) *size = sizeof(spirv_fragment);
}
CIMGUI_API void CImGui_ImplSDLGPU3_GetDXBCVertexShader(const void** ptr, size_t* size) 
{
    if (ptr) *ptr = (const void*)dxbc_vertex;
    if (size) *size = sizeof(dxbc_vertex);
}
CIMGUI_API void CImGui_ImplSDLGPU3_GetDXBCPixelShader(const void** ptr, size_t* size) 
{
    if (ptr) *ptr = (const void*)dxbc_pixel;
    if (size) *size = sizeof(dxbc_pixel);
}
