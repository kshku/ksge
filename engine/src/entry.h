#pragma once

#include "application_types.h"
#include "core/logger.h"
#include "defines.h"

extern b8 create_application(Application *app_inst);

int main(int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);
    SFATAL("Test log message: %d", 42);
    SERROR("Test log message: %d", 42);
    SWARN("Test log message: %d", 42);
    SINFO("Test log message: %d", 42);
    SDEBUG("Test log message: %d", 42);
    STRACE("Test log message: %d", 42);

    Application app_inst = {0};

    if (!create_application(&app_inst)) {
        SFATAL("Could not create game!");
        return -1;
    }

    if (!app_inst.initialize || !app_inst.update || !app_inst.render
        || !app_inst.terminate) {
        SFATAL("App's function pointer must be assigned!");
        return -1;
    }

    if (!app_inst.initialize(&app_inst)) {
        SFATAL("Application initialization failed!");
        return -1;
    }

    if (!app_inst.update(&app_inst, (f32)0)) {
        SFATAL("Application update failed!");
        return -1;
    }

    app_inst.terminate(&app_inst);

    return 0;
}
