#include "engine.h"

#include "logger.h"

typedef struct EngineState {
        b8 is_running;
        Application *app_inst;
} EngineState;

static EngineState engine_state;

/**
 * @brief Initialize the engine.
 *
 * This will also initialize subsystems and will call initialize on application.
 *
 * @param app_inst Pointer to the Application instance
 *
 * @return true if engine was initialized successfully.
 *
 * @note If some of the subsystem, like logger, failed to initialize, it is not
 * conidered as failure to initialize engine. In such cases an error message
 * will be given and this function returns true.
 */
b8 initializeEngine(Application *app_inst) {
    if (engine_state.is_running) {
        // Engine is already running, so we had initialized logger.
        SERROR("Engine is already running, but initializeEngine called again.");
        return false;
    }

    // TODO: specify the log file (platform specific)
    if (!initializeLogger("log.txt")) {
        // Even if initialize is failed, messages will be logged to the stdout
        // or stderr
        SERROR("Failed to initialize logger");
    }

    engine_state.is_running = true;
    engine_state.app_inst = app_inst;

    // Should be called at last, i.e., after initializing subsystems
    if (!engine_state.app_inst->initialize(engine_state.app_inst)) {
        SFATAL("Application initialization failed!");
        return false;
    }

    return true;
}

/**
 * @brief Shutdown the engine.
 */
void shutdownEngine() {
    // Should be called first, i.e., before terminating subsystems
    engine_state.app_inst->terminate(engine_state.app_inst);

    shutdownLogger();
}

/**
 * @brief Main loop for the application.
 *
 * @return true if terminated normally, false if terminated abnormally.
 */
b8 engineRun() {
    b8 ret_val = true;
    while (engine_state.is_running) {
        if (!engine_state.app_inst->update(engine_state.app_inst, (f32)0)) {
            SFATAL("Application update failed!");
            ret_val = false;
            // TODO: Yet to decide how to terminate main loop
            // NOTE: For now using break
            // engine_state.is_running = false;
            break;
        }
        engine_state.is_running = false;
    }

    return ret_val;
}
