#include "cimgui_impl_dx10.h"
CIMGUI_API bool CImGui_ImplDX10_Init(ID3D10Device *device)
{
    return ImGui_ImplDX10_Init(device);
}
CIMGUI_API void CImGui_ImplDX10_Shutdown()
{
    ImGui_ImplDX10_Shutdown();
}
CIMGUI_API void CImGui_ImplDX10_NewFrame()
{
    ImGui_ImplDX10_NewFrame();
}
CIMGUI_API void CImGui_ImplDX10_RenderDrawData(ImDrawData *draw_data)
{
    ImGui_ImplDX10_RenderDrawData(draw_data);
}
CIMGUI_API void CImGui_ImplDX10_InvalidateDeviceObjects()
{
    ImGui_ImplDX10_InvalidateDeviceObjects();
}
CIMGUI_API bool CImGui_ImplDX10_CreateDeviceObjects()
{
    return ImGui_ImplDX10_CreateDeviceObjects();
}
