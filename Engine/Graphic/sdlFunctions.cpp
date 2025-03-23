#include "sdlFunctions.h"
#include <iostream>

void LogErrorAndExit(const char* msg, const char* error) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

void waitUntilKeyPressed() {
    SDL_Event e;
    while (true)
    {
        if (SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT)) {
            return;
        }
        SDL_Delay(100);
    }
}


