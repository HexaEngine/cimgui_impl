#ifndef CIMGUI_IMPL_SDL3_H
#define CIMGUI_IMPL_SDL3_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_SDL3
#include "backends/imgui_impl_sdl3.h"
CIMGUI_API bool CImGui_ImplSDL3_InitForOpenGL(SDL_Window *window, void *sdl_gl_context);
CIMGUI_API bool CImGui_ImplSDL3_InitForVulkan(SDL_Window *window);
CIMGUI_API bool CImGui_ImplSDL3_InitForD3D(SDL_Window *window);
CIMGUI_API bool CImGui_ImplSDL3_InitForMetal(SDL_Window *window);
CIMGUI_API bool CImGui_ImplSDL3_InitForSDLRenderer(SDL_Window *window, SDL_Renderer *renderer);
CIMGUI_API bool CImGui_ImplSDL3_InitForSDLGPU(SDL_Window *window);
CIMGUI_API bool CImGui_ImplSDL3_InitForOther(SDL_Window *window);
CIMGUI_API void CImGui_ImplSDL3_Shutdown();
CIMGUI_API void CImGui_ImplSDL3_NewFrame();
CIMGUI_API bool CImGui_ImplSDL3_ProcessEvent(const SDL_Event *event);
CIMGUI_API void CImGui_ImplSDL3_SetGamepadMode(ImGui_ImplSDL3_GamepadMode mode, SDL_Gamepad **manual_gamepads_array = nullptr, int manual_gamepads_count = -1);
#endif

#endif // CIMGUI_IMPL_SDL3_H
