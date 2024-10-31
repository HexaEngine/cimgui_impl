@echo off
rm -r .\bin\
mkdir bin
cd bin
mkdir base
mkdir glfw
mkdir sdl2
cd ..

rm -r .\build\
cmake -DCMAKE_TOOLCHAIN_FILE="C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" -B build -S . -A arm64 -DBACKENDS_BASE_ONLY=ON -DIMGUI_WCHAR32=ON
cmake --build .\build\ --config Release
mv ./build/Release/*.dll ./bin/base/

rm -r .\build\
cmake -DCMAKE_TOOLCHAIN_FILE="C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" -B build -S . -A arm64 -DBACKENDS_SDL2_ONLY=ON -DIMGUI_WCHAR32=ON
cmake --build .\build\ --config Release
mv ./build/Release/*.dll ./bin/sdl2/

rm -r .\build\
cmake -DCMAKE_TOOLCHAIN_FILE="C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" -B build -S . -A arm64 -DBACKENDS_GLFW_ONLY=ON -DIMGUI_WCHAR32=ON
cmake --build .\build\ --config Release
mv ./build/Release/*.dll ./bin/glfw/