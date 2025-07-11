#include "cimgui_impl_sdl2.h"
CIMGUI_API bool CImGui_ImplSDL2_InitForOpenGL(SDL_Window *window, void *sdl_gl_context)
{
    return ImGui_ImplSDL2_InitForOpenGL(window, sdl_gl_context);
}
CIMGUI_API bool CImGui_ImplSDL2_InitForVulkan(SDL_Window *window)
{
    return ImGui_ImplSDL2_InitForVulkan(window);
}
CIMGUI_API bool CImGui_ImplSDL2_InitForD3D(SDL_Window *window)
{
    return ImGui_ImplSDL2_InitForD3D(window);
}
CIMGUI_API bool CImGui_ImplSDL2_InitForMetal(SDL_Window *window)
{
    return ImGui_ImplSDL2_InitForMetal(window);
}
CIMGUI_API bool CImGui_ImplSDL2_InitForSDLRenderer(SDL_Window *window, SDL_Renderer *renderer)
{
    return ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
}
CIMGUI_API bool CImGui_ImplSDL2_InitForOther(SDL_Window *window)
{
    return ImGui_ImplSDL2_InitForOther(window);
}
CIMGUI_API void CImGui_ImplSDL2_Shutdown()
{
    ImGui_ImplSDL2_Shutdown();
}
CIMGUI_API void CImGui_ImplSDL2_NewFrame()
{
    ImGui_ImplSDL2_NewFrame();
}
CIMGUI_API bool CImGui_ImplSDL2_ProcessEvent(const SDL_Event *event)
{
    return ImGui_ImplSDL2_ProcessEvent(event);
}
CIMGUI_API void CImGui_ImplSDL2_SetGamepadMode(ImGui_ImplSDL2_GamepadMode mode, struct _SDL_GameController **manual_gamepads_array, int manual_gamepads_count)
{
    ImGui_ImplSDL2_SetGamepadMode(mode, manual_gamepads_array, manual_gamepads_count);
}
