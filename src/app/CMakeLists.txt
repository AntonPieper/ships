add_library(intent intent.c)
target_include_directories(intent PUBLIC .)
target_link_libraries(intent PUBLIC core)
