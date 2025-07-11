#ifndef CIMGUI_IMPL_SDL3_RENDERER_H
#define CIMGUI_IMPL_SDL3_RENDERER_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_SDL3Renderer
#include "backends/imgui_impl_sdl3renderer.h"
// Follow "Getting Started" link and check examples/ folder to learn about using backends!
CIMGUI_API bool CImGui_ImplSDLRenderer3_Init(SDL_Renderer *renderer);
CIMGUI_API void CImGui_ImplSDLRenderer3_Shutdown();
CIMGUI_API void CImGui_ImplSDLRenderer3_NewFrame();
CIMGUI_API void CImGui_ImplSDLRenderer3_RenderDrawData(ImDrawData *draw_data, SDL_Renderer *renderer);
// Called by Init/NewFrame/Shutdown
CIMGUI_API bool CImGui_ImplSDLRenderer3_CreateDeviceObjects();
CIMGUI_API void CImGui_ImplSDLRenderer3_DestroyDeviceObjects();
// (Advanced) Use e.g. if you need to precisely control the timing of texture updates (e.g. for staged rendering), by setting ImDrawData::Textures = NULL to handle this manually.
CIMGUI_API void CImGui_ImplSDLRenderer3_UpdateTexture(ImTextureData* tex);
#endif

#endif // CIMGUI_IMPL_SDL3_RENDERER_H
