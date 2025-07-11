#ifndef CIMGUI_IMPL_ANDROID_H
#define CIMGUI_IMPL_ANDROID_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_ANDROID
#include "backends/imgui_impl_android.h"
// Follow "Getting Started" link and check examples/ folder to learn about using backends!
CIMGUI_API bool CImGui_ImplAndroid_Init(ANativeWindow *window);
CIMGUI_API int32_t CImGui_ImplAndroid_HandleInputEvent(const AInputEvent *input_event);
CIMGUI_API void CImGui_ImplAndroid_Shutdown();
CIMGUI_API void CImGui_ImplAndroid_NewFrame();
#endif

#endif // CIMGUI_IMPL_ANDROID_H
