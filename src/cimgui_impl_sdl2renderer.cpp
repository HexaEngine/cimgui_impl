#include "cimgui_impl_sdl2renderer.h"

CIMGUI_API bool CImGui_ImplSDLRenderer2_Init(SDL_Renderer *renderer)
{
    return ImGui_ImplSDLRenderer2_Init(renderer);
}
CIMGUI_API void CImGui_ImplSDLRenderer2_Shutdown()
{
    ImGui_ImplSDLRenderer2_Shutdown();
}
CIMGUI_API void CImGui_ImplSDLRenderer2_NewFrame()
{
    ImGui_ImplSDLRenderer2_NewFrame();
}
CIMGUI_API void CImGui_ImplSDLRenderer2_RenderDrawData(ImDrawData *draw_data, SDL_Renderer *renderer)
{
    ImGui_ImplSDLRenderer2_RenderDrawData(draw_data, renderer);
}
CIMGUI_API void CImGui_ImplSDLRenderer2_UpdateTexture(ImTextureData* tex)
{
    ImGui_ImplSDLRenderer2_UpdateTexture(tex);
}
CIMGUI_API void CImGui_ImplSDLRenderer2_CreateDeviceObjects()
{
    ImGui_ImplSDLRenderer2_CreateDeviceObjects();
}
CIMGUI_API void CImGui_ImplSDLRenderer2_DestroyDeviceObjects()
{
    ImGui_ImplSDLRenderer2_DestroyDeviceObjects();
}
