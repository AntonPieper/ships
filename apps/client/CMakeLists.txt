add_executable(ships
  ./src/main.c
)
target_link_libraries(ships
  PRIVATE
    app
    core
)
