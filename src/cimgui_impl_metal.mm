#include "imgui/backends/imgui_impl_metal.h"
#import <AppKit/AppKit.h>
#import <Metal/Metal.h>
#import <QuartzCore/QuartzCore.h>

#ifdef __OBJC__

// Follow "Getting Started" link and check examples/ folder to learn about using backends!
CIMGUI_API bool CImGui_ImplMetal_Init(void *device)
{
    return ImGui_ImplMetal_Init(reinterpret_cast<id<MTLDevice>>(device));
}

CIMGUI_API void CImGui_ImplMetal_Shutdown()
{
    ImGui_ImplMetal_Shutdown();
}

CIMGUI_API void CImGui_ImplMetal_NewFrame(void *renderPassDescriptor)
{
    ImGui_ImplMetal_NewFrame(reinterpret_cast<MTLRenderPassDescriptor*>(renderPassDescriptor));
}

CIMGUI_API void CImGui_ImplMetal_RenderDrawData(ImDrawData *draw_data, void *commandBuffer, void *commandEncoder)
{
    ImGui_ImplMetal_RenderDrawData(draw_data, reinterpret_cast<id<MTLCommandBuffer>>(commandBuffer), reinterpret_cast<id<MTLRenderCommandEncoder>>(commandEncoder));
}

// Called by Init/NewFrame/Shutdown
CIMGUI_API bool CImGui_ImplMetal_CreateFontsTexture(void *device)
{
    return ImGui_ImplMetal_CreateFontsTexture(reinterpret_cast<id<MTLDevice>>(device));
}

CIMGUI_API void CImGui_ImplMetal_DestroyFontsTexture()
{
    ImGui_ImplMetal_DestroyFontsTexture();
}

CIMGUI_API bool CImGui_ImplMetal_CreateDeviceObjects(void *device)
{
    return ImGui_ImplMetal_CreateDeviceObjects(reinterpret_cast<id<MTLDevice>>(device));
}

CIMGUI_API void CImGui_ImplMetal_DestroyDeviceObjects()
{
    ImGui_ImplMetal_DestroyDeviceObjects();
}

#endif

//-----------------------------------------------------------------------------
// C++ API
//-----------------------------------------------------------------------------

// Enable Metal C++ binding support with '#define IMGUI_IMPL_METAL_CPP' in your imconfig.h file
// More info about using Metal from C++: https://developer.apple.com/metal/cpp/

#ifdef IMGUI_IMPL_METAL_CPP

#ifndef __OBJC__

// Follow "Getting Started" link and check examples/ folder to learn about using backends!
CIMGUI_API bool CImGui_ImplMetal_Init(MTLDevice *device)
{
    return ImGui_ImplMetal_Init(reinterpret_cast<MTL::Device *>(device));
}

CIMGUI_API void CImGui_ImplMetal_Shutdown()
{
    ImGui_ImplMetal_Shutdown();
}

CIMGUI_API void CImGui_ImplMetal_NewFrame(MTLRenderPassDescriptor *renderPassDescriptor)
{
    ImGui_ImplMetal_NewFrame(reinterpret_cast<MTL::RenderPassDescriptor *>(renderPassDescriptor));
}

CIMGUI_API void CImGui_ImplMetal_RenderDrawData(ImDrawData *draw_data, MTLCommandBuffer *commandBuffer, MTLRenderCommandEncoder *commandEncoder)
{
    ImGui_ImplMetal_RenderDrawData(draw_data, reinterpret_cast<MTL::CommandBuffer *>(commandBuffer), reinterpret_cast<MTL::RenderCommandEncoder *>(commandEncoder));
}

// Called by Init/NewFrame/Shutdown
CIMGUI_API bool CImGui_ImplMetal_CreateFontsTexture(MTLDevice *device)
{
    return ImGui_ImplMetal_CreateFontsTexture(reinterpret_cast<MTL::Device *>(device));
}

CIMGUI_API void CImGui_ImplMetal_DestroyFontsTexture()
{
    ImGui_ImplMetal_DestroyFontsTexture();
}

CIMGUI_API bool CImGui_ImplMetal_CreateDeviceObjects(MTLDevice *device)
{
    return ImGui_ImplMetal_CreateDeviceObjects(reinterpret_cast<MTL::Device *>(device));
}

CIMGUI_API void CImGui_ImplMetal_DestroyDeviceObjects()
{
    ImGui_ImplMetal_DestroyDeviceObjects();
}

#endif

#endif