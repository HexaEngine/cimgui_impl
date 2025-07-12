#!/usr/bin/env bash
set -e

PLATFORM="${GHA_OS_NAME}"
ARCH="${GHA_CMAKE_ARCH}"
ANDROID_API="${GHA_ANDROID_API}"
ANDROID_NDK="${GHA_ANDROID_NDK}"
ANDROID_CMAKE_FLAGS="${GHA_ANDROID_CMAKE_FLAGS}"

SRC_DIR="src"
SDL_DIR="SDL"
INSTALL_DIR="install"
BUILD_DIR="build"

cd "$SRC_DIR"
git clone --recursive https://github.com/libsdl-org/SDL.git $SDL_DIR
cd "$SDL_DIR"
git checkout release-3.2.10

CMAKE_ARGS="-DSDL_STATIC=OFF -DSDL_SHARED=ON -DSDL_TEST=OFF -DCMAKE_BUILD_TYPE=Release"

if [[ "$PLATFORM" == "android" ]]; then
    cmake -S . -B "$BUILD_DIR" $ANDROID_CMAKE_FLAGS -DCMAKE_ANDROID_ARCH_ABI=$ARCH -DCMAKE_ANDROID_API=$ANDROID_API \
        $CMAKE_ARGS
elif [[ "$PLATFORM" == "linux" ]]; then
    cmake -S . -B "$BUILD_DIR" $CMAKE_ARGS
elif [[ "$PLATFORM" == "macos" ]]; then
    cmake -S . -B "$BUILD_DIR" -DCMAKE_OSX_ARCHITECTURES="$ARCH" $CMAKE_ARGS
elif [[ "$PLATFORM" == "windows" ]]; then
    cmake -S . -B "$BUILD_DIR" -A "$ARCH" $CMAKE_ARGS -DCMAKE_SYSTEM_VERSION=10.0.26100.0
else
    echo "Unknown platform: $PLATFORM"
    exit 1
fi

cmake --build "$BUILD_DIR" --config Release
cmake --install "$BUILD_DIR" --config Release --prefix "$INSTALL_DIR"
