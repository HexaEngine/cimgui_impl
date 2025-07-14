#include "cimgui_impl_vulkan.h"

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
CIMGUI_API void CImGui_ImplVulkan_SetMinImageCount(uint32_t min_image_count)
{
    ImGui_ImplVulkan_SetMinImageCount(min_image_count);
}

CIMGUI_API void CImGui_ImplVulkan_UpdateTexture(ImTextureData* tex)
{
    ImGui_ImplVulkan_UpdateTexture(tex);
}
CIMGUI_API VkDescriptorSet CImGui_ImplVulkan_AddTexture(VkSampler sampler, VkImageView image_view, VkImageLayout image_layout)
{
    return ImGui_ImplVulkan_AddTexture(sampler, image_view, image_layout);
}
CIMGUI_API void CImGui_ImplVulkan_RemoveTexture(VkDescriptorSet descriptor_set)
{
    ImGui_ImplVulkan_RemoveTexture(descriptor_set);
}

CIMGUI_API bool CImGui_ImplVulkan_LoadFunctions(uint32_t api_version, PFN_vkVoidFunction(*loader_func)(const char* function_name, void* user_data), void* user_data)
{
    return ImGui_ImplVulkan_LoadFunctions(api_version, loader_func, user_data);
}

// -----

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
CIMGUI_API VkPhysicalDevice CImGui_ImplVulkanH_SelectPhysicalDevice(VkInstance instance)
{
    return ImGui_ImplVulkanH_SelectPhysicalDevice(instance);
}
CIMGUI_API uint32_t CImGui_ImplVulkanH_SelectQueueFamilyIndex(VkPhysicalDevice physical_device)
{
    return ImGui_ImplVulkanH_SelectQueueFamilyIndex(physical_device);
}
CIMGUI_API int CImGui_ImplVulkanH_GetMinImageCountFromPresentMode(VkPresentModeKHR present_mode)
{
    return ImGui_ImplVulkanH_GetMinImageCountFromPresentMode(present_mode);
}
