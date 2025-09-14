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

add_library(curses_renderer renderer.c)
target_include_directories(curses_renderer PUBLIC ./include)

target_link_libraries(curses_renderer
  PRIVATE
    Curses::Curses
  PUBLIC
    renderer
    core
)
