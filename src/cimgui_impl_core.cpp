#include "cimgui_impl_core.h"

CIMGUI_API void igSetCurrentContext(ImGuiContext *ctx)
{
    return ImGui::SetCurrentContext(ctx);
}
CIMGUI_API ImGuiContext *igGetCurrentContext()
{
    return ImGui::GetCurrentContext();
}
