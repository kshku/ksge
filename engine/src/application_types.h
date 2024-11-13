#pragma once

#include "defines.h"

typedef struct Application {
        // Function pointer to app's initialize function
        b8 (*initialize)(struct Application *app_inst);

        // Function pointer to app's update function
        b8 (*update)(struct Application *app_inst, f32 detla_time);

        // Function pointer to app's render function
        b8 (*render)(struct Application *app_inst, f32 delta_time);

        // Function pointer to app's terminate function
        void (*terminate)(struct Application *app_inst);

        // App specific state. Created and managed by app.
        void *state;
} Application;
