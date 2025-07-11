#ifndef CIMGUI_IMPL_WIN32_H
#define CIMGUI_IMPL_WIN32_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_WIN32
#include <windows.h>
#include "backends/imgui_impl_win32.h"
CIMGUI_API bool CImGui_ImplWin32_Init(void *hwnd);
CIMGUI_API bool CImGui_ImplWin32_InitForOpenGL(void *hwnd);
CIMGUI_API void CImGui_ImplWin32_Shutdown();
CIMGUI_API void CImGui_ImplWin32_NewFrame();
CIMGUI_API LRESULT CImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
CIMGUI_API void CImGui_ImplWin32_EnableDpiAwareness();
CIMGUI_API float CImGui_ImplWin32_GetDpiScaleForHwnd(void *hwnd);
CIMGUI_API float CImGui_ImplWin32_GetDpiScaleForMonitor(void *monitor);
CIMGUI_API void CImGui_ImplWin32_EnableAlphaCompositing(void *hwnd);
#endif

#endif // CIMGUI_IMPL_WIN32_H
