add_library(app intent.c)
target_include_directories(app PUBLIC ./include)
target_link_libraries(app PUBLIC core)
