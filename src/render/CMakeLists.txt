add_library(renderer INTERFACE)
target_include_directories(renderer INTERFACE .)
target_link_libraries(renderer INTERFACE core)
