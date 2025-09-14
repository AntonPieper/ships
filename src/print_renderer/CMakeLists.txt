add_library(print_renderer renderer.c)
target_include_directories(print_renderer PUBLIC ./include)
target_link_libraries(print_renderer PUBLIC renderer)