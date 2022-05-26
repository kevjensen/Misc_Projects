cmake_minimum_required(VERSION 3.15)
project(VigenereCipher)

set(CMAKE_CXX_STANDARD 20)

# Compiler Flags
set(GCC_WARNINGS "-Wall -Wextra -Wpedantic -Wunused -Wformat=2 -Wswitch-enum -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wcast-align -Wcast-qual -Wconversion -Wsign-conversion -Wzero-as-null-pointer-constant -Wlogical-op -Wmissing-declarations -Wctor-dtor-privacy -Wnoexcept -Wnon-virtual-dtor -Wstrict-null-sentinel -Wold-style-cast -Woverloaded-virtual -Wfloat-equal -Wredundant-decls -Wshadow -Wwrite-strings -Wno-long-long")
set(CLANG_WARNINGS "-Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-documentation-unknown-command")


set(CLANG_DEBUG "-O0 -g")
set(CLANG_RELEASE "-O3")

set(GCC_DEBUG "-O0 -g")
set(GCC_RELEASE "-O3")


# Set up the compiler flags used
if(CMAKE_COMPILER_IS_GNUCXX)
    # gcc
    set(CMAKE_CXX_FLAGS "${GCC_WARNINGS}")

    set(CMAKE_CXX_FLAGS_DEBUG "${GCC_DEBUG}")
    set(CMAKE_CXX_FLAGS_RELEASE "${GCC_RELEASE}")
else()
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        # clang
        set(CMAKE_CXX_FLAGS "${CLANG_WARNINGS}")

        set(CMAKE_CXX_FLAGS_DEBUG "${CLANG_DEBUG}")
        set(CMAKE_CXX_FLAGS_RELEASE "${CLANG_RELEASE}")
    else()
        # Generic flags for undetected compiler
        set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
        set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    endif()
endif()

# Copies Plain_txt file
file(COPY Plain_txt.txt DESTINATION ${CMAKE_BINARY_DIR})
add_executable(VigenereCipher main.cpp Letter.cpp Letter.h Crypto.cpp Crypto.h)