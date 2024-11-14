#pragma once

#include "defines.h"

// Enable warn, info debug trace by default
// Note: Fatal and error are always enabled
#ifndef LOG_WARN_ENABLED
    #define LOG_WARN_ENABLED 1
#endif

#ifndef LOG_INFO_ENABLED
    #define LOG_INFO_ENABLED 1
#endif

#ifndef LOG_DEBUG_ENABLED
    #define LOG_DEBUG_ENABLED 1
#endif

#ifndef LOG_TRACE_ENABLED
    #define LOG_TRACE_ENABLED 1
#endif

// Disable debug and trace in release
#ifdef S_RELEASE
    #define LOG_DEBUG_ENABLED 0
    #define LOG_TRACE_ENABLED 0
#endif

typedef enum LogLevel {
    LOG_LEVEL_FATAL,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARN,
    LOG_LEVEL_INFO,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_TRACE
} LogLevel;

b8 initializeLogger(const char *file);

void shutdownLogger();

SAPI void logMessage(LogLevel level, const char *msg, ...);

// Logging macros
#define SFATAL(msg, ...) logMessage(LOG_LEVEL_FATAL, msg, ##__VA_ARGS__)

#define SERROR(msg, ...) logMessage(LOG_LEVEL_ERROR, msg, ##__VA_ARGS__)

#define SWARN(msg, ...) logMessage(LOG_LEVEL_WARN, msg, ##__VA_ARGS__)

#define SINFO(msg, ...) logMessage(LOG_LEVEL_INFO, msg, ##__VA_ARGS__)

#define SDEBUG(msg, ...) logMessage(LOG_LEVEL_DEBUG, msg, ##__VA_ARGS__)

#define STRACE(msg, ...) logMessage(LOG_LEVEL_TRACE, msg, ##__VA_ARGS__)

#if LOG_WARN_ENABLED == 0
    #define SWARN(msg, ...)
#endif

#if LOG_INFO_ENABLED == 0
    #define SINFO(msg, ...)
#endif

#if !defined(S_DEBUG) || LOG_DEBUG_ENABLED == 0
    #define SDEBUG(msg, ...)
#endif

#if LOG_TRACE_ENABLED == 0
    #define STRACE(msg, ...)
#endif
