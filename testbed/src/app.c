#include <core/logger.h>
#include <entry.h>

typedef struct AppState {
} AppState;

b8 app_initialize(Application *app_inst) {
    UNUSED(app_inst);
    SINFO("app_initialize is called");
    return true;
}

b8 app_update(Application *app_inst, f32 delta_time) {
    UNUSED(app_inst);
    UNUSED(delta_time);
    SINFO("app_update is called");
    return true;
}

b8 app_render(Application *app_inst, f32 delta_time) {
    UNUSED(app_inst);
    UNUSED(delta_time);
    SINFO("app_render is called");
    return true;
}

void app_terminate(Application *app_inst) {
    UNUSED(app_inst);
    SINFO("app_terminate is called");
}

b8 create_application(Application *app_inst) {
    app_inst->initialize = app_initialize;
    app_inst->update = app_update;
    app_inst->render = app_render;
    app_inst->terminate = app_terminate;

    app_inst->state = NULL;

    return true;
}
