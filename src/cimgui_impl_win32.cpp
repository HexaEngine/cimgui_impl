#include "cimgui_impl_win32.h"
CIMGUI_API bool CImGui_ImplWin32_Init(void *hwnd)
{
    return ImGui_ImplWin32_Init(hwnd);
}
CIMGUI_API bool CImGui_ImplWin32_InitForOpenGL(void *hwnd)
{
    return ImGui_ImplWin32_Init(hwnd);
}
CIMGUI_API void CImGui_ImplWin32_Shutdown()
{
    ImGui_ImplWin32_Shutdown();
}
CIMGUI_API void CImGui_ImplWin32_NewFrame()
{
    ImGui_ImplWin32_NewFrame();
}
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
CIMGUI_API LRESULT CImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam);
}
CIMGUI_API void CImGui_ImplWin32_EnableDpiAwareness()
{
    ImGui_ImplWin32_EnableDpiAwareness();
}
CIMGUI_API float CImGui_ImplWin32_GetDpiScaleForHwnd(void *hwnd)
{
    return ImGui_ImplWin32_GetDpiScaleForHwnd(hwnd);
}
CIMGUI_API float CImGui_ImplWin32_GetDpiScaleForMonitor(void *monitor)
{
    return ImGui_ImplWin32_GetDpiScaleForMonitor(monitor);
}
CIMGUI_API void CImGui_ImplWin32_EnableAlphaCompositing(void *hwnd)
{
    ImGui_ImplWin32_EnableAlphaCompositing(hwnd);
}
