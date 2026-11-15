#include <jni.h>
#include <android/sensor.h>
#include <android/log.h>
#include <android_native_app_glue.h>
#include "Core/GameManager.cpp"

#define LOG_TAG "AngryTuxEngine"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

struct Engine {
    struct android_app* app;
    GameManager* gameManager;
    bool animating;
};

static void engine_handle_cmd(struct android_app* app, int32_t cmd) {
    struct Engine* engine = (struct Engine*)app->userData;
    switch (cmd) {
        case APP_CMD_INIT_WINDOW:
            if (engine->app->window != NULL) {
                LOGI("AngryTux OpenGL window initialized successfully!");
                engine->animating = true;
            }
            break;
        case APP_CMD_TERM_WINDOW:
            engine->animating = false;
            break;
    }
}

void android_main(struct android_app* state) {
    struct Engine engine;
    memset(&engine, 0, sizeof(engine));
    state->userData = &engine;
    state->app = state;
    state->onAppCmd = engine_handle_cmd;

    engine.gameManager = new GameManager();
    engine.animating = true;

    while (1) {
        int ident;
        int events;
        struct android_poll_source* source;

        while ((ident = ALooper_pollAll(engine.animating ? 0 : -1, NULL, &events,
                                      (void**)&source)) >= 0) {
            if (source != NULL) {
                source->process(state, source);
            }
            if (state->destroyRequested != 0) {
                delete engine.gameManager;
                return;
            }
        }

        if (engine.animating) {
            engine.gameManager->updatePhysics(0.016f);
        }
    }
}
