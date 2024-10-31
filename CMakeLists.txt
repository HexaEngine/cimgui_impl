cmake_minimum_required(VERSION 3.8)
project(cimgui_impl)

set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

set (CMAKE_CXX_STANDARD 11)

#general settings
option(BACKENDS_WIN32 "Enable Win32 backend" ON)
option(BACKENDS_D3D11 "Enable Direct3D 11 backend" ON)
option(BACKENDS_D3D12 "Enable Direct3D 12 backend" ON)
option(BACKENDS_VULKAN "Enable Vulkan backend" ON)
option(BACKENDS_GLFW "Enable GLFW backend" ON)
option(BACKENDS_OPENGL3 "Enable OpenGL 3 backend" ON)
option(BACKENDS_OPENGL2 "Enable OpenGL 2 backend" ON)
option(BACKENDS_SDL2 "Enable SDL2 backend" ON)
option(BACKENDS_NO_GRAPHICS "Disables graphics" OFF)
set(IMGUI_WCHAR32 "no" CACHE STRING "Build with ImWChar32")

if (BACKENDS_NO_GRAPHICS)
	set(BACKENDS_D3D11 OFF)
	set(BACKENDS_D3D12 OFF)
	set(BACKENDS_OPENGL3 OFF)
	set(BACKENDS_OPENGL2 OFF)
	set(BACKENDS_VULKAN OFF)
endif(BACKENDS_NO_GRAPHICS)

if (IMGUI_WCHAR32)
    add_definitions("-DIMGUI_USE_WCHAR32=1")
endif(IMGUI_WCHAR32)

# Automatically detect platform and set options accordingly
if(WIN32)
    message(STATUS "Configuring for Windows...") 
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

elseif(UNIX AND NOT APPLE)
    message(STATUS "Configuring for Linux...")
    set(BACKENDS_D3D11 OFF)
    set(BACKENDS_D3D12 OFF)
endif()

set(BAKENDS_FOLDER "imgui/backends/")

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
endif(IMGUI_FREETYPE)

message("Building with:")
if (BACKENDS_WIN32 AND WIN32)
	message("Backends Win32: ON")
	# win32
	list(APPEND IMGUI_SOURCES ${BAKENDS_FOLDER}imgui_impl_win32.cpp)

	if (BACKENDS_D3D11)
		message("Backends D3D11: ON")
		# dx11
		list(APPEND IMGUI_SOURCES ${BAKENDS_FOLDER}imgui_impl_dx11.cpp)
	endif(BACKENDS_D3D11)

	if (BACKENDS_D3D12)
		message("Backends D3D12: ON")
		# dx12
		list(APPEND IMGUI_LIBRARIES dxgi.lib)
		list(APPEND IMGUI_SOURCES ${BAKENDS_FOLDER}imgui_impl_dx12.cpp)
	endif(BACKENDS_D3D12)
endif(BACKENDS_WIN32 AND WIN32)

if (BACKENDS_VULKAN)
	message("Backends Vulkan: ON")
	# vulkan
	find_package(Vulkan REQUIRED)
	list(APPEND IMGUI_LIBRARIES Vulkan::Vulkan)
	list(APPEND IMGUI_SOURCES ${BAKENDS_FOLDER}imgui_impl_vulkan.cpp)
endif(BACKENDS_VULKAN)

# GLFW
if (BACKENDS_GLFW)
	message("Backends GLFW: ON")
	find_package(glfw3 REQUIRED)
	list(APPEND IMGUI_LIBRARIES glfw)
	list(APPEND IMGUI_SOURCES ${BAKENDS_FOLDER}imgui_impl_glfw.cpp)
endif(BACKENDS_GLFW)

#opengl3
if (BACKENDS_OPENGL3)
	message("Backends OPENGL3: ON")
	find_package(OpenGL REQUIRED)
	list(APPEND IMGUI_LIBRARIES OpenGL::GL OpenGL::GLU)
	list(APPEND IMGUI_SOURCES ${BAKENDS_FOLDER}imgui_impl_opengl3.cpp)
	include_directories(imgui/examples/libs/gl3w)
	message(STATUS "OpenGL_LIBRARIES: ${OPENGL_LIBRARIES}")
endif(BACKENDS_OPENGL3)

#opengl2
if (BACKENDS_OPENGL2)
	message("Backends OPENGL2: ON")
	list(APPEND IMGUI_SOURCES ${BAKENDS_FOLDER}imgui_impl_opengl2.cpp)
	include_directories(imgui/examples/libs/gl3w)
	if (!BACKENDS_OPENGL3)
		find_package(OpenGL REQUIRED)
		list(APPEND IMGUI_LIBRARIES OpenGL::GL OpenGL::GLU)
	endif(!BACKENDS_OPENGL3)
endif(BACKENDS_OPENGL2)

#sdl2
if (BACKENDS_SDL2)
	message("Backends SDL2: ON")
	list(APPEND IMGUI_SOURCES ${BAKENDS_FOLDER}imgui_impl_sdl2.cpp)
	list(APPEND IMGUI_SOURCES ${BAKENDS_FOLDER}imgui_impl_sdlrenderer2.cpp)
	
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
	list(APPEND IMGUI_SOURCES ${BAKENDS_FOLDER}imgui_impl_android.cpp)
endif(ANDROID)

add_library(cimgui_impl SHARED ${IMGUI_SOURCES})

if(APPLE)
	set(CMAKE_MACOSX_RPATH 1)
	set_target_properties(cimgui_impl PROPERTIES INSTALL_RPATH "@rpath" INSTALL_RPATH_USE_LINK_PATH TRUE)
 	set(CMAKE_INSTALL_RPATH "@rpath")
	set_target_properties(cimgui_impl PROPERTIES INSTALL_RPATH "@rpath")
elseif(UNIX AND NOT APPLE)
	set_target_properties(cimgui_impl PROPERTIES INSTALL_RPATH "\$ORIGIN" BUILD_WITH_INSTALL_RPATH TRUE)
endif()

if(BACKENDS_WIN32)
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_WIN32=1)
else()
    target_compile_definitions(cimgui_impl PRIVATE CIMGUI_USE_WIN32=0)
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
    target_link_options(cimgui_impl PRIVATE "/DELAYLOAD:glfw3.dll")
	target_link_options(cimgui_impl PRIVATE "/DELAYLOAD:SDL2.dll")
endif()

install(TARGETS cimgui_impl
        LIBRARY DESTINATION .
        ARCHIVE DESTINATION .
)
