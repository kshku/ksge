#include "logger.h"

#include <stdarg.h>
#include <stdio.h>

static const char *log_level_strings[] = {
    "[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};

/**
 * @brief Initializes the logger
 *
 * @param file The file to log to
 *
 * @return true if the logger was initialized successfully
 */
b8 initialize_logger(const char *file) {
    UNUSED(file);
    // TODO: Logging to file, aynchronous logging, etc.
    return true;
}

/**
 * @brief Shuts down the logger
 */
void shutdown_logger() {
}

/**
 * @brief Logs a message
 *
 * @param level Log level (one of the values of enum LogLevel)
 * @param msg Format string message
 * @param ... Arguments for the format string
 */
void log_message(LogLevel level, const char *msg, ...) {
    // TODO: Log to file, timestamp, etc.
    // TODO: Also while logging to console colored ouput (platform specific)

    va_list args;
    va_start(args, msg);

    printf("%s", log_level_strings[level]);
    vprintf(msg, args);
    printf("\n");

    va_end(args);
}
