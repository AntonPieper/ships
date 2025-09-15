add_library(renderer_print STATIC ./src/renderer.c)
add_library(renderer::print ALIAS renderer_print)

target_include_directories(renderer_print PUBLIC ./include)
target_link_libraries(renderer_print PUBLIC renderer)