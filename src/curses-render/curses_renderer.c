#include "./curses_renderer.h"
#include "renderer.h"
#include <curses.h>

bool curses_init(Renderer *const this, Vec2i size);
void curses_draw_string(Renderer *const this,
                        DrawStringOptions options);

const RendererOperations curses_vtable = {
    .init = &curses_init,
    .draw_string = &curses_draw_string,
};

Renderer curses_renderer_create(Vec2i size) {
  Renderer renderer = {
      .vtable = &curses_vtable,
  };
  renderer.vtable->init(&renderer, size);
  return renderer;
}

bool curses_init(Renderer *const this, Vec2i size) {
  initscr();
  return true;
}
void curses_draw_string(Renderer *const this,
                        DrawStringOptions options) {
  if (options.str_len != 0) {
    printw("%*s", options.str_len, options.str);
  } else {
    printw("%s", options.str);
  }
}
