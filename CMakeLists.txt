cmake_minimum_required(VERSION 3.14)
project(huffman)

set(CMAKE_CXX_STANDARD 17)

set(S_EXE utility/console.h utility/console.cpp utility/util.h utility/util.cpp test/test.cpp)
set(S_LIB lib/encoder.h lib/encoder.cpp lib/decoder.h lib/decoder.cpp )

add_library(HuffmanCompresser STATIC ${S_LIB})
add_executable(Testing ${S_EXE})

target_link_libraries(Testing HuffmanCompresser)