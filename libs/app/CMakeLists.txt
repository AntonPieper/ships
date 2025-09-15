add_library(app STATIC ./src/intent.c)
target_include_directories(app PUBLIC ./include)
target_link_libraries(app PUBLIC core)
