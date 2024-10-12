#ifdef IMGUI_ENABLE_FREETYPE
#ifndef CIMGUI_FREETYPE
#error "IMGUI_FREETYPE should be defined for Freetype linking"
#endif
#else
#ifdef CIMGUI_FREETYPE
#error "IMGUI_FREETYPE should not be defined without freetype generated cimgui"
#endif
#endif
#include "../imgui/imgui.h"
#ifdef IMGUI_ENABLE_FREETYPE
#include "./imgui/misc/freetype/imgui_freetype.h"
#endif
#include "../imgui/imgui_internal.h"
#include "cimgui_impl.h"

CIMGUI_API void igSetCurrentContext(ImGuiContext *ctx)
{
    return ImGui::SetCurrentContext(ctx);
}
CIMGUI_API ImGuiContext *igGetCurrentContext()
{
    return ImGui::GetCurrentContext();
}