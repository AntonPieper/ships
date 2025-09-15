cmake_minimum_required(VERSION 3.16)
project(ships LANGUAGES C)

if(NOT CMAKE_BUILD_TYPE)
  set(default_build_type "Debug")
  message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
  set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Chooce the build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
  "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "ships Build Type: ${CMAKE_BUILD_TYPE}")

# Set the version for ships
set(ships_Version_Major 0)
set(ships_Version_Minor 1)
set(ships_Version_Patch 0)
set(ships_Version_Status "-dev")
set(PROJECT_VERSION
  "${ships_Version_Major}.${ships_Version_Minor}.${ships_Version_Patch}${ships_Version_Status}"
)
message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")

add_subdirectory(libs)
add_subdirectory(apps)
