#ifndef PRINT_RENDERER_RENDERER_H
#define PRINT_RENDERER_RENDERER_H

#include <core/Vec2i.h>
#include <render/renderer.h>
#include <stddef.h>
#include <utils/da.h>

typedef struct ScreenData {
  char *items;
  size_t capacity;
  size_t length;
} ScreenData;

DA_ASSERT_COMPAT(ScreenData);

typedef struct PrintRenderer {
  Renderer renderer;
  ScreenData screen;
  size_t width;
  size_t height;
  Vec2i cursor;
} PrintRenderer;

PrintRenderer print_renderer_create(void);

#endif  // !PRINT_RENDERER_RENDERER_H