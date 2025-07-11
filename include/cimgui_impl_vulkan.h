#ifndef CIMGUI_IMPL_VULKAN_H
#define CIMGUI_IMPL_VULKAN_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_VULKAN
#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS
// Vulkan and backend types (no Im* typedefs)
typedef void* VkInstance;
typedef void* VkPhysicalDevice;
typedef void* VkDevice;
typedef void* VkQueue;
typedef void* VkDescriptorPool;
typedef void* VkRenderPass;
typedef unsigned int uint32_t;
typedef void* VkSampleCountFlagBits;
typedef void* VkPipelineCache;
typedef void* VkPipelineRenderingCreateInfoKHR;
typedef int bool;
typedef void* VkAllocationCallbacks;
typedef void* VkDeviceSize;
typedef void* VkResult;
typedef void* PFN_vkVoidFunction;
typedef void* VkCommandBuffer;
typedef void* VkPipeline;
typedef void* VkSampler;
typedef void* VkImageView;
typedef void* VkImageLayout;
typedef void* VkDescriptorSet;
typedef void* VkSurfaceKHR;
typedef void* VkFormat;
typedef void* VkColorSpaceKHR;
typedef void* VkSurfaceFormatKHR;
typedef void* VkPresentModeKHR;
typedef void* VkPipelineLayout;
typedef void* VkCommandPool;
typedef void* VkFence;
typedef void* VkImage;
typedef void* VkFramebuffer;
typedef void* VkSemaphore;
typedef void* VkSwapchainKHR;
typedef void* VkClearValue;
// Full struct layout for ImGui_ImplVulkan_InitInfo
struct ImGui_ImplVulkan_InitInfo {
    uint32_t ApiVersion;
    VkInstance Instance;
    VkPhysicalDevice PhysicalDevice;
    VkDevice Device;
    uint32_t QueueFamily;
    VkQueue Queue;
    VkDescriptorPool DescriptorPool;
    VkRenderPass RenderPass;
    uint32_t MinImageCount;
    uint32_t ImageCount;
    VkSampleCountFlagBits MSAASamples;
    VkPipelineCache PipelineCache;
    uint32_t Subpass;
    uint32_t DescriptorPoolSize;
    bool UseDynamicRendering;
#ifdef IMGUI_IMPL_VULKAN_HAS_DYNAMIC_RENDERING
    VkPipelineRenderingCreateInfoKHR PipelineRenderingCreateInfo;
#endif
    const VkAllocationCallbacks* Allocator;
    void (*CheckVkResultFn)(VkResult err);
    VkDeviceSize MinAllocationSize;
};
#else
#include "backends/imgui_impl_vulkan.h"
#endif
// [Configuration] in order to use a custom Vulkan function loader:
// (1) You'll need to disable default Vulkan function prototypes.
//     We provide a '#define IMGUI_IMPL_VULKAN_NO_PROTOTYPES' convenience configuration flag.
//     In order to make sure this is visible from the imgui_impl_vulkan.cpp compilation unit:
//     - Add '#define IMGUI_IMPL_VULKAN_NO_PROTOTYPES' in your imconfig.h file
//     - Or as a compilation flag in your build system
//     - Or uncomment here (not recommended because you'd be modifying imgui sources!)
//     - Do not simply add it in a .cpp file!
// (2) Call ImGui_ImplVulkan_LoadFunctions() before ImGui_ImplVulkan_Init() with your custom function.
// If you have no idea what this is, leave it alone!
// Convenience support for Volk
// (you can also technically use IMGUI_IMPL_VULKAN_NO_PROTOTYPES + wrap Volk via ImGui_ImplVulkan_LoadFunctions().)
// If you have no idea what this is, leave it alone!
CIMGUI_API bool CImGui_ImplVulkan_Init(ImGui_ImplVulkan_InitInfo *info);
CIMGUI_API void CImGui_ImplVulkan_Shutdown();
CIMGUI_API void CImGui_ImplVulkan_NewFrame();
CIMGUI_API void CImGui_ImplVulkan_RenderDrawData(ImDrawData *draw_data, VkCommandBuffer command_buffer, VkPipeline pipeline);
CIMGUI_API void CImGui_ImplVulkan_UpdateTexture(ImTextureData* tex);
CIMGUI_API void CImGui_ImplVulkan_SetMinImageCount(uint32_t min_image_count);
// [!] Renderer: User texture binding. Use 'VkDescriptorSet' as texture identifier. Call ImGui_ImplVulkan_AddTexture() to register one. Read the FAQ about ImTextureID/ImTextureRef + https://github.com/ocornut/imgui/pull/914 for discussions.
CIMGUI_API VkDescriptorSet CImGui_ImplVulkan_AddTexture(VkSampler sampler, VkImageView image_view, VkImageLayout image_layout);
CIMGUI_API void CImGui_ImplVulkan_RemoveTexture(VkDescriptorSet descriptor_set);
CIMGUI_API void CImGui_ImplVulkanH_CreateOrResizeWindow(VkInstance instance, VkPhysicalDevice physical_device, VkDevice device, ImGui_ImplVulkanH_Window *wd, uint32_t queue_family, const VkAllocationCallbacks *allocator, int w, int h, uint32_t min_image_count);
CIMGUI_API void CImGui_ImplVulkanH_DestroyWindow(VkInstance instance, VkDevice device, ImGui_ImplVulkanH_Window *wd, const VkAllocationCallbacks *allocator);
CIMGUI_API VkSurfaceFormatKHR CImGui_ImplVulkanH_SelectSurfaceFormat(VkPhysicalDevice physical_device, VkSurfaceKHR surface, const VkFormat *request_formats, int request_formats_count, VkColorSpaceKHR request_color_space);
CIMGUI_API VkPresentModeKHR CImGui_ImplVulkanH_SelectPresentMode(VkPhysicalDevice physical_device, VkSurfaceKHR surface, const VkPresentModeKHR *request_modes, int request_modes_count);
CIMGUI_API int CImGui_ImplVulkanH_GetMinImageCountFromPresentMode(VkPresentModeKHR present_mode);
#endif

#endif // CIMGUI_IMPL_VULKAN_H
