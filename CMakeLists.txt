cmake_minimum_required(VERSION 3.8)
project(cimgui_impl)

set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

set (CMAKE_CXX_STANDARD 11)

#general settings
option(BACKENDS_WIN32 "Enable Win32 backend" ON)
option(BACKENDS_D3D11 "Enable Direct3D 11 backend" ON)
option(BACKENDS_D3D12 "Enable Direct3D 12 backend" ON)
option(BACKENDS_VULKAN "Enable Vulkan backend" ON)
option(BACKENDS_OPENGL3 "Enable OpenGL 3 backend" ON)
option(BACKENDS_OPENGL2 "Enable OpenGL 2 backend" ON)
option(BACKENDS_METAL "Enable Metal backend" ON)
option(BACKENDS_OSX "Enable OSX backend" ON)
option(BACKENDS_BASE_ONLY "Only base backends" OFF)
option(BACKENDS_GLFW "Enable GLFW backend" ON)
option(BACKENDS_GLFW_ONLY "Only GLFW backend" OFF)
option(BACKENDS_SDL2 "Enable SDL2 backend" ON)
option(BACKENDS_SDL2_ONLY "Only SDL2 backend" OFF)
option(BACKENDS_NO_GRAPHICS "Disables all graphics backends" OFF)
option(BACKENDS_NO_BASE "Disables all base backends" OFF)
option(IMGUI_WCHAR32 "Build with ImWChar32" OFF)

if (BACKENDS_GLFW_ONLY AND BACKENDS_SDL2_ONLY)
	message(FATAL_ERROR "You cannot set both BACKENDS_GLFW_ONLY and BACKENDS_SDL2_ONLY")
endif()

if (BACKENDS_BASE_ONLY)
	set(BACKENDS_GLFW OFF)
	set(BACKENDS_SDL2 OFF)
	set(lib_name "ImGuiImpl")
endif()

if (BACKENDS_SDL2_ONLY)
	set(BACKENDS_GLFW OFF)
	set(BACKENDS_SDL2 ON)
	set(BACKENDS_NO_BASE ON)
	set(lib_name "ImGuiImplSDL2")
endif()

if (BACKENDS_GLFW_ONLY)
	set(BACKENDS_GLFW ON)
	set(BACKENDS_SDL2 OFF)
	set(BACKENDS_NO_BASE ON)
	set(lib_name "ImGuiImplGLFW")
endif()

if (BACKENDS_BASE_ONLY AND BACKENDS_NO_BASE)
	message(FATAL_ERROR "You cannot set both BACKENDS_BASE_ONLY and BACKENDS_NO_BASE (note this can happen if you set BACKENDS_BASE_ONLY and any other ONLY option)")
endif()

if (BACKENDS_NO_BASE)
	set(BACKENDS_WIN32 OFF)
	set(BACKENDS_OSX OFF)
	set(BACKENDS_NO_GRAPHICS ON)
endif()

if (BACKENDS_NO_GRAPHICS)
	set(BACKENDS_D3D11 OFF)
	set(BACKENDS_D3D12 OFF)
	set(BACKENDS_OPENGL3 OFF)
	set(BACKENDS_OPENGL2 OFF)
	set(BACKENDS_VULKAN OFF)
	set(BACKENDS_METAL OFF)
endif()

# Automatically detect platform and set options accordingly
if(WIN32)
    message(STATUS "Configuring for Windows...") 
	set(BACKENDS_METAL OFF)
	set(BACKENDS_OSX OFF)
elseif(APPLE)
    message(STATUS "Configuring for macOS...")
    set(BACKENDS_D3D11 OFF)
    set(BACKENDS_D3D12 OFF)

elseif(ANDROID)
	message("Configuring for Android...")
	set(BACKENDS_D3D11 OFF)
	set(BACKENDS_D3D12 OFF)
	set(BACKENDS_OPENGL3 OFF)
	set(BACKENDS_OPENGL2 OFF)
	set(BACKENDS_WIN32 OFF)
	set(BACKENDS_VULKAN OFF)
	set(BACKENDS_GLFW OFF)
	set(BACKENDS_SDL2 OFF)
	set(BACKENDS_METAL OFF)
	set(BACKENDS_OSX OFF)

elseif(UNIX AND NOT APPLE)
    message(STATUS "Configuring for Linux...")
    set(BACKENDS_D3D11 OFF)
    set(BACKENDS_D3D12 OFF)
	set(BACKENDS_METAL OFF)
	set(BACKENDS_OSX OFF)
endif()

set(BACKENDS_FOLDER "imgui/backends/")

if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/imgui/imgui_tables.cpp)
	set(TABLES_SOURCE "imgui/imgui_tables.cpp")
else()
	set(TABLES_SOURCE "")
endif()

include_directories(imgui)
add_definitions("-DIMGUI_DISABLE_OBSOLETE_FUNCTIONS=1")

include_directories()
set(IMGUI_SOURCES 
cimgui_impl.cpp 
imgui/imgui.cpp 
imgui/imgui_draw.cpp 
imgui/imgui_demo.cpp 
imgui/imgui_widgets.cpp
${TABLES_SOURCE} 
)

set(IMGUI_LIBRARIES )

if (WIN32)
    add_definitions("-DIMGUI_IMPL_API=extern \"C\" __declspec\(dllexport\)")
else(WIN32)
    add_definitions("-DIMGUI_IMPL_API=extern \"C\" ")
endif(WIN32)

add_compile_definitions("IMGUI_IMPL_OPENGL_LOADER_GL3W")

#optional adding freetype
option(IMGUI_FREETYPE "add Freetype2" OFF)

if(IMGUI_FREETYPE)
	FIND_PACKAGE(freetype REQUIRED PATHS ${FREETYPE_PATH})
	list(APPEND IMGUI_LIBRARIES freetype)
	list(APPEND IMGUI_SOURCES imgui/misc/freetype/imgui_freetype.cpp)
	add_definitions("-DCIMGUI_FREETYPE=1")
endif()

message("Building with:")
if (BACKENDS_WIN32 AND WIN32)
	message("Backends Win32: ON")
	# win32
	list(APPEND IMGUI_SOURCES ${BACKENDS_FOLDER}imgui_impl_win32.cpp)

	if (BACKENDS_D3D11)
		message("Backends D3D11: ON")
		# dx11
		list(APPEND IMGUI_SOURCES ${BACKENDS_FOLDER}imgui_impl_dx11.cpp)
	endif()

	if (BACKENDS_D3D12)
		message("Backends D3D12: ON")
		# dx12
		list(APPEND IMGUI_LIBRARIES dxgi.lib)
		list(APPEND IMGUI_SOURCES ${BACKENDS_FOLDER}imgui_impl_dx12.cpp)
	endif()
endif()

if (BACKENDS_VULKAN)
	message("Backends Vulkan: ON")
	# vulkan
	find_package(Vulkan REQUIRED)
	list(APPEND IMGUI_LIBRARIES Vulkan::Vulkan)
	list(APPEND IMGUI_SOURCES ${BACKENDS_FOLDER}imgui_impl_vulkan.cpp)
endif()

# Metal
if (BACKENDS_METAL AND APPLE)
	message("Backends Metal: ON")
	find_library(METAL_FRAMEWORK Metal REQUIRED)
	list(APPEND IMGUI_LIBRARIES ${METAL_FRAMEWORK})
	list(APPEND IMGUI_SOURCES ${BACKENDS_FOLDER}imgui_impl_metal.mm)
endif()

# OSX
if (BACKENDS_OSX AND APPLE)
	message("Backends OSX: ON")
    find_library(COCOA_FRAMEWORK Cocoa REQUIRED)
    find_library(QUARTZCORE_FRAMEWORK QuartzCore REQUIRED)
	find_library(GAMECONTROLLER_FRAMEWORK GameController REQUIRED)
    list(APPEND IMGUI_LIBRARIES ${COCOA_FRAMEWORK} ${QUARTZCORE_FRAMEWORK} ${GAMECONTROLLER_FRAMEWORK})
	list(APPEND IMGUI_SOURCES ${BACKENDS_FOLDER}imgui_impl_osx.mm)
endif()

# GLFW
if (BACKENDS_GLFW)
	message("Backends GLFW: ON")
	find_package(glfw3 REQUIRED)
	list(APPEND IMGUI_LIBRARIES glfw)
	list(APPEND IMGUI_SOURCES ${BACKENDS_FOLDER}imgui_impl_glfw.cpp)
endif()

#opengl3
if (BACKENDS_OPENGL3)
	message("Backends OPENGL3: ON")
	find_package(OpenGL REQUIRED)
	list(APPEND IMGUI_LIBRARIES OpenGL::GL OpenGL::GLU)
	list(APPEND IMGUI_SOURCES ${BACKENDS_FOLDER}imgui_impl_opengl3.cpp)
	include_directories(imgui/examples/libs/gl3w)
	message(STATUS "OpenGL_LIBRARIES: ${OPENGL_LIBRARIES}")
endif()

#opengl2
if (BACKENDS_OPENGL2)
	message("Backends OPENGL2: ON")
	list(APPEND IMGUI_SOURCES ${BACKENDS_FOLDER}imgui_impl_opengl2.cpp)
	include_directories(imgui/examples/libs/gl3w)
	if (!BACKENDS_OPENGL3)
		find_package(OpenGL REQUIRED)
		list(APPEND IMGUI_LIBRARIES OpenGL::GL OpenGL::GLU)
	endif(!BACKENDS_OPENGL3)
endif()

#sdl2
if (BACKENDS_SDL2)
	message("Backends SDL2: ON")
	list(APPEND IMGUI_SOURCES ${BACKENDS_FOLDER}imgui_impl_sdl2.cpp)
	list(APPEND IMGUI_SOURCES ${BACKENDS_FOLDER}imgui_impl_sdlrenderer2.cpp)
	
	find_package(SDL2 CONFIG REQUIRED)

	if(SDL2_FOUND)
		get_target_property(SDL_INCLUDE SDL2::SDL2 INTERFACE_INCLUDE_DIRECTORIES)
		message(STATUS "sdlinclude is " ${SDL_INCLUDE})
		if ("${SDL_INCLUDE}" STREQUAL "" OR "${SDL_INCLUDE}" STREQUAL "SDL_INCLUDE-NOTFOUND") #if not found latest SDL2 cmake config use older
			message(STATUS "sdlinclude2 is " ${SDL2_INCLUDE_DIRS})
			include_directories(${SDL2_INCLUDE_DIRS})
			set(IMGUI_SDL_LIBRARY ${SDL2_LIBRARIES})
			message(STATUS IMGUI_SDL_LIBRARY ${SDL2_LIBRARIES})
		else()#use new one SDL2 config
			include_directories(${SDL_INCLUDE})
			set(IMGUI_SDL_LIBRARY SDL2::SDL2)
			set(SDL_MAIN SDL2::SDL2main)
			message(STATUS ${SDL_MAIN} ${IMGUI_SDL_LIBRARY})
		endif()
	else(SDL2_FOUND)
		if(DEFINED SDL_PATH)
			message(FATAL_ERROR "Cannot find SDL at SDL_PATH")
		else(DEFINED SDL_PATH)
			message(FATAL_ERROR "Cannot find SDL. Maybe try specifying SDL_PATH?")
		endif(DEFINED SDL_PATH)
	endif(SDL2_FOUND)
endif(BACKENDS_SDL2)

if (ANDROID)
	message("Backends Android: ON")
	list(APPEND IMGUI_SOURCES ${BACKENDS_FOLDER}imgui_impl_android.cpp)
endif()

add_library(cimgui_impl SHARED ${IMGUI_SOURCES})

if(DEFINED lib_name)
    set_target_properties(cimgui_impl PROPERTIES OUTPUT_NAME ${lib_name})
endif()

if (APPLE AND BACKENDS_VULKAN)
	target_link_options(cimgui_impl PRIVATE -weak_library ${VULKAN_LIBRARY})
endif()

if(APPLE)
	if(BACKENDS_SDL2)
		add_custom_command(TARGET cimgui_impl POST_BUILD COMMAND install_name_tool -change /opt/homebrew/opt/sdl2/lib/libSDL2-2.0.0.dylib @loader_path/libSDL2.dylib $<TARGET_FILE:cimgui_impl>)
		add_custom_command(TARGET cimgui_impl POST_BUILD COMMAND install_name_tool -change /usr/local/opt/sdl2/lib/libSDL2-2.0.0.dylib @loader_path/libSDL2.dylib $<TARGET_FILE:cimgui_impl>)
 	endif(BACKENDS_SDL2)
  	if(BACKENDS_GLFW)
		add_custom_command(TARGET cimgui_impl POST_BUILD COMMAND install_name_tool -change /opt/homebrew/opt/glfw/lib/libglfw.3.dylib @loader_path/libglfw.dylib $<TARGET_FILE:cimgui_impl>)
		add_custom_command(TARGET cimgui_impl POST_BUILD COMMAND install_name_tool -change /usr/local/opt/glfw/lib/libglfw.3.dylib @loader_path/libglfw.dylib $<TARGET_FILE:cimgui_impl>)
 	endif(BACKENDS_GLFW)
elseif(UNIX AND NOT APPLE)
	set_target_properties(cimgui_impl PROPERTIES INSTALL_RPATH "\$ORIGIN" BUILD_WITH_INSTALL_RPATH TRUE)
 	if(BACKENDS_SDL2)
 		add_custom_command(TARGET cimgui_impl POST_BUILD COMMAND patchelf --replace-needed libSDL2-2.0.so.0 libSDL2.so $<TARGET_FILE:cimgui_impl>)
	endif(BACKENDS_SDL2)
 	 if(BACKENDS_GLFW)
 		add_custom_command(TARGET cimgui_impl POST_BUILD COMMAND  patchelf --replace-needed libglfw.so.3 libglfw.so $<TARGET_FILE:cimgui_impl>)
	endif(BACKENDS_GLFW)
endif()

if (IMGUI_WCHAR32)
	target_compile_definitions(cimgui_impl PRIVATE IMGUI_USE_WCHAR32=1)
endif()

if(BACKENDS_WIN32)
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_WIN32=1)
else()
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_WIN32=0)
endif()

if(BACKENDS_OSX)
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_OSX=1)
else()
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_OSX=0)
endif()

if(BACKENDS_D3D11)
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_D3D11=1)
else()
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_D3D11=0)
endif()

if(BACKENDS_D3D12)
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_D3D12=1)
else()
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_D3D12=0)
endif()

if(BACKENDS_METAL)
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_METAL=1)
else()
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_METAL=0)
endif()

if(BACKENDS_VULKAN)
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_VULKAN=1)
else()
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_VULKAN=0)
endif()

if(BACKENDS_GLFW)
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_GLFW=1)
else()
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_GLFW=0)
endif()

if(BACKENDS_OPENGL2)
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_OPENGL2=1)
else()
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_OPENGL2=0)
endif()

if(BACKENDS_OPENGL3)
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_OPENGL3=1)
else()
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_OPENGL3=0)
endif()

if(BACKENDS_SDL2)
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_SDL2=1)
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_SDL2Renderer=1)
else()
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_SDL2=0)
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_SDL2Renderer=0)
endif()

if (MSVC)
target_link_libraries(cimgui_impl PRIVATE ${IMGUI_LIBRARIES} ${IMGUI_SDL_LIBRARY} delayimp)
else(MSVC)
target_link_libraries(cimgui_impl PRIVATE ${IMGUI_LIBRARIES} ${IMGUI_SDL_LIBRARY})
endif()

if (MSVC)
	if(BACKENDS_GLFW)
    	target_link_options(cimgui_impl PRIVATE "/DELAYLOAD:glfw3.dll")
	endif()

	if(BACKENDS_SDL2)
		target_link_options(cimgui_impl PRIVATE "/DELAYLOAD:SDL2.dll")
	endif()
endif()

install(TARGETS cimgui_impl
        LIBRARY DESTINATION .
        ARCHIVE DESTINATION .
)
