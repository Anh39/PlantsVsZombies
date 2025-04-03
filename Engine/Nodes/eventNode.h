#pragma once

#include "../core.h"
#include "../event.h"

/// @class EventNode
/// @brief Node that process Event
class EventNode: public Node
{
public:
    EventNode();
    ~EventNode();
    /// @brief Process events in this frame
    virtual void ProcessEvent(Event* event);
};