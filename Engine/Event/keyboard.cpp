#include "keyboard.h"
#include <iostream>
#include <SDL2/SDL.h>


KeyboardEvent::~KeyboardEvent() {

}
KeyboardEvent::KeyboardEvent() {

}

bool KeyboardEvent::initialized = false;

KeyboardEvent::KeyboardEvent(KeyboardType type) {
    this->type = type;
    this->isPressing = false;
    this->justPressed = false;
    this->justReleased = false;
}
map<KeyboardType, KeyboardEvent> KeyboardEvent::events = map<KeyboardType, KeyboardEvent>();
map<SDL_Scancode, KeyboardType> KeyboardEvent::keyMap = {
    {SDL_SCANCODE_RIGHT, KeyboardType::Right},
    {SDL_SCANCODE_LEFT, KeyboardType::Left},
    {SDL_SCANCODE_UP, KeyboardType::Up},
    {SDL_SCANCODE_DOWN, KeyboardType::Down},
    {SDL_SCANCODE_ESCAPE, KeyboardType::Esc},
    {SDL_SCANCODE_SPACE, KeyboardType::Space},
    {SDL_SCANCODE_KP_ENTER, KeyboardType::Enter},
    {SDL_SCANCODE_LSHIFT, KeyboardType::LShift},
    {SDL_SCANCODE_RSHIFT, KeyboardType::RShift},
    {SDL_SCANCODE_W, KeyboardType::W},
    {SDL_SCANCODE_D, KeyboardType::D},
    {SDL_SCANCODE_S, KeyboardType::S},
    {SDL_SCANCODE_A, KeyboardType::A},
    {SDL_SCANCODE_F1, KeyboardType::F1},
    {SDL_SCANCODE_F2, KeyboardType::F2},
    {SDL_SCANCODE_F3, KeyboardType::F3},
    {SDL_SCANCODE_F4, KeyboardType::F4},
    {SDL_SCANCODE_F5, KeyboardType::F5}
};

void KeyboardEvent::Initialize() {
    if (!KeyboardEvent::initialized) {
        KeyboardEvent::initialized = true;
        for(const auto& [key, type]: KeyboardEvent::keyMap) {
            KeyboardEvent newEvent = KeyboardEvent(type);
            events[type] = newEvent;
        }
    }
}

KeyboardEvent KeyboardEvent::GetEvent(KeyboardType type) {
    return KeyboardEvent::events[type];
}
KeyboardEvent updateEvent(map<KeyboardType, KeyboardEvent> &events, KeyboardType type, bool isPressing) {
    KeyboardEvent event = events[type];
    if (isPressing) {
        if (!event.isPressing) {
            event.justReleased = false;
            event.justPressed = true;
        } else {
            event.justPressed = false;
        }
        event.isPressing = true;
    } else {
        if (event.isPressing) {
            event.justPressed = false;
            event.justReleased = true;
        } else {
            event.justReleased = false;
        }
        event.isPressing = false;
    }
    return event;
}
void KeyboardEvent::Update() {
    const Uint8* keyStates = SDL_GetKeyboardState(NULL);
    for(const auto& [key, type]: KeyboardEvent::keyMap) {
        KeyboardEvent::events[type] = updateEvent(KeyboardEvent::events, type, keyStates[key]);
    }
}
bool KeyboardEvent::IsPressing(KeyboardType type) {
    KeyboardEvent event = GetEvent(type);
    return event.isPressing;
}
bool KeyboardEvent::JustPressed(KeyboardType type) {
    KeyboardEvent event = GetEvent(type);
    return event.justPressed;
}
bool KeyboardEvent::JustReleased(KeyboardType type) {
    KeyboardEvent event = GetEvent(type);
    return event.justReleased;
}