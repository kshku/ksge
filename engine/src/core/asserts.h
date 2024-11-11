#pragma once

#include "defines.h"

#define SASSERTIONS_ENABLED 1

#if S_RELEASE == 1
    #define SASSERTIONS_ENABLED 0
#endif

#if SASSERTIONS_ENABLED == 1
    #if SPLATFORM_WINDOWS == 1
        #include <intrin.h>
        #define DEBUG_BREAK() __debugbreak()
    #else
        #define DEBUG_BREAK() __builtin_trap()
    #endif

SAPI void assertion_failure(const char *expression, const char *message,
                            const char *file, i32 line);

    #define SASSERT(expr)                                     \
        if (expr) {                                           \
        } else {                                              \
            assertion_failure(#expr, "", __FILE__, __LINE__); \
            DEBUG_BREAK();                                    \
        }

    #define SASSERT_MSG(expr, msg)                             \
        if (expr) {                                            \
        } else {                                               \
            assertion_failure(#expr, msg, __FILE__, __LINE__); \
            DEBUG_BREAK();                                     \
        }

    #ifdef S_DEBUG
        #define SASSERT_DEBUG(expr) SASSERT(expr)
        #define SASSERT_DEBUG_MSG(expr, msg) SASSERT_MSG(expr, msg)
    #else
        #define SASSERT_DEBUG(expr)
        #define SASSERT_DEBUG_MSG(expr, msg)
    #endif
#else
    #define SASSERT(expr)
    #define SASSERT_MSG(expr, msg)
    #define SASSERT_DEBUG(expr)
    #define SASSERT_DEBUG_MSG(expr, msg)
#endif
