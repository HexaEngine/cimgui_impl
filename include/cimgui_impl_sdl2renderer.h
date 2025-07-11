#ifndef CIMGUI_IMPL_SDL2_RENDERER_H
#define CIMGUI_IMPL_SDL2_RENDERER_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_SDL2Renderer
#include "backends/imgui_impl_sdl2renderer.h"
CIMGUI_API bool CImGui_ImplSDLRenderer2_Init(SDL_Renderer *renderer);
CIMGUI_API void CImGui_ImplSDLRenderer2_Shutdown();
CIMGUI_API void CImGui_ImplSDLRenderer2_NewFrame();
CIMGUI_API void CImGui_ImplSDLRenderer2_RenderDrawData(ImDrawData *draw_data, SDL_Renderer *renderer);
CIMGUI_API bool CImGui_ImplSDLRenderer2_CreateFontsTexture();
CIMGUI_API void CImGui_ImplSDLRenderer2_DestroyFontsTexture();
CIMGUI_API bool CImGui_ImplSDLRenderer2_CreateDeviceObjects();
CIMGUI_API void CImGui_ImplSDLRenderer2_DestroyDeviceObjects();
#endif

#endif // CIMGUI_IMPL_SDL2_RENDERER_H
