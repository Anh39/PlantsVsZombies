#pragma once

#define FPS 60

/// @class GameLoop
/// @brief https://gameprogrammingpatterns.com/game-loop.html
class GameLoop
{
public:
    /// @brief Start game, block thread
    static void Start();
    static void Stop();

    static void Pause();
    static void Resume();
    static bool IsPaused();
private:
    static bool running;
    static bool stopTime;
};