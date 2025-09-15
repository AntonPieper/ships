#ifndef UTILS_SPAN_H
#define UTILS_SPAN_H

#include <stddef.h>

typedef struct Span {
  const char *data;
  size_t length;
} Span;

#define STATIC_STRLEN(str) (sizeof(str) - 1)

#define STATIC_SPAN(Type, value)      \
  ((Type){                            \
      .data = (value),                \
      .length = STATIC_STRLEN(value), \
  })

#endif  // !UTILS_SPAN_H