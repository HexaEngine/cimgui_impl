#include "imgui/imgui.h"
#ifdef CIMGUI_FREETYPE
#include "./imgui/misc/freetype/imgui_freetype.h"
#endif
#include "imgui/imgui_internal.h"
#include "cimgui_impl.h"

CIMGUI_API void igSetCurrentContext(ImGuiContext *ctx)
{
    return ImGui::SetCurrentContext(ctx);
}
CIMGUI_API ImGuiContext *igGetCurrentContext()
{
    return ImGui::GetCurrentContext();
}

#define IMGUI_IMPL_METAL_CPP
#define IMGUI_IMPL_METAL_CPP_EXTENSIONS

// Win32 Backend Implementations
#if CIMGUI_USE_WIN32
CIMGUI_API bool CImGui_ImplWin32_Init(void *hwnd)
{
    return ImGui_ImplWin32_Init(hwnd);
}

CIMGUI_API bool CImGui_ImplWin32_InitForOpenGL(void *hwnd)
{
    return ImGui_ImplWin32_Init(hwnd);
}

CIMGUI_API void CImGui_ImplWin32_Shutdown()
{
    ImGui_ImplWin32_Shutdown();
}

CIMGUI_API void CImGui_ImplWin32_NewFrame()
{
    ImGui_ImplWin32_NewFrame();
}

CIMGUI_API void CImGui_ImplWin32_EnableDpiAwareness()
{
    ImGui_ImplWin32_EnableDpiAwareness();
}

CIMGUI_API float CImGui_ImplWin32_GetDpiScaleForHwnd(void *hwnd)
{
    return ImGui_ImplWin32_GetDpiScaleForHwnd(hwnd);
}

CIMGUI_API float CImGui_ImplWin32_GetDpiScaleForMonitor(void *monitor)
{
    return ImGui_ImplWin32_GetDpiScaleForMonitor(monitor);
}

CIMGUI_API void CImGui_ImplWin32_EnableAlphaCompositing(void *hwnd)
{
    ImGui_ImplWin32_EnableAlphaCompositing(hwnd);
}
#endif

// GLFW Backend Implementations
#if CIMGUI_USE_GLFW
CIMGUI_API bool CImGui_ImplGlfw_InitForOpenGL(GLFWwindow *window, bool install_callbacks)
{
    return ImGui_ImplGlfw_InitForOpenGL(window, install_callbacks);
}

CIMGUI_API bool CImGui_ImplGlfw_InitForVulkan(GLFWwindow *window, bool install_callbacks)
{
    return ImGui_ImplGlfw_InitForVulkan(window, install_callbacks);
}

CIMGUI_API bool CImGui_ImplGlfw_InitForOther(GLFWwindow *window, bool install_callbacks)
{
    return ImGui_ImplGlfw_InitForOther(window, install_callbacks);
}

CIMGUI_API void CImGui_ImplGlfw_Shutdown()
{
    ImGui_ImplGlfw_Shutdown();
}

CIMGUI_API void CImGui_ImplGlfw_NewFrame()
{
    ImGui_ImplGlfw_NewFrame();
}

CIMGUI_API void CImGui_ImplGlfw_InstallCallbacks(GLFWwindow *window)
{
    ImGui_ImplGlfw_InstallCallbacks(window);
}

CIMGUI_API void CImGui_ImplGlfw_RestoreCallbacks(GLFWwindow *window)
{
    ImGui_ImplGlfw_RestoreCallbacks(window);
}

CIMGUI_API void CImGui_ImplGlfw_SetCallbacksChainForAllWindows(bool chain_for_all_windows)
{
    ImGui_ImplGlfw_SetCallbacksChainForAllWindows(chain_for_all_windows);
}
CIMGUI_API void CImGui_ImplGlfw_WindowFocusCallback(GLFWwindow *window, int focused)
{
    ImGui_ImplGlfw_WindowFocusCallback(window, focused);
}

CIMGUI_API void CImGui_ImplGlfw_CursorEnterCallback(GLFWwindow *window, int entered)
{
    ImGui_ImplGlfw_CursorEnterCallback(window, entered);
}

CIMGUI_API void CImGui_ImplGlfw_CursorPosCallback(GLFWwindow *window, double x, double y)
{
    ImGui_ImplGlfw_CursorPosCallback(window, x, y);
}

CIMGUI_API void CImGui_ImplGlfw_MouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
    ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
}

CIMGUI_API void CImGui_ImplGlfw_ScrollCallback(GLFWwindow *window, double xoffset, double yoffset)
{
    ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
}

CIMGUI_API void CImGui_ImplGlfw_KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
}

CIMGUI_API void CImGui_ImplGlfw_CharCallback(GLFWwindow *window, unsigned int c)
{
    ImGui_ImplGlfw_CharCallback(window, c);
}

CIMGUI_API void CImGui_ImplGlfw_MonitorCallback(GLFWmonitor *monitor, int event)
{
    ImGui_ImplGlfw_MonitorCallback(monitor, event);
}

CIMGUI_API void CImGui_ImplGlfw_Sleep(int milliseconds)
{
    ImGui_ImplGlfw_Sleep(milliseconds);
}
#endif

// SDL2 Backend Implementations
#if CIMGUI_USE_SDL2
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
#endif

// SDL2 Renderer Backend Implementations
#if CIMGUI_USE_SDL2Renderer
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

CIMGUI_API bool CImGui_ImplSDLRenderer2_CreateFontsTexture()
{
    return ImGui_ImplSDLRenderer2_CreateFontsTexture();
}

CIMGUI_API void CImGui_ImplSDLRenderer2_DestroyFontsTexture()
{
    ImGui_ImplSDLRenderer2_DestroyFontsTexture();
}

CIMGUI_API bool CImGui_ImplSDLRenderer2_CreateDeviceObjects()
{
    return ImGui_ImplSDLRenderer2_CreateDeviceObjects();
}

CIMGUI_API void CImGui_ImplSDLRenderer2_DestroyDeviceObjects()
{
    ImGui_ImplSDLRenderer2_DestroyDeviceObjects();
}
#endif

// OpenGL 3 Backend Implementations
#if CIMGUI_USE_OPENGL3
CIMGUI_API bool CImGui_ImplOpenGL3_Init(const char *glsl_version)
{
    return ImGui_ImplOpenGL3_Init(glsl_version);
}

CIMGUI_API void CImGui_ImplOpenGL3_Shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
}

CIMGUI_API void CImGui_ImplOpenGL3_NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
}

CIMGUI_API void CImGui_ImplOpenGL3_RenderDrawData(ImDrawData *draw_data)
{
    ImGui_ImplOpenGL3_RenderDrawData(draw_data);
}
CIMGUI_API bool CImGui_ImplOpenGL3_CreateFontsTexture()
{
    return ImGui_ImplOpenGL3_CreateFontsTexture();
}

CIMGUI_API void CImGui_ImplOpenGL3_DestroyFontsTexture()
{
    ImGui_ImplOpenGL3_DestroyFontsTexture();
}

CIMGUI_API bool CImGui_ImplOpenGL3_CreateDeviceObjects()
{
    return ImGui_ImplOpenGL3_CreateDeviceObjects();
}

CIMGUI_API void CImGui_ImplOpenGL3_DestroyDeviceObjects()
{
    ImGui_ImplOpenGL3_DestroyDeviceObjects();
}
#endif

// OpenGL 2 Backend Implementations
#if CIMGUI_USE_OPENGL2
CIMGUI_API bool CImGui_ImplOpenGL2_Init()
{
    return ImGui_ImplOpenGL2_Init();
}

CIMGUI_API void CImGui_ImplOpenGL2_Shutdown()
{
    ImGui_ImplOpenGL2_Shutdown();
}

CIMGUI_API void CImGui_ImplOpenGL2_NewFrame()
{
    ImGui_ImplOpenGL2_NewFrame();
}

CIMGUI_API void CImGui_ImplOpenGL2_RenderDrawData(ImDrawData *draw_data)
{
    ImGui_ImplOpenGL2_RenderDrawData(draw_data);
}

CIMGUI_API bool CImGui_ImplOpenGL2_CreateFontsTexture()
{
    return ImGui_ImplOpenGL2_CreateFontsTexture();
}

CIMGUI_API void CImGui_ImplOpenGL2_DestroyFontsTexture()
{
    ImGui_ImplOpenGL2_DestroyFontsTexture();
}

CIMGUI_API bool CImGui_ImplOpenGL2_CreateDeviceObjects()
{
    return ImGui_ImplOpenGL2_CreateDeviceObjects();
}

CIMGUI_API void CImGui_ImplOpenGL2_DestroyDeviceObjects()
{
    ImGui_ImplOpenGL2_DestroyDeviceObjects();
}
#endif

// Direct3D 11 Backend Implementations
#if CIMGUI_USE_D3D11
CIMGUI_API bool CImGui_ImplDX11_Init(ID3D11Device *device, ID3D11DeviceContext *device_context)
{
    return ImGui_ImplDX11_Init(device, device_context);
}

CIMGUI_API void CImGui_ImplDX11_Shutdown()
{
    ImGui_ImplDX11_Shutdown();
}

CIMGUI_API void CImGui_ImplDX11_NewFrame()
{
    ImGui_ImplDX11_NewFrame();
}

CIMGUI_API void CImGui_ImplDX11_RenderDrawData(ImDrawData *draw_data)
{
    ImGui_ImplDX11_RenderDrawData(draw_data);
}

CIMGUI_API void CImGui_ImplDX11_InvalidateDeviceObjects()
{
    ImGui_ImplDX11_InvalidateDeviceObjects();
}

CIMGUI_API bool CImGui_ImplDX11_CreateDeviceObjects()
{
    return ImGui_ImplDX11_CreateDeviceObjects();
}
#endif

// Direct3D 12 Backend Implementations
#if CIMGUI_USE_D3D12
CIMGUI_API bool CImGui_ImplDX12_Init(ID3D12Device *device, int num_frames_in_flight, DXGI_FORMAT rtv_format, ID3D12DescriptorHeap *cbv_srv_heap, D3D12_CPU_DESCRIPTOR_HANDLE font_srv_cpu_desc_handle, D3D12_GPU_DESCRIPTOR_HANDLE font_srv_gpu_desc_handle)
{
    return ImGui_ImplDX12_Init(device, num_frames_in_flight, rtv_format, cbv_srv_heap, font_srv_cpu_desc_handle, font_srv_gpu_desc_handle);
}

CIMGUI_API void CImGui_ImplDX12_Shutdown()
{
    ImGui_ImplDX12_Shutdown();
}

CIMGUI_API void CImGui_ImplDX12_NewFrame()
{
    ImGui_ImplDX12_NewFrame();
}

CIMGUI_API void CImGui_ImplDX12_RenderDrawData(ImDrawData *draw_data, ID3D12GraphicsCommandList *graphics_command_list)
{
    ImGui_ImplDX12_RenderDrawData(draw_data, graphics_command_list);
}

CIMGUI_API void CImGui_ImplDX12_InvalidateDeviceObjects()
{
    ImGui_ImplDX12_InvalidateDeviceObjects();
}

CIMGUI_API bool CImGui_ImplDX12_CreateDeviceObjects()
{
    return ImGui_ImplDX12_CreateDeviceObjects();
}
#endif

// Vulkan Backend Implementations
#if CIMGUI_USE_VULKAN
CIMGUI_API bool CImGui_ImplVulkan_Init(ImGui_ImplVulkan_InitInfo *info)
{
    return ImGui_ImplVulkan_Init(info);
}

CIMGUI_API void CImGui_ImplVulkan_Shutdown()
{
    ImGui_ImplVulkan_Shutdown();
}

CIMGUI_API void CImGui_ImplVulkan_NewFrame()
{
    ImGui_ImplVulkan_NewFrame();
}

CIMGUI_API void CImGui_ImplVulkan_RenderDrawData(ImDrawData *draw_data, VkCommandBuffer command_buffer, VkPipeline pipeline)
{
    ImGui_ImplVulkan_RenderDrawData(draw_data, command_buffer, pipeline);
}

CIMGUI_API bool CImGui_ImplVulkan_CreateFontsTexture()
{
    return ImGui_ImplVulkan_CreateFontsTexture();
}

CIMGUI_API void CImGui_ImplVulkan_DestroyFontsTexture()
{
    ImGui_ImplVulkan_DestroyFontsTexture();
}

CIMGUI_API void CImGui_ImplVulkan_SetMinImageCount(uint32_t min_image_count)
{
    ImGui_ImplVulkan_SetMinImageCount(min_image_count);
}

CIMGUI_API VkDescriptorSet CImGui_ImplVulkan_AddTexture(VkSampler sampler, VkImageView image_view, VkImageLayout image_layout)
{
    return ImGui_ImplVulkan_AddTexture(sampler, image_view, image_layout);
}

CIMGUI_API void CImGui_ImplVulkan_RemoveTexture(VkDescriptorSet descriptor_set)
{
    ImGui_ImplVulkan_RemoveTexture(descriptor_set);
}

// Vulkan Custom Function Loader
/*
CIMGUI_API bool CImGui_ImplVulkan_LoadFunctions(PFN_vkVoidFunction loader_func, void *user_data)
{
    return ImGui_ImplVulkan_LoadFunctions(reinterpret_cast<PFN_vkVoidFunction>(loader_func), user_data);
}
*/

// Vulkan Helper Functions

CIMGUI_API void CImGui_ImplVulkanH_CreateOrResizeWindow(VkInstance instance, VkPhysicalDevice physical_device, VkDevice device, ImGui_ImplVulkanH_Window *wd, uint32_t queue_family, const VkAllocationCallbacks *allocator, int w, int h, uint32_t min_image_count)
{
    ImGui_ImplVulkanH_CreateOrResizeWindow(instance, physical_device, device, wd, queue_family, allocator, w, h, min_image_count);
}

CIMGUI_API void CImGui_ImplVulkanH_DestroyWindow(VkInstance instance, VkDevice device, ImGui_ImplVulkanH_Window *wd, const VkAllocationCallbacks *allocator)
{
    ImGui_ImplVulkanH_DestroyWindow(instance, device, wd, allocator);
}

CIMGUI_API VkSurfaceFormatKHR CImGui_ImplVulkanH_SelectSurfaceFormat(VkPhysicalDevice physical_device, VkSurfaceKHR surface, const VkFormat *request_formats, int request_formats_count, VkColorSpaceKHR request_color_space)
{
    return ImGui_ImplVulkanH_SelectSurfaceFormat(physical_device, surface, request_formats, request_formats_count, request_color_space);
}

CIMGUI_API VkPresentModeKHR CImGui_ImplVulkanH_SelectPresentMode(VkPhysicalDevice physical_device, VkSurfaceKHR surface, const VkPresentModeKHR *request_modes, int request_modes_count)
{
    return ImGui_ImplVulkanH_SelectPresentMode(physical_device, surface, request_modes, request_modes_count);
}

CIMGUI_API int CImGui_ImplVulkanH_GetMinImageCountFromPresentMode(VkPresentModeKHR present_mode)
{
    return ImGui_ImplVulkanH_GetMinImageCountFromPresentMode(present_mode);
}
#endif

// OSX Backend Implementations
#if CIMGUI_USE_OSX
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

// Metal Backend Implementations
#if CIMGUI_USE_METAL
CIMGUI_API bool CImGui_ImplMetal_Init(MTLDevice *device)
{
    return ImGui_ImplMetal_Init(device);
}

CIMGUI_API void CImGui_ImplMetal_Shutdown()
{
    ImGui_ImplMetal_Shutdown();
}

CIMGUI_API void CImGui_ImplMetal_NewFrame(MTLRenderPassDescriptor *renderPassDescriptor)
{
    ImGui_ImplMetal_NewFrame(renderPassDescriptor);
}

CIMGUI_API void CImGui_ImplMetal_RenderDrawData(ImDrawData *draw_data, MTLCommandBuffer *commandBuffer, MTLRenderCommandEncoder *commandEncoder)
{
    ImGui_ImplMetal_RenderDrawData(draw_data, commandBuffer, commandEncoder);
}

CIMGUI_API bool CImGui_ImplMetal_CreateFontsTexture(MTLDevice *device)
{
    return ImGui_ImplMetal_CreateFontsTexture(device);
}

CIMGUI_API void CImGui_ImplMetal_DestroyFontsTexture()
{
    ImGui_ImplMetal_DestroyFontsTexture();
}

CIMGUI_API bool CImGui_ImplMetal_CreateDeviceObjects(MTLDevice *device)
{
    return ImGui_ImplMetal_CreateDeviceObjects(device);
}

CIMGUI_API void CImGui_ImplMetal_DestroyDeviceObjects()
{
    ImGui_ImplMetal_DestroyDeviceObjects();
}
#endif

// Android Backend Implementations
#if CIMGUI_USE_ANDROID
CIMGUI_API bool CImGui_ImplAndroid_Init(ANativeWindow *window)
{
    return ImGui_ImplAndroid_Init(window);
}

CIMGUI_API int32_t CImGui_ImplAndroid_HandleInputEvent(const AInputEvent *input_event)
{
    return ImGui_ImplAndroid_HandleInputEvent(input_event);
}

CIMGUI_API void CImGui_ImplAndroid_Shutdown()
{
    ImGui_ImplAndroid_Shutdown();
}

CIMGUI_API void CImGui_ImplAndroid_NewFrame()
{
    ImGui_ImplAndroid_NewFrame();
}
#endif