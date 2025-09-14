add_subdirectory(./app)
add_subdirectory(./core)
add_subdirectory(./curses_renderer)
add_subdirectory(./print_renderer)
add_subdirectory(./render)
add_subdirectory(./utils)

add_executable(ships
  ./main.c
)
target_link_libraries(ships
  PRIVATE
    app
    core
)
