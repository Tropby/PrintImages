cmake_minimum_required(VERSION 3.0.0)

set( PROJECT_NAME "PrintImages" )

project(${PROJECT_NAME} VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(WINDOWS_VERSION 0x0A00) 
add_definitions(-DWINVER=${WINDOWS_VERSION})
add_definitions(-D_WIN32_WINNT=${WINDOWS_VERSION})

include_directories(dep/ebcpp/src)

include(src/CMakeLists.txt)

add_executable(${PROJECT_NAME} ${PROGRAM_SRCS})

target_link_libraries(${PROJECT_NAME} gdiplus)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -static")
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_LIST_DIR}/bin)