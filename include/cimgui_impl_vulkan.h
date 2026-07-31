#ifndef CIMGUI_IMPL_VULKAN_H
#define CIMGUI_IMPL_VULKAN_H

#include "cimgui_config.h"
#if CIMGUI_USE_VULKAN
#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS
typedef struct VkAllocationCallbacks VkAllocationCallbacks;

typedef struct VkInstance_T* VkInstance;
typedef struct VkPhysicalDevice_T* VkPhysicalDevice;
typedef struct VkDevice_T* VkDevice;
typedef struct VkQueue_T* VkQueue;
typedef struct VkCommandBuffer_T* VkCommandBuffer;
typedef struct VkDescriptorPool { uint64_t Handle; } VkDescriptorPool;
typedef struct VkRenderPass { uint64_t Handle; } VkRenderPass;
typedef struct VkPipelineCache { uint64_t Handle; } VkPipelineCache;
typedef struct VkSemaphore { uint64_t Handle; } VkSemaphore;
typedef struct VkImage { uint64_t Handle; } VkImage;
typedef struct VkImageView { uint64_t Handle; } VkImageView;
typedef struct VkFramebuffer { uint64_t Handle; } VkFramebuffer;
typedef struct VkSwapchainKHR { uint64_t Handle; } VkSwapchainKHR;
typedef struct VkSurfaceKHR { uint64_t Handle; } VkSurfaceKHR;
typedef struct VkDescriptorSet { uint64_t Handle; } VkDescriptorSet;
typedef struct VkSampler { uint64_t Handle; } VkSampler;
typedef struct VkCommandPool { uint64_t Handle; } VkCommandPool;
typedef struct VkFence { uint64_t Handle; } VkFence;
typedef struct VkPipelineLayout { uint64_t Handle; } VkPipelineLayout;
typedef struct VkPipeline { uint64_t Handle; } VkPipeline;
typedef struct ImGuiViewport ImGuiViewport;
typedef struct ImGui_ImplVulkan_PipelineInfo ImGui_ImplVulkan_PipelineInfo;

#define VKAPI_CALL
#define VKAPI_PTR VKAPI_CALL

typedef void (VKAPI_PTR* PFN_vkVoidFunction)(void);

// Simplified Vulkan types
typedef int VkResult;
typedef unsigned int VkSampleCountFlagBits;
typedef unsigned long long VkDeviceSize;
typedef int VkStructureType;
typedef int VkDynamicState;

// Format and color space types
typedef unsigned int VkFormat;
typedef unsigned int VkColorSpaceKHR;
typedef int VkPresentModeKHR;
typedef int VkImageLayout;

typedef uint32_t VkFlags;

typedef enum VkImageUsageFlagBits {
	VK_IMAGE_USAGE_TRANSFER_SRC_BIT = 0x00000001,
	VK_IMAGE_USAGE_TRANSFER_DST_BIT = 0x00000002,
	VK_IMAGE_USAGE_SAMPLED_BIT = 0x00000004,
	VK_IMAGE_USAGE_STORAGE_BIT = 0x00000008,
	VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT = 0x00000010,
	VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT = 0x00000020,
	VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT = 0x00000040,
	VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT = 0x00000080,
	VK_IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR = 0x00000400,
	VK_IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR = 0x00000800,
	VK_IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR = 0x00001000,
	VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT = 0x00000200,
	VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR = 0x00000100,
	VK_IMAGE_USAGE_HOST_TRANSFER_BIT_EXT = 0x00400000,
	VK_IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR = 0x00002000,
	VK_IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR = 0x00004000,
	VK_IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR = 0x00008000,
	VK_IMAGE_USAGE_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT = 0x00080000,
	VK_IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI = 0x00040000,
	VK_IMAGE_USAGE_SAMPLE_WEIGHT_BIT_QCOM = 0x00100000,
	VK_IMAGE_USAGE_SAMPLE_BLOCK_MATCH_BIT_QCOM = 0x00200000,
	VK_IMAGE_USAGE_SHADING_RATE_IMAGE_BIT_NV = VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR,
	VK_IMAGE_USAGE_FLAG_BITS_MAX_ENUM = 0x7FFFFFFF
} VkImageUsageFlagBits;
typedef VkFlags VkImageUsageFlags;

typedef union VkClearColorValue {
    float       float32[4];
    int32_t     int32[4];
    uint32_t    uint32[4];
} VkClearColorValue;

typedef struct VkClearDepthStencilValue {
    float       depth;
    uint32_t    stencil;
} VkClearDepthStencilValue;

typedef union VkClearValue {
    VkClearColorValue           color;
    VkClearDepthStencilValue    depthStencil;
} VkClearValue;

typedef struct VkSurfaceFormatKHR {
	VkFormat format;
	VkColorSpaceKHR colorSpace;
} VkSurfaceFormatKHR;

typedef struct VkAttachmentDescription {
	VkFlags flags;
	VkFormat format;
	VkSampleCountFlagBits samples;
	int loadOp;
	int storeOp;
	int stencilLoadOp;
	int stencilStoreOp;
	VkImageLayout initialLayout;
	VkImageLayout finalLayout;
} VkAttachmentDescription;

typedef struct VkPipelineRenderingCreateInfo {
	VkStructureType    sType;
	const void* pNext;
	uint32_t           viewMask;
	uint32_t           colorAttachmentCount;
	const VkFormat* pColorAttachmentFormats;
	VkFormat           depthAttachmentFormat;
	VkFormat           stencilAttachmentFormat;
} VkPipelineRenderingCreateInfo;

typedef VkPipelineRenderingCreateInfo VkPipelineRenderingCreateInfoKHR;

typedef struct VkShaderModuleCreateInfo {
	VkStructureType sType;
	const void* pNext;
	VkFlags flags;
	size_t codeSize;
	const uint32_t* pCode;
} VkShaderModuleCreateInfo;

typedef struct ImVector_VkDynamicState { int Size; int Capacity; VkDynamicState* Data; } ImVector_VkDynamicState;

struct ImGui_ImplVulkan_PipelineInfo
{
	VkRenderPass RenderPass;
	uint32_t Subpass;
	VkSampleCountFlagBits MSAASamples;
	ImVector_VkDynamicState ExtraDynamicStates;
	VkPipelineRenderingCreateInfoKHR PipelineRenderingCreateInfo;
	VkImageUsageFlags SwapChainImageUsage;
};

// Backend uses a small number of descriptors per font atlas + as many as additional calls done to ImGui_ImplVulkan_AddTexture().
#define CIMGUI_IMPL_VULKAN_MINIMUM_IMAGE_SAMPLER_POOL_SIZE   (8)     // Minimum per atlas

// Initialization data, for ImGui_ImplVulkan_Init()
// [Please zero-clear before use!]
// - About descriptor pool:
//   - A VkDescriptorPool should be created with VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT,
//     and must contain a pool size large enough to hold a small number of VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER descriptors.
//   - As an convenience, by setting DescriptorPoolSize > 0 the backend will create one for you.
// - About dynamic rendering:
//   - When using dynamic rendering, set UseDynamicRendering=true and fill PipelineRenderingCreateInfo structure.
struct ImGui_ImplVulkan_InitInfo
{
	uint32_t                        ApiVersion;                 // Fill with API version of Instance, e.g. VK_API_VERSION_1_3 or your value of VkApplicationInfo::apiVersion. May be lower than header version (VK_HEADER_VERSION_COMPLETE)
	VkInstance                      Instance;
	VkPhysicalDevice                PhysicalDevice;
	VkDevice                        Device;
	uint32_t                        QueueFamily;
	VkQueue                         Queue;
	VkDescriptorPool                DescriptorPool;             // See requirements in note above; ignored if using DescriptorPoolSize > 0
	uint32_t                        DescriptorPoolSize;
	uint32_t                        MinImageCount;              // >= 2
	uint32_t                        ImageCount;                 // >= MinImageCount
	VkPipelineCache                 PipelineCache;
	ImGui_ImplVulkan_PipelineInfo   PipelineInfoMain;
	ImGui_ImplVulkan_PipelineInfo   PipelineInfoForViewports;

	// (Optional) Dynamic Rendering
	// Need to explicitly enable VK_KHR_dynamic_rendering extension to use this, even for Vulkan 1.3.
	bool                            UseDynamicRendering;
	// (Optional) Allocation, Debugging
	const VkAllocationCallbacks* Allocator;
	void                            (*CheckVkResultFn)(VkResult err);
	VkDeviceSize                    MinAllocationSize;          // Minimum allocation size. Set to 1024*1024 to satisfy zealous best practices validation layer and waste a little memory.
	VkShaderModuleCreateInfo        CustomShaderVertCreateInfo;
	VkShaderModuleCreateInfo        CustomShaderFragCreateInfo;
};
#else
#include "backends/imgui_impl_vulkan.h"
#endif

// Follow "Getting Started" link and check examples/ folder to learn about using backends!
CIMGUI_API bool             CImGui_ImplVulkan_Init(ImGui_ImplVulkan_InitInfo* info);
CIMGUI_API void             CImGui_ImplVulkan_Shutdown();
CIMGUI_API void             CImGui_ImplVulkan_NewFrame();
CIMGUI_API void             CImGui_ImplVulkan_RenderDrawData(ImDrawData* draw_data, VkCommandBuffer command_buffer, VkPipeline pipeline);
CIMGUI_API void             CImGui_ImplVulkan_SetMinImageCount(uint32_t min_image_count); // To override MinImageCount after initialization (e.g. if swap chain is recreated)
CIMGUI_API void             CImGui_ImplVulkan_CreateMainPipeline(const ImGui_ImplVulkan_PipelineInfo* info);

// (Advanced) Use e.g. if you need to precisely control the timing of texture updates (e.g. for staged rendering), by setting ImDrawData::Textures = NULL to handle this manually.
CIMGUI_API void             CImGui_ImplVulkan_UpdateTexture(ImTextureData* tex);

// Register a texture (VkDescriptorSet == ImTextureID)
// FIXME: This is experimental in the sense that we are unsure how to best design/tackle this problem
// Please post to https://github.com/ocornut/imgui/pull/914 if you have suggestions.
CIMGUI_API VkDescriptorSet  CImGui_ImplVulkan_AddTexture(VkImageView image_view, VkImageLayout image_layout);
CIMGUI_API void             CImGui_ImplVulkan_RemoveTexture(VkDescriptorSet descriptor_set);

// Optional: load Vulkan functions with a custom function loader
// This is only useful with IMGUI_IMPL_VULKAN_NO_PROTOTYPES / VK_NO_PROTOTYPES
CIMGUI_API bool             CImGui_ImplVulkan_LoadFunctions(uint32_t api_version, PFN_vkVoidFunction(*loader_func)(const char* function_name, void* user_data), void* user_data = nullptr);

#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS

// [BETA] Selected render state data shared with callbacks.
// This is temporarily stored in GetPlatformIO().Renderer_RenderState during the ImGui_ImplVulkan_RenderDrawData() call.
// (Please open an issue if you feel you need access to more data)
struct ImGui_ImplVulkan_RenderState
{
	VkCommandBuffer     CommandBuffer;
	VkPipeline          Pipeline;
	VkPipelineLayout    PipelineLayout;
};

#endif

//-------------------------------------------------------------------------
// Internal / Miscellaneous Vulkan Helpers
//-------------------------------------------------------------------------
// Used by example's main.cpp. Used by multi-viewport features. PROBABLY NOT used by your own engine/app.
//
// You probably do NOT need to use or care about those functions.
// Those functions only exist because:
//   1) they facilitate the readability and maintenance of the multiple main.cpp examples files.
//   2) the multi-viewport / platform window implementation needs them internally.
// Generally we avoid exposing any kind of superfluous high-level helpers in the backends,
// but it is too much code to duplicate everywhere so we exceptionally expose them.
//
// Your engine/app will likely _already_ have code to setup all that stuff (swap chain,
// render pass, frame buffers, etc.). You may read this code if you are curious, but
// it is recommended you use you own custom tailored code to do equivalent work.
//
// We don't provide a strong guarantee that we won't change those functions API.
//
// The ImGui_ImplVulkanH_XXX functions should NOT interact with any of the state used
// by the regular ImGui_ImplVulkan_XXX functions).
//-------------------------------------------------------------------------

#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS

struct ImGui_ImplVulkanH_Frame;
struct ImGui_ImplVulkanH_Window;

#endif

// Helpers
CIMGUI_API void                 CImGui_ImplVulkanH_CreateOrResizeWindow(VkInstance instance, VkPhysicalDevice physical_device, VkDevice device, ImGui_ImplVulkanH_Window* wd, uint32_t queue_family, const VkAllocationCallbacks* allocator, int w, int h, uint32_t min_image_count, VkImageUsageFlags image_usage);
CIMGUI_API void                 CImGui_ImplVulkanH_DestroyWindow(VkInstance instance, VkDevice device, ImGui_ImplVulkanH_Window* wd, const VkAllocationCallbacks* allocator);
CIMGUI_API VkSurfaceFormatKHR   CImGui_ImplVulkanH_SelectSurfaceFormat(VkPhysicalDevice physical_device, VkSurfaceKHR surface, const VkFormat* request_formats, int request_formats_count, VkColorSpaceKHR request_color_space);
CIMGUI_API VkPresentModeKHR     CImGui_ImplVulkanH_SelectPresentMode(VkPhysicalDevice physical_device, VkSurfaceKHR surface, const VkPresentModeKHR* request_modes, int request_modes_count);
CIMGUI_API VkPhysicalDevice     CImGui_ImplVulkanH_SelectPhysicalDevice(VkInstance instance);
CIMGUI_API uint32_t             CImGui_ImplVulkanH_SelectQueueFamilyIndex(VkPhysicalDevice physical_device);
CIMGUI_API int                  CImGui_ImplVulkanH_GetMinImageCountFromPresentMode(VkPresentModeKHR present_mode);
CIMGUI_API ImGui_ImplVulkanH_Window* CImGui_ImplVulkanH_GetWindowDataFromViewport(ImGuiViewport* viewport);

#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS

// Helper structure to hold the data needed by one rendering frame
// (Used by example's main.cpp. Used by multi-viewport features. Probably NOT used by your own engine/app.)
// [Please zero-clear before use!]
struct ImGui_ImplVulkanH_Frame
{
	VkCommandPool       CommandPool;
	VkCommandBuffer     CommandBuffer;
	VkFence             Fence;
	VkImage             Backbuffer;
	VkImageView         BackbufferView;
	VkFramebuffer       Framebuffer;
};

struct ImGui_ImplVulkanH_FrameSemaphores
{
	VkSemaphore         ImageAcquiredSemaphore;
	VkSemaphore         RenderCompleteSemaphore;
};

typedef struct ImVector_ImGui_ImplVulkanH_Frame { int Size; int Capacity; ImGui_ImplVulkanH_Frame* Data; } ImVector_ImGui_ImplVulkanH_Frame;
typedef struct ImVector_ImGui_ImplVulkanH_FrameSemaphores { int Size; int Capacity; ImGui_ImplVulkanH_FrameSemaphores* Data; } ImVector_ImGui_ImplVulkanH_FrameSemaphores;

// Helper structure to hold the data needed by one rendering context into one OS window
// (Used by example's main.cpp. Used by multi-viewport features. Probably NOT used by your own engine/app.)
struct ImGui_ImplVulkanH_Window
{
	bool                UseDynamicRendering;
	VkSurfaceKHR        Surface;
	VkSurfaceFormatKHR  SurfaceFormat;
	VkPresentModeKHR    PresentMode;
	VkAttachmentDescription AttachmentDesc;
	VkClearValue        ClearValue;
	int                 Width;
	int                 Height;
	VkSwapchainKHR      Swapchain;
	VkRenderPass        RenderPass;
	uint32_t            FrameIndex;             // Current frame being rendered to (0 <= FrameIndex < FrameInFlightCount)
	uint32_t            ImageCount;             // Number of simultaneous in-flight frames (returned by vkGetSwapchainImagesKHR, usually derived from min_image_count)
	uint32_t            SemaphoreCount;         // Number of simultaneous in-flight frames + 1, to be able to use it in vkAcquireNextImageKHR
	uint32_t            SemaphoreIndex;         // Current set of swapchain wait semaphores we're using (needs to be distinct from per frame data)
	ImVector_ImGui_ImplVulkanH_Frame           Frames;
	ImVector_ImGui_ImplVulkanH_FrameSemaphores FrameSemaphores;
};

#endif

#endif

#endif // CIMGUI_IMPL_VULKAN_H
