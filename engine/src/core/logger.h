#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

#if S_RELEASE == 1
    #define LOG_FATAL_ENABLED 1
    #define LOG_ERROR_ENABLED 1
#endif

typedef enum LogLevel {
    LOG_LEVEL_FATAL,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARN,
    LOG_LEVEL_INFO,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_TRACE,
} LogLevel;

b8 initialize_logging();

void shutdown_logging();

SAPI void log_message(LogLevel level, const char *message, ...);

#define SFATAL(message, ...) \
    log_message(LOG_LEVEL_FATAL, message, ##__VA_ARGS__)

#define SERROR(message, ...) \
    log_message(LOG_LEVEL_ERROR, message, ##__VA_ARGS__)

#if LOG_WARN_ENABLED == 1
    #define SWARN(message, ...) \
        log_message(LOG_LEVEL_WARN, message, ##__VA_ARGS__)
#else
    #define SWARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
    #define SINFO(message, ...) \
        log_message(LOG_LEVEL_INFO, message, ##__VA_ARGS__)
#else
    #define SINFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
    #define SDEBUG(message, ...) \
        log_message(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__)
#else
    #define SDEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
    #define STRACE(message, ...) \
        log_message(LOG_LEVEL_TRACE, message, ##__VA_ARGS__)
#else
    #define STRACE(message, ...)
#endif
