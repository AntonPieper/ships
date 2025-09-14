#include <curses.h>
#include <curses_renderer/renderer.h>
#include <render/renderer.h>

static bool curses_init(Renderer *this);
static bool curses_close(Renderer *this);
static void curses_draw_string(
    Renderer *this, DrawStringOptions options);

const RendererOperations curses_vtable = {
    .init = curses_init,
    .close = curses_close,
    .draw_string = curses_draw_string,
};

Renderer curses_renderer_create(Vec2i size) {
  Renderer renderer = {
      .vtable = &curses_vtable,
  };
  return renderer;
}

static bool curses_init(Renderer *this) {
  initscr();
  return true;
}

static bool curses_close(Renderer *this) {
  return endwin() == OK;
}

static void curses_draw_string(
    Renderer *this, DrawStringOptions options) {
  printw("%*s", (int)options.str.length,
         options.str.data);
}
