#include "cimgui_impl_opengl3.h"

CIMGUI_API bool CImGui_ImplOpenGL3_Init(const char *glsl_version)
{
    return ImGui_ImplOpenGL3_Init(glsl_version);
}

CIMGUI_API void CImGui_ImplOpenGL3_Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
}

CIMGUI_API void CImGui_ImplOpenGL3_NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
}

CIMGUI_API void CImGui_ImplOpenGL3_RenderDrawData(ImDrawData *draw_data)
{
    ImGui_ImplOpenGL3_RenderDrawData(draw_data);
}

CIMGUI_API void CImGui_ImplOpenGL3_UpdateTexture(ImTextureData* tex)
{
    ImGui_ImplOpenGL3_UpdateTexture(tex);
}

CIMGUI_API bool CImGui_ImplOpenGL3_CreateDeviceObjects()
{
    return ImGui_ImplOpenGL3_CreateDeviceObjects();
}

CIMGUI_API void CImGui_ImplOpenGL3_DestroyDeviceObjects()
{
    ImGui_ImplOpenGL3_DestroyDeviceObjects();
}
