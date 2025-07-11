#ifndef CIMGUI_IMPL_SDL2_RENDERER_H
#define CIMGUI_IMPL_SDL2_RENDERER_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_SDL2Renderer
#include "backends/imgui_impl_sdl2renderer.h"
// Follow "Getting Started" link and check examples/ folder to learn about using backends!
CIMGUI_API bool CImGui_ImplSDLRenderer2_Init(SDL_Renderer *renderer);
CIMGUI_API void CImGui_ImplSDLRenderer2_Shutdown();
CIMGUI_API void CImGui_ImplSDLRenderer2_NewFrame();
CIMGUI_API void CImGui_ImplSDLRenderer2_RenderDrawData(ImDrawData *draw_data, SDL_Renderer *renderer);
// Called by Init/NewFrame/Shutdown
CIMGUI_API void CImGui_ImplSDLRenderer2_CreateDeviceObjects();
CIMGUI_API void CImGui_ImplSDLRenderer2_DestroyDeviceObjects();
// (Advanced) Use e.g. if you need to precisely control the timing of texture updates (e.g. for staged rendering), by setting ImDrawData::Textures = NULL to handle this manually.
CIMGUI_API void CImGui_ImplSDLRenderer2_UpdateTexture(ImTextureData* tex);
#endif

#endif // CIMGUI_IMPL_SDL2_RENDERER_H
