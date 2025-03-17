#pragma once
#include "event.h"
#include "../dataTypes.h"


enum MouseType
{
    MouseLeft,
    MouseRight,
    MouseMiddle
};
class MouseEvent: public Event
{
public:
    MouseEvent();
    ~MouseEvent();
    MouseType type;

    bool isPressing;
    bool justPressed;
    bool justReleased;
    Vector2F position;
    static Vector2F Position();
    static MouseEvent GetEvent(MouseType type);
    static bool IsPressing(MouseType type);
    static bool JustPressed(MouseType type);
    static bool JustReleased(MouseType type);
    static void Initialize();
    static void Update();
private:
    static Vector2F _position;
    MouseEvent(MouseType type);
    static bool initialized;
    static MouseEvent leftMouseEvent;
    static MouseEvent rightMouseEvent;
    static MouseEvent middleMouseEvent;
};