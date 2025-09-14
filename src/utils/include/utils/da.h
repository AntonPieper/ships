#ifndef UTILS_DA_H
#define UTILS_DA_H

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#ifndef DA_INIT_CAP
#define DA_INIT_CAP 256
#endif

#ifdef __cplusplus
#define DECLTYPE_CAST(T) (decltype(T))
#else
#define DECLTYPE_CAST(T)
#endif  // __cplusplus

#define DA_ASSERT_COMPAT(T)                      \
  static_assert(sizeof(((T*)0)->items) &&        \
                    sizeof(((T*)0)->capacity) && \
                    sizeof(((T*)0)->length),     \
                /* unused */ "")

#define da_reserve(da, expected_capacity)             \
  do {                                                \
    if ((expected_capacity) > (da)->capacity) {       \
      if ((da)->capacity == 0) {                      \
        (da)->capacity = DA_INIT_CAP;                 \
      }                                               \
      while ((expected_capacity) > (da)->capacity) {  \
        (da)->capacity *= 2;                          \
      }                                               \
      (da)->items =                                   \
          DECLTYPE_CAST((da)->items) realloc(         \
              (da)->items,                            \
              (da)->capacity * sizeof(*(da)->items)); \
      assert((da)->items != NULL && "Out of memory"); \
    }                                                 \
  } while (0)

#define da_append(da, item)              \
  do {                                   \
    da_reserve((da), (da)->count + 1);   \
    (da)->items[(da)->count++] = (item); \
  } while (0)

#endif  // !UTILS_DA_H