cmake_minimum_required(VERSION 3.0.0)

######################################################################################

set( PROJECT_NAME "PrintImages" )

set(APP_ICON ${CMAKE_CURRENT_LIST_DIR}/appicon.ico)
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -static")

######################################################################################

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(WINDOWS_VERSION 0x0A00) 
add_definitions(-DWINVER=${WINDOWS_VERSION})
add_definitions(-D_WIN32_WINNT=${WINDOWS_VERSION})

######################################################################################

include_directories(dep/ebcpp/src)
include(src/CMakeLists.txt)

######################################################################################

project(${PROJECT_NAME} VERSION 0.1.0)

add_executable(${PROJECT_NAME} ${PROGRAM_SRCS})
target_link_libraries(${PROJECT_NAME} gdiplus)

######################################################################################

# http://www.angusj.com/resourcehacker/resource_hacker.zip

#add_custom_command(
#  TARGET ${PROJECT_NAME}
#  POST_BUILD
#  COMMAND
#    ResourceHacker.exe
#    -open ${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.exe
#    -save ${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.exe
#    -action addskip -res ${APP_ICON}
#    -mask ICONGROUP,MAINICON,
#)

######################################################################################
