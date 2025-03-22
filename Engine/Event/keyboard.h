#pragma once
#include "event.h"
#include <map>
#include <SDL2/SDL.h>

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
    F1
};
class KeyboardEvent: public Event
{
public:
    KeyboardEvent();
    ~KeyboardEvent();
    KeyboardType type;
    bool isPressing;
    bool justReleased;
    bool justPressed;

    static KeyboardEvent GetEvent(KeyboardType type);
    static bool IsPressing(KeyboardType type);
    static bool JustReleased(KeyboardType type);
    static bool JustPressed(KeyboardType type);
    static void Initialize();
    static void Update();
private:
    KeyboardEvent(KeyboardType type);
    static bool initialized;
    static map<KeyboardType, KeyboardEvent> events;
    static map<SDL_Scancode, KeyboardType> keyMap;
};