add_library(renderer INTERFACE)
target_include_directories(renderer INTERFACE ./include)
target_link_libraries(renderer INTERFACE core)

add_subdirectory(backends)