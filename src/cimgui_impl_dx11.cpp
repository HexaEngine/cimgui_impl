#include "cimgui_impl_dx11.h"
CIMGUI_API bool CImGui_ImplDX11_Init(ID3D11Device *device, ID3D11DeviceContext *device_context)
{
    return ImGui_ImplDX11_Init(device, device_context);
}
CIMGUI_API void CImGui_ImplDX11_Shutdown()
{
    ImGui_ImplDX11_Shutdown();
}
CIMGUI_API void CImGui_ImplDX11_NewFrame()
{
    ImGui_ImplDX11_NewFrame();
}
CIMGUI_API void CImGui_ImplDX11_RenderDrawData(ImDrawData *draw_data)
{
    ImGui_ImplDX11_RenderDrawData(draw_data);
}
CIMGUI_API void CImGui_ImplDX11_InvalidateDeviceObjects()
{
    ImGui_ImplDX11_InvalidateDeviceObjects();
}
CIMGUI_API bool CImGui_ImplDX11_CreateDeviceObjects()
{
    return ImGui_ImplDX11_CreateDeviceObjects();
}
