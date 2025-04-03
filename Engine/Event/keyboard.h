#pragma once
#include "event.h"
#include <map>
#include <SDL2/SDL.h>

/// @brief Enum for Key
enum KeyboardType
{
    Left,
    Right,
    Up,
    Down,
    Esc,
    Space,
    Enter,
    LShift,
    RShift,
    W,
    A,
    S,
    D,
    F1,
    F2,
    F3,
    F4,
    F5
};

/// @class KeyboardEvent
/// @brief Event of Keyboard
class KeyboardEvent: public Event
{
public:
    KeyboardEvent();
    ~KeyboardEvent();
    /// @brief Key type of Event
    KeyboardType type;
    /// @brief Is key pressing
    bool isPressing;
    /// @brief Is key just pressed, trigger once.
    bool justReleased;
    /// @brief Is key just release.
    bool justPressed;

    /// @brief Get KeyboardEvent corresponding to a Key
    static KeyboardEvent GetEvent(KeyboardType type);
    /// @brief Check if a Key is Pressing
    static bool IsPressing(KeyboardType type);
    /// @brief Check if a Key is just Released
    static bool JustReleased(KeyboardType type);
    /// @brief Check if a Key is just Pressed;
    static bool JustPressed(KeyboardType type);
    /// @brief Initialize class. Called by GameLoop.
    static void Initialize();
    /// @brief Update class. Called by GameLoop.
    static void Update();
private:
    KeyboardEvent(KeyboardType type);
    static bool initialized;
    static std::map<KeyboardType, KeyboardEvent> events;
    static std::map<SDL_Scancode, KeyboardType> keyMap;
};