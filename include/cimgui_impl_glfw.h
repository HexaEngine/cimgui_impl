#ifndef CIMGUI_IMPL_GLFW_H
#define CIMGUI_IMPL_GLFW_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_GLFW
#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS
typedef struct GLFWwindow GLFWwindow;
typedef struct GLFWmonitor GLFWmonitor;
#else
#include "backends/imgui_impl_glfw.h"
#endif
// Follow "Getting Started" link and check examples/ folder to learn about using backends!
CIMGUI_API bool CImGui_ImplGlfw_InitForOpenGL(GLFWwindow *window, bool install_callbacks);
CIMGUI_API bool CImGui_ImplGlfw_InitForVulkan(GLFWwindow *window, bool install_callbacks);
CIMGUI_API bool CImGui_ImplGlfw_InitForOther(GLFWwindow *window, bool install_callbacks);
CIMGUI_API void CImGui_ImplGlfw_Shutdown(void);
CIMGUI_API void CImGui_ImplGlfw_NewFrame(void);
CIMGUI_API void CImGui_ImplGlfw_InstallCallbacks(GLFWwindow *window);
CIMGUI_API void CImGui_ImplGlfw_RestoreCallbacks(GLFWwindow *window);
CIMGUI_API void CImGui_ImplGlfw_SetCallbacksChainForAllWindows(bool chain_for_all_windows);
CIMGUI_API void CImGui_ImplGlfw_WindowFocusCallback(GLFWwindow *window, int focused);
CIMGUI_API void CImGui_ImplGlfw_CursorEnterCallback(GLFWwindow *window, int entered);
CIMGUI_API void CImGui_ImplGlfw_CursorPosCallback(GLFWwindow *window, double x, double y);
CIMGUI_API void CImGui_ImplGlfw_MouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
CIMGUI_API void CImGui_ImplGlfw_ScrollCallback(GLFWwindow *window, double xoffset, double yoffset);
CIMGUI_API void CImGui_ImplGlfw_KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
CIMGUI_API void CImGui_ImplGlfw_CharCallback(GLFWwindow *window, unsigned int c);
CIMGUI_API void CImGui_ImplGlfw_MonitorCallback(GLFWmonitor *monitor, int event);
CIMGUI_API void CImGui_ImplGlfw_Sleep(int milliseconds);
#endif

#endif // CIMGUI_IMPL_GLFW_H
