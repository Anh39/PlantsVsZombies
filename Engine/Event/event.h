#pragma once


/// @class Event
/// @brief Base class for Event
class Event
{
public:
    bool handled = false;
    virtual ~Event();
};
