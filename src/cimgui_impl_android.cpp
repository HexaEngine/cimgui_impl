#include "cimgui_impl_android.h"

CIMGUI_API bool CImGui_ImplAndroid_Init(ANativeWindow *window)
{
    return ImGui_ImplAndroid_Init(window);
}
CIMGUI_API int32_t CImGui_ImplAndroid_HandleInputEvent(const AInputEvent *input_event)
{
    return ImGui_ImplAndroid_HandleInputEvent(input_event);
}
CIMGUI_API void CImGui_ImplAndroid_Shutdown()
{
    ImGui_ImplAndroid_Shutdown();
}
CIMGUI_API void CImGui_ImplAndroid_NewFrame()
{
    ImGui_ImplAndroid_NewFrame();
}
