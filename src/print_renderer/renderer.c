#include <assert.h>
#include <core/Vec2i.h>
#include <print_renderer/renderer.h>
#include <render/renderer.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <utils/da.h>

static bool print_init(Renderer *renderer);
static bool print_close(Renderer *renderer);
static void print_draw_string(
    Renderer *renderer, DrawStringOptions options);
static void print_swap(Renderer *renderer);

const RendererOperations print_vtable = {
    .init = print_init,
    .close = print_close,
    .draw_string = print_draw_string,
    .swap = print_swap,
};

PrintRenderer print_renderer_create() {
  Renderer renderer = {
      .vtable = &print_vtable,
      .size = sizeof(PrintRenderer),
  };
  return (PrintRenderer){
      .renderer = renderer,
  };
}

static bool print_init(Renderer *renderer) {
  return true;
}

static bool print_close(Renderer *renderer) {
  return true;
}

static int min(int a, int b) { return (a < b) ? a : b; }

static int max(int a, int b) { return (a > b) ? a : b; }

static Span span_chop_until(Span *str, char ch) {
  const size_t len = str->length;
  for (size_t i = 0; i < len; ++i) {
    if (str->data[i] == ch) {
      str->length = i;
      return (Span){
          .data = str->data + i,
          .length = str->length - i,
      };
    }
  }
  return (Span){
      .data = str->data + str->length - 1,
      .length = 0,
  };
}

typedef struct NewlineInfo {
  size_t max_line_length;
  size_t line_count;
} NewlineInfo;
static NewlineInfo span_newline_info(const Span str) {
  size_t line_max = 0;
  size_t line_start = -1;
  size_t line_count = 1;
  for (size_t i = 0; i < str.length; ++i) {
    if (str.data[i] != '\n') {
      continue;
    }
    ++line_count;
    size_t line_length = i - line_start - 1;
    line_max = max(line_max, line_length);
    line_start = i;
  }
  size_t last_line_length = str.length - line_start - 1;
  line_max = max(line_max, last_line_length);

  return (NewlineInfo){
      .max_line_length = line_max,
      .line_count = line_count,
  };
}

static void print_draw_string(
    Renderer *renderer, DrawStringOptions options) {
  assert(renderer->size == sizeof(PrintRenderer));
  PrintRenderer *this = (PrintRenderer *)renderer;
  da_reserve(&this->screen, this->width * this->height);
  Span str = options.str;
  Vec2i position = options.position;
  const Vec2i start = position;
  Vec2i coord = position;
  for (size_t i = 0; i < str.length; ++i) {
    char ch = str.data[i];
    if ((coord.x > 0 && coord.x < this->width) &&
        (coord.y > 0 && coord.y < this->height)) {
      fputc(ch, stdout);
    }
    if (ch == '\n') {
      ++coord.y;
    }
    ++coord.x;
  }
}

static void print_swap(Renderer *renderer) {}
