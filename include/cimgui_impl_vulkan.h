#ifndef CIMGUI_IMPL_VULKAN_H
#define CIMGUI_IMPL_VULKAN_H

#include "cimgui_config.h"
#ifdef CIMGUI_USE_VULKAN
#include "backends/imgui_impl_vulkan.h"
CIMGUI_API bool CImGui_ImplVulkan_Init(ImGui_ImplVulkan_InitInfo *info);
CIMGUI_API void CImGui_ImplVulkan_Shutdown();
CIMGUI_API void CImGui_ImplVulkan_NewFrame();
CIMGUI_API void CImGui_ImplVulkan_RenderDrawData(ImDrawData *draw_data, VkCommandBuffer command_buffer, VkPipeline pipeline = VK_NULL_HANDLE);
CIMGUI_API void CImGui_ImplVulkan_UpdateTexture(ImTextureData* tex);
CIMGUI_API void CImGui_ImplVulkan_SetMinImageCount(uint32_t min_image_count);
CIMGUI_API VkDescriptorSet CImGui_ImplVulkan_AddTexture(VkSampler sampler, VkImageView image_view, VkImageLayout image_layout);
CIMGUI_API void CImGui_ImplVulkan_RemoveTexture(VkDescriptorSet descriptor_set);
CIMGUI_API void CImGui_ImplVulkanH_CreateOrResizeWindow(VkInstance instance, VkPhysicalDevice physical_device, VkDevice device, ImGui_ImplVulkanH_Window *wd, uint32_t queue_family, const VkAllocationCallbacks *allocator, int w, int h, uint32_t min_image_count);
CIMGUI_API void CImGui_ImplVulkanH_DestroyWindow(VkInstance instance, VkDevice device, ImGui_ImplVulkanH_Window *wd, const VkAllocationCallbacks *allocator);
CIMGUI_API VkSurfaceFormatKHR CImGui_ImplVulkanH_SelectSurfaceFormat(VkPhysicalDevice physical_device, VkSurfaceKHR surface, const VkFormat *request_formats, int request_formats_count, VkColorSpaceKHR request_color_space);
CIMGUI_API VkPresentModeKHR CImGui_ImplVulkanH_SelectPresentMode(VkPhysicalDevice physical_device, VkSurfaceKHR surface, const VkPresentModeKHR *request_modes, int request_modes_count);
CIMGUI_API int CImGui_ImplVulkanH_GetMinImageCountFromPresentMode(VkPresentModeKHR present_mode);
#endif

#endif // CIMGUI_IMPL_VULKAN_H
