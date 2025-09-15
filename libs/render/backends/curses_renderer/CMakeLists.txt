find_package(Curses REQUIRED)
if(Curses_FOUND AND NOT TARGET Curses::Curses)
  add_library(Curses::Curses INTERFACE IMPORTED)
  set_target_properties(
    Curses::Curses
    PROPERTIES
      INTERFACE_LINK_LIBRARIES "${CURSES_LIBRARIES}"
      INTERFACE_INCLUDE_DIRECTORIES "${CURSES_INCLUDE_DIRS}"
  )
endif()

add_library(renderer_curses STATIC ./src/renderer.c)
add_library(renderer::curses ALIAS renderer_curses)

target_include_directories(renderer_curses PUBLIC ./include)

target_link_libraries(renderer_curses
  PRIVATE
    Curses::Curses
  PUBLIC
    renderer
    core
)
