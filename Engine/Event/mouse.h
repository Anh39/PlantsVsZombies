#pragma once
#include "event.h"
#include "../dataTypes.h"

/// @brief Enum for MouseKey
enum MouseType
{
    MouseLeft,
    MouseRight,
    MouseMiddle
};
/// @class MouseEvent
/// @brief Event of Mouse
class MouseEvent: public Event
{
public:
    MouseEvent();
    ~MouseEvent();
    /// @brief Mouse type of Event
    MouseType type;

    /// @brief Is mouse pressing.
    bool isPressing;
    /// @brief Is mouse just pressed. Trigger once.
    bool justPressed;
    /// @brief Is mouse just released.
    bool justReleased;
    /// @brief Position of mouse, share all cross all instance
    Vector2 position;
    /// @brief Get position of mouse.
    static Vector2 Position();
    /// @brief Get MouseEvent corresponding to a Type
    static MouseEvent GetEvent(MouseType type);
    /// @brief Check if Mouse is Pressing
    static bool IsPressing(MouseType type);
    /// @brief Check if Mouse is just Pressed
    static bool JustPressed(MouseType type);
    /// @brief Check if Mouse is jus Released
    static bool JustReleased(MouseType type);
    /// @brief Initialize class. Called by GameLoop
    static void Initialize();
    /// @brief Update class. Called by GameLoop
    static void Update();
private:
    static Vector2 _position;
    MouseEvent(MouseType type);
    static bool initialized;
    static MouseEvent leftMouseEvent;
    static MouseEvent rightMouseEvent;
    static MouseEvent middleMouseEvent;
};