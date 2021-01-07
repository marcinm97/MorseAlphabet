cmake_minimum_required(VERSION 3.17)
project(MorseAlphabet C)

set(CMAKE_C_STANDARD 99)

add_executable(MorseAlphabet main.c morse.h morse.c)