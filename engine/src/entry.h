#pragma once

#include "application_types.h"
#include "defines.h"

// TODO: Create subsystems to replace these
#include <stdio.h>
#include <stdlib.h>

extern b8 create_application(Application *app_inst);

int main(int argc, char *argv[]) {
    Application app_inst;

    if (!create_application(&app_inst)) {
        printf("Could not create game!\n");
        return -1;
    }

    if (!app_inst.initialize || !app_inst.update || !app_inst.render
        || !app_inst.terminate) {
        printf("App's function pointer must be assigned\n");
        return -1;
    }

    if (!app_inst.initialize(&app_inst)) {
        printf("Application initialization failed\n");
        return -1;
    }

    if (!app_inst.update(&app_inst, (f32)0)) {
        printf("Application update failed\n");
        return -1;
    }

    app_inst.terminate(&app_inst);

    return 0;
}
