#ifndef CIMGUI_IMPL_SDL3_RENDERER_H
#define CIMGUI_IMPL_SDL3_RENDERER_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_SDL3Renderer
#include "backends/imgui_impl_sdl3renderer.h"
CIMGUI_API bool CImGui_ImplSDLRenderer3_Init(SDL_Renderer *renderer);
CIMGUI_API void CImGui_ImplSDLRenderer3_Shutdown();
CIMGUI_API void CImGui_ImplSDLRenderer3_NewFrame();
CIMGUI_API void CImGui_ImplSDLRenderer3_RenderDrawData(ImDrawData *draw_data, SDL_Renderer *renderer);
CIMGUI_API bool CImGui_ImplSDLRenderer3_CreateFontsTexture();
CIMGUI_API void CImGui_ImplSDLRenderer3_DestroyFontsTexture();
CIMGUI_API bool CImGui_ImplSDLRenderer3_CreateDeviceObjects();
CIMGUI_API void CImGui_ImplSDLRenderer3_DestroyDeviceObjects();
#endif

#endif // CIMGUI_IMPL_SDL3_RENDERER_H
