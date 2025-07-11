#ifndef CIMGUI_IMPL_SDL2_H
#define CIMGUI_IMPL_SDL2_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_SDL2
#include "backends/imgui_impl_sdl2.h"
CIMGUI_API bool CImGui_ImplSDL2_InitForOpenGL(SDL_Window *window, void *sdl_gl_context);
CIMGUI_API bool CImGui_ImplSDL2_InitForVulkan(SDL_Window *window);
CIMGUI_API bool CImGui_ImplSDL2_InitForD3D(SDL_Window *window);
CIMGUI_API bool CImGui_ImplSDL2_InitForMetal(SDL_Window *window);
CIMGUI_API bool CImGui_ImplSDL2_InitForSDLRenderer(SDL_Window *window, SDL_Renderer *renderer);
CIMGUI_API bool CImGui_ImplSDL2_InitForOther(SDL_Window *window);
CIMGUI_API void CImGui_ImplSDL2_Shutdown(void);
CIMGUI_API void CImGui_ImplSDL2_NewFrame(void);
CIMGUI_API bool CImGui_ImplSDL2_ProcessEvent(const SDL_Event *event);
CIMGUI_API void CImGui_ImplSDL2_SetGamepadMode(ImGui_ImplSDL2_GamepadMode mode, struct _SDL_GameController **manual_gamepads_array, int manual_gamepads_count);
#endif

#endif // CIMGUI_IMPL_SDL2_H
