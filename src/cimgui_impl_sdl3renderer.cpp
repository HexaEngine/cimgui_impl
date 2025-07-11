#include "cimgui_impl_sdl3renderer.h"
CIMGUI_API bool CImGui_ImplSDLRenderer3_Init(SDL_Renderer *renderer)
{
    return ImGui_ImplSDLRenderer3_Init(renderer);
}
CIMGUI_API void CImGui_ImplSDLRenderer3_Shutdown()
{
    ImGui_ImplSDLRenderer3_Shutdown();
}
CIMGUI_API void CImGui_ImplSDLRenderer3_NewFrame()
{
    ImGui_ImplSDLRenderer3_NewFrame();
}
CIMGUI_API void CImGui_ImplSDLRenderer3_RenderDrawData(ImDrawData *draw_data, SDL_Renderer *renderer)
{
    ImGui_ImplSDLRenderer3_RenderDrawData(draw_data, renderer);
}
CIMGUI_API bool CImGui_ImplSDLRenderer3_CreateFontsTexture()
{
    return ImGui_ImplSDLRenderer3_CreateFontsTexture();
}
CIMGUI_API void CImGui_ImplSDLRenderer3_DestroyFontsTexture()
{
    ImGui_ImplSDLRenderer3_DestroyFontsTexture();
}
CIMGUI_API bool CImGui_ImplSDLRenderer3_CreateDeviceObjects()
{
    return ImGui_ImplSDLRenderer3_CreateDeviceObjects();
}
CIMGUI_API void CImGui_ImplSDLRenderer3_DestroyDeviceObjects()
{
    ImGui_ImplSDLRenderer3_DestroyDeviceObjects();
}
