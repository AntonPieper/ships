#ifndef RENDER_RENDERER_H
#define RENDER_RENDERER_H

#include <core/Vec2i.h>
#include <stddef.h>
#include <utils/span.h>

typedef struct RendererOperations RendererOperations;

typedef struct Renderer {
  const RendererOperations *const vtable;
  const size_t size;
} Renderer;

typedef enum AlignMode {
  ALIGN_MODE_START,
  ALIGN_MODE_CENTER,
  ALIGN_MODE_END,
} AlignMode;

typedef struct {
  Span str;
  Vec2i position;
  AlignMode verticalAlign;
  AlignMode horizontalAlign;
} DrawStringOptions;

struct RendererOperations {
  bool (*init)(Renderer *this);
  bool (*close)(Renderer *this);
  void (*draw_string)(Renderer *this,
                      DrawStringOptions options);
  void (*swap)(Renderer *this);
};

static inline bool renderer_close(Renderer *this) {
  return this->vtable->close(this);
}

static inline bool enderer_init(Renderer *this) {
  return this->vtable->init(this);
}

static inline void renderer_swap(Renderer *this) {
  this->vtable->swap(this);
}

static inline void renderer_draw_string(
    Renderer *this, DrawStringOptions options) {
  this->vtable->draw_string(this, options);
}

#define renderer_draw_string(this, str, position, ...) \
  renderer_draw_string(                                \
      this,                                            \
      (DrawStringOptions){.s##tr = (str),              \
                          .p##osition = (position),    \
                          __VA_ARGS__})

#endif  // !RENDER_RENDERER_H
