#!/bin/bash
SDL_VER=2.0.8
MAIN_DIR_PATH=`pwd`
SDL2_DIR=$MAIN_DIR_PATH/lib/sdl2
curl -OL http://www.libsdl.org/release/SDL2-$SDL_VER.tar.gz
tar -zxvf SDL2-$SDL_VER.tar.gz
rm SDL2-$SDL_VER.tar.gz
mkdir -p $SDL2_DIR
cd SDL2-$SDL_VER
sh configure --prefix=$SDL2_DIR
make
make install
cd ..
rm -rf SDL2-$SDL_VER
