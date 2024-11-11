#include "logger.h"

#include <stdarg.h>
#include <stdio.h>

#include "asserts.h"

b8 initialize_logging() {
    // Todo: Writing to a log file
    return true;
}

void shutdown_logging() {
    // Todo: Cleaning up things
}

void log_message(LogLevel level, const char *message, ...) {
    const char *log_header[] = {
        "[FATAL]: ", "[ERROR]: ", "[WARN]: ",
        "[INFO]: ",  "[DEBUG]: ", "[TRACE]: ",
    };
    va_list args;
    va_start(args, message);
    // Todo: Platform specific logging with colored output
    printf("%s", log_header[level]);
    vprintf(message, args);
    printf("\n");
    va_end(args);
}

void assertion_failure(const char *expression, const char *message,
                       const char *file, i32 line) {
    log_message(LOG_LEVEL_FATAL,
                "Assertion Failure: %s, message: '%s', in file: %s, line: %d",
                expression, message, file, line);
}
