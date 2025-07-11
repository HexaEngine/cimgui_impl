#include "cimgui_impl_dx9.h"
CIMGUI_API bool CImGui_ImplDX9_Init(IDirect3DDevice9 *device)
{
    return ImGui_ImplDX9_Init(device);
}
CIMGUI_API void CImGui_ImplDX9_Shutdown()
{
    ImGui_ImplDX9_Shutdown();
}
CIMGUI_API void CImGui_ImplDX9_NewFrame()
{
    ImGui_ImplDX9_NewFrame();
}
CIMGUI_API void CImGui_ImplDX9_RenderDrawData(ImDrawData *draw_data)
{
    ImGui_ImplDX9_RenderDrawData(draw_data);
}
CIMGUI_API void CImGui_ImplDX9_InvalidateDeviceObjects()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
}
CIMGUI_API bool CImGui_ImplDX9_CreateDeviceObjects()
{
    return ImGui_ImplDX9_CreateDeviceObjects();
}
