#include "cimgui_impl_glfw.h"

CIMGUI_API bool CImGui_ImplGlfw_InitForOpenGL(GLFWwindow *window, bool install_callbacks)
{
    return ImGui_ImplGlfw_InitForOpenGL(window, install_callbacks);
}
CIMGUI_API bool CImGui_ImplGlfw_InitForVulkan(GLFWwindow *window, bool install_callbacks)
{
    return ImGui_ImplGlfw_InitForVulkan(window, install_callbacks);
}
CIMGUI_API bool CImGui_ImplGlfw_InitForOther(GLFWwindow *window, bool install_callbacks)
{
    return ImGui_ImplGlfw_InitForOther(window, install_callbacks);
}
CIMGUI_API void CImGui_ImplGlfw_Shutdown()
{
    ImGui_ImplGlfw_Shutdown();
}
CIMGUI_API void CImGui_ImplGlfw_NewFrame()
{
    ImGui_ImplGlfw_NewFrame();
}
#ifdef __EMSCRIPTEN__
CIMGUI_API void CImGui_ImplGlfw_InstallEmscriptenCallbacks(GLFWwindow *window, const char *canvas_selector)
{
    ImGui_ImplGlfw_InstallEmscriptenCallbacks(window, canvas_selector);
}
#endif
CIMGUI_API void CImGui_ImplGlfw_InstallCallbacks(GLFWwindow *window)
{
    ImGui_ImplGlfw_InstallCallbacks(window);
}
CIMGUI_API void CImGui_ImplGlfw_RestoreCallbacks(GLFWwindow *window)
{
    ImGui_ImplGlfw_RestoreCallbacks(window);
}
CIMGUI_API void CImGui_ImplGlfw_SetCallbacksChainForAllWindows(bool chain_for_all_windows)
{
    ImGui_ImplGlfw_SetCallbacksChainForAllWindows(chain_for_all_windows);
}
CIMGUI_API void CImGui_ImplGlfw_WindowFocusCallback(GLFWwindow *window, int focused)
{
    ImGui_ImplGlfw_WindowFocusCallback(window, focused);
}
CIMGUI_API void CImGui_ImplGlfw_CursorEnterCallback(GLFWwindow *window, int entered)
{
    ImGui_ImplGlfw_CursorEnterCallback(window, entered);
}
CIMGUI_API void CImGui_ImplGlfw_CursorPosCallback(GLFWwindow *window, double x, double y)
{
    ImGui_ImplGlfw_CursorPosCallback(window, x, y);
}
CIMGUI_API void CImGui_ImplGlfw_MouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
    ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
}
CIMGUI_API void CImGui_ImplGlfw_ScrollCallback(GLFWwindow *window, double xoffset, double yoffset)
{
    ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
}
CIMGUI_API void CImGui_ImplGlfw_KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
}
CIMGUI_API void CImGui_ImplGlfw_CharCallback(GLFWwindow *window, unsigned int c)
{
    ImGui_ImplGlfw_CharCallback(window, c);
}
CIMGUI_API void CImGui_ImplGlfw_MonitorCallback(GLFWmonitor *monitor, int event)
{
    ImGui_ImplGlfw_MonitorCallback(monitor, event);
}

// GLFW helpers
CIMGUI_API void CImGui_ImplGlfw_Sleep(int milliseconds)
{
    ImGui_ImplGlfw_Sleep(milliseconds);
}
CIMGUI_API float CImGui_ImplGlfw_GetContentScaleForWindow(GLFWwindow *window)
{
    return ImGui_ImplGlfw_GetContentScaleForWindow(window);
}

CIMGUI_API float CImGui_ImplGlfw_GetContentScaleForMonitor(GLFWmonitor *monitor)
{
    return ImGui_ImplGlfw_GetContentScaleForMonitor(monitor);
}
