#ifndef RENDER_RENDERER_H
#define RENDER_RENDERER_H

#include "Vec2i.h"

typedef struct RendererOperations RendererOperations;

typedef struct {
  const RendererOperations *const vtable;
} Renderer;

typedef enum AlignMode {
  ALIGN_MODE_START,
  ALIGN_MODE_CENTER,
  ALIGN_MODE_END,
} AlignMode;

typedef struct {
  const char *str;
  int str_len;
  Vec2i position;
  AlignMode verticalAlign;
  AlignMode horizontalAlign;
} DrawStringOptions;

struct RendererOperations {
  bool (*init)(Renderer *const this, Vec2i size);
  void (*draw_string)(Renderer *const this,
                      DrawStringOptions options);
};

static inline void renderer_draw_string_options(
    Renderer *const this, DrawStringOptions options) {
  this->vtable->draw_string(this, options);
}

#define renderer_draw_string(renderer, str, position,  \
                             ...)                      \
  renderer_draw_string_options(                        \
      renderer,                                        \
      (DrawStringOptions){.s##tr = (str),              \
                          .p##osition = (position),    \
                          __VA_ARGS__})

#endif // !RENDER_RENDERER_H
