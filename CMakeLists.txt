cmake_minimum_required(VERSION 3.10)
project(dockerizecppv2)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

set(CMAKE_CXX_STANDARD 17)


add_executable(dockerizecppv2 main.cpp)
target_link_libraries(dockerizecppv2 ${CONAN_LIBS})