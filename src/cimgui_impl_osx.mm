#include "cimgui_impl_osx.h"

#ifdef __OBJC__

// Follow "Getting Started" link and check examples/ folder to learn about using backends!

CIMGUI_API bool CImGui_ImplOSX_Init(void *view)
{
    return ImGui_ImplOSX_Init(reinterpret_cast<NSView *>(view));
}

CIMGUI_API void CImGui_ImplOSX_Shutdown()
{
    ImGui_ImplOSX_Shutdown();
}

CIMGUI_API void CImGui_ImplOSX_NewFrame(void *view)
{
    ImGui_ImplOSX_NewFrame(reinterpret_cast<NSView *>(view));
}

#endif

//-----------------------------------------------------------------------------
// C++ API
//-----------------------------------------------------------------------------

#ifdef IMGUI_IMPL_METAL_CPP_EXTENSIONS
// #include <AppKit/AppKit.hpp>
#ifndef __OBJC__

// Follow "Getting Started" link and check examples/ folder to learn about using backends!
CIMGUI_API bool CImGui_ImplOSX_Init(void *view)
{
    return ImGui_ImplOSX_Init(view);
}

CIMGUI_API void CImGui_ImplOSX_Shutdown()
{
    ImGui_ImplOSX_Shutdown();
}

CIMGUI_API void CImGui_ImplOSX_NewFrame(void *view)
{
    ImGui_ImplOSX_NewFrame(view);
}

#endif

#endif