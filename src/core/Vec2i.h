#ifndef CORE_VEC2I_H
#define CORE_VEC2I_H

#include "vec2.h"
#include <stdint.h>

typedef struct Vec2i {
  int32_t x;
  int32_t y;
} Vec2i;
Vec2Impl(int32_t, Vec2i);

#endif // !CORE_VEC2I_H
