#ifndef UTILS_SPAN_H
#define UTILS_SPAN_H

#define STATIC_STRLEN(str) (sizeof(str) - 1)

#define SPAN(Type, value)                              \
  ((Type){                                             \
      .data = (value),                                 \
      .length = STATIC_STRLEN(value),                  \
  })

#endif // !UTILS_SPAN_H