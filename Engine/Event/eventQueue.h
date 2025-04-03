#pragma once
#include "event.h"
#include <queue>

/// @class EventQueue
/// @brief Static class for manage Events (except Keyboard and Mouse events)
class EventQueue 
{
public:
    /// @brief Add new event to Queue
    static void PushEvent(Event* event);
    /// @brief Get and pop all event in this frame
    static std::vector<Event*> PopAll();
    /// @brief Check if Queue is empty
    static bool IsEmpty();
private:
    EventQueue();
    static std::queue<Event*> events;
};