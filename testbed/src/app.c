#include <entry.h>

// TODO: Use logger
#include <stdio.h>

typedef struct AppState {
} AppState;

b8 app_initialize(Application *app_inst) {
    printf("app_initialize is called\n");
    return true;
}

b8 app_update(Application *app_inst, f32 delta_time) {
    printf("app_update is called\n");
    return true;
}

b8 app_render(Application *app_inst, f32 delta_time) {
    printf("app_render is called\n");
    return true;
}

void app_terminate(Application *app_inst) {
    printf("app_terminate is called\n");
}

b8 create_application(Application *app_inst) {
    app_inst->initialize = app_initialize;
    app_inst->update = app_update;
    app_inst->render = app_render;
    app_inst->terminate = app_terminate;

    app_inst->state = NULL;

    return true;
}
