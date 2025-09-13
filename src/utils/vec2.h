#ifndef UTILS_VEC2_H
#define UTILS_VEC2_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

#define Vec2Impl(T, Name)                              \
  static inline Name Name##_add(Name a, Name b) {      \
    return (Name){.x = a.x + b.x, .y = a.y + b.y};     \
  }                                                    \
  static inline Name Name##_mul(Name a, Name b) {      \
    return (Name){.x = a.x * b.x, .y = a.y * b.y};     \
  }                                                    \
  static inline Name Name##_scale(Name v, T scale) {   \
    return (Name){.x = v.x * scale, .y = v.y * scale}; \
  }                                                    \
  static inline T Name##_dot(Name a, Name b) {         \
    return a.x * b.x + a.y * b.y;                      \
  }                                                    \
  static inline bool Name##_eq(Name a, Name b) {       \
    return a.x == b.x && a.y == b.y;                   \
  }                                                    \
  static_assert(sizeof(Name) == 2 * sizeof(T), #Name   \
                " must have 2 fields of type " #T);

#define Vec2Convert(From, To)                          \
  static inline To To##_from_##From(From v) {          \
    return (To){.x = v.x, .y = v.y};                   \
  }
#define Vec2ConvertPtr(From, To)                       \
  static inline const To *const                        \
  To##_from_##From##_ptr(const From *const v) {        \
    static_assert(sizeof(From) == sizeof(To),          \
                  "not same size");                    \
    return (const To *const)(v);                       \
  }

#endif // !UTILS_VEC2_H
