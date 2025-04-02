#pragma once
#include "event.h"
#include <queue>
using namespace std;
class EventQueue 
{
public:
    static void PushEvent(Event* event);
    static vector<Event*> PopAll();
    static bool IsEmpty();
private:
    EventQueue();
    static queue<Event*> events;
};