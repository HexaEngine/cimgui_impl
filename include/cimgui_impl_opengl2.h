#ifndef CIMGUI_IMPL_OPENGL2_H
#define CIMGUI_IMPL_OPENGL2_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_OPENGL2
#include "backends/imgui_impl_opengl2.h"
CIMGUI_API bool CImGui_ImplOpenGL2_Init(void);
CIMGUI_API void CImGui_ImplOpenGL2_Shutdown(void);
CIMGUI_API void CImGui_ImplOpenGL2_NewFrame(void);
CIMGUI_API void CImGui_ImplOpenGL2_RenderDrawData(ImDrawData *draw_data);
CIMGUI_API bool CImGui_ImplOpenGL2_CreateFontsTexture(void);
CIMGUI_API void CImGui_ImplOpenGL2_DestroyFontsTexture(void);
CIMGUI_API bool CImGui_ImplOpenGL2_CreateDeviceObjects(void);
CIMGUI_API void CImGui_ImplOpenGL2_DestroyDeviceObjects(void);
#endif

#endif // CIMGUI_IMPL_OPENGL2_H
