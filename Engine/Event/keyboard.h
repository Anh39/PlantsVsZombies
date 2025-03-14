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
    D
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

    static KeyboardEvent getEvent(KeyboardType type);
    static bool isPressed(KeyboardType type);
    static void Initialize();
    static void Update();
private:
    KeyboardEvent(KeyboardType type);
    static bool initialized;
    static map<KeyboardType, KeyboardEvent> events;
    // static const KeyboardType types[NUM_TYPES];
    static map<SDL_Scancode, KeyboardType> keyMap;
};