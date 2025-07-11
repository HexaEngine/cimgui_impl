#include "cimgui_impl_sdl3.h"
CIMGUI_API bool CImGui_ImplSDL3_InitForOpenGL(SDL_Window *window, void *sdl_gl_context)
{
    return ImGui_ImplSDL3_InitForOpenGL(window, sdl_gl_context);
}
CIMGUI_API bool CImGui_ImplSDL3_InitForVulkan(SDL_Window *window)
{
    return ImGui_ImplSDL3_InitForVulkan(window);
}
CIMGUI_API bool CImGui_ImplSDL3_InitForD3D(SDL_Window *window)
{
    return ImGui_ImplSDL3_InitForD3D(window);
}
CIMGUI_API bool CImGui_ImplSDL3_InitForMetal(SDL_Window *window)
{
    return ImGui_ImplSDL3_InitForMetal(window);
}
CIMGUI_API bool CImGui_ImplSDL3_InitForSDLRenderer(SDL_Window *window, SDL_Renderer *renderer)
{
    return ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
}
CIMGUI_API bool CImGui_ImplSDL3_InitForOther(SDL_Window *window)
{
    return ImGui_ImplSDL3_InitForOther(window);
}
CIMGUI_API void CImGui_ImplSDL3_Shutdown()
{
    ImGui_ImplSDL3_Shutdown();
}
CIMGUI_API void CImGui_ImplSDL3_NewFrame()
{
    ImGui_ImplSDL3_NewFrame();
}
CIMGUI_API bool CImGui_ImplSDL3_ProcessEvent(const SDL_Event *event)
{
    return ImGui_ImplSDL3_ProcessEvent(event);
}
CIMGUI_API void CImGui_ImplSDL3_SetGamepadMode(ImGui_ImplSDL3_GamepadMode mode, struct SDL_Gamepad **manual_gamepads_array, int manual_gamepads_count)
{
    ImGui_ImplSDL3_SetGamepadMode(mode, manual_gamepads_array, manual_gamepads_count);
}
