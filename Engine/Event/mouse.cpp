#include "mouse.h"
#include "../core.h"
#include <SDL2/SDL.h>
using namespace std;
MouseEvent::MouseEvent() {

}

MouseEvent::~MouseEvent() {

}

bool MouseEvent::initialized = false;
Vector2 MouseEvent::_position = Vector2(0, 0);
MouseEvent MouseEvent::leftMouseEvent = MouseEvent(MouseType::MouseLeft);
MouseEvent MouseEvent::rightMouseEvent = MouseEvent(MouseType::MouseRight);
MouseEvent MouseEvent::middleMouseEvent = MouseEvent(MouseType::MouseMiddle);

MouseEvent::MouseEvent(MouseType type) {
    this->type = type;
    this->justPressed = false;
    this->isPressing = false;
    this->justReleased = false;
}

void MouseEvent::Initialize() {
    if (!MouseEvent::initialized) {
        MouseEvent::initialized = true;
    }
}

MouseEvent MouseEvent::GetEvent(MouseType type) {
    switch (type)
    {
    case MouseType::MouseLeft:
        return MouseEvent::leftMouseEvent;
        break;
    case MouseType::MouseRight:
        return MouseEvent::rightMouseEvent;
        break;
    case MouseType::MouseMiddle:
        return MouseEvent::middleMouseEvent;
        break;
    default:
        throw runtime_error("Invalid case");
        break;
    }
}
void UpdateEvent(MouseEvent& event, bool isPressing) {
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
}
void MouseEvent::Update() {
    int x, y;
    Uint32 state = SDL_GetMouseState(&x, &y);
    UpdateEvent(MouseEvent::leftMouseEvent, state & SDL_BUTTON(SDL_BUTTON_LEFT));
    UpdateEvent(MouseEvent::rightMouseEvent, state & SDL_BUTTON(SDL_BUTTON_RIGHT));
    UpdateEvent(MouseEvent::middleMouseEvent, state & SDL_BUTTON(SDL_BUTTON_MIDDLE));
    Vector2 position = Vector2(x, y);
    MouseEvent::_position = position;
    MouseEvent::leftMouseEvent.position = MouseEvent::Position();
    MouseEvent::rightMouseEvent.position = MouseEvent::Position();
    MouseEvent::middleMouseEvent.position = MouseEvent::Position();
}
Vector2 MouseEvent::Position() {
    Vector2 absolutePosition = MouseEvent::_position;
    Vector2 scale = Scene::scale;
    absolutePosition.x /= scale.x;
    absolutePosition.y /= scale.y;
    return absolutePosition;
}
bool MouseEvent::IsPressing(MouseType type) {
    switch (type)
    {
    case MouseType::MouseLeft:
        return MouseEvent::leftMouseEvent.isPressing;
        break;
    case MouseType::MouseRight:
        return MouseEvent::rightMouseEvent.isPressing;
        break;
    case MouseType::MouseMiddle:
        return MouseEvent::middleMouseEvent.isPressing;
        break;
    default:
        return false;
        break;
    }
}
bool MouseEvent::JustPressed(MouseType type) {
    switch (type)
    {
    case MouseType::MouseLeft:
        return MouseEvent::leftMouseEvent.justPressed;
        break;
    case MouseType::MouseRight:
        return MouseEvent::rightMouseEvent.justPressed;
        break;
    case MouseType::MouseMiddle:
        return MouseEvent::middleMouseEvent.justPressed;
        break;
    default:
        return false;
        break;
    }
}
bool MouseEvent::JustReleased(MouseType type) {
    switch (type)
    {
    case MouseType::MouseLeft:
        return MouseEvent::leftMouseEvent.justReleased;
        break;
    case MouseType::MouseRight:
        return MouseEvent::rightMouseEvent.justReleased;
        break;
    case MouseType::MouseMiddle:
        return MouseEvent::middleMouseEvent.justReleased;
        break;
    default:
        return false;
        break;
    }
}