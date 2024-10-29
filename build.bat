@echo off
rm -r .\bin\
mkdir bin
cd bin
mkdir base
mkdir glfw
mkdir sdl2
cd ..

rm -r .\build\
cmake -DCMAKE_TOOLCHAIN_FILE="C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" -B build -S . -A arm64 -DBACKENDS_WIN32=OFF -DBACKENDS_NO_GRAPHICS=ON -DBACKENDS_GLFW=OFF -DBACKENDS_SDL2=ON -DIMGUI_WCHAR32=ON
cmake --build .\build\ --config Release
mv ./build/Release/*.dll ./bin/sdl2/

rm -r .\build\
cmake -DCMAKE_TOOLCHAIN_FILE="C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" -B build -S . -A arm64 -DBACKENDS_WIN32=OFF -DBACKENDS_NO_GRAPHICS=ON -DBACKENDS_GLFW=ON -DBACKENDS_SDL2=OFF -DIMGUI_WCHAR32=ON
cmake --build .\build\ --config Release
mv ./build/Release/*.dll ./bin/glfw/

rm -r .\build\
cmake -DCMAKE_TOOLCHAIN_FILE="C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" -B build -S . -A arm64 -DBACKENDS_GLFW=OFF -DBACKENDS_SDL2=OFF -DIMGUI_WCHAR32=ON
cmake --build .\build\ --config Release
mv ./build/Release/*.dll ./bin/base/