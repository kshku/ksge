#include <core/asserts.h>
#include <core/logger.h>

int main() {
    SFATAL("Test message fatal: %d", 42);
    SERROR("Test message error: %d", 42);
    SWARN("Test message warn: %d", 42);
    SINFO("Test message info: %d", 42);
    SDEBUG("Test message debug: %d", 42);
    STRACE("Test message trace: %d", 42);
}
