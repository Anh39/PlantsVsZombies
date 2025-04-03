#include "eventQueue.h"
using namespace std;
EventQueue::EventQueue() {};
queue<Event*> EventQueue::events = queue<Event*>();

void EventQueue::PushEvent(Event* event) 
{
    EventQueue::events.push(event);
}
vector<Event*> EventQueue::PopAll() 
{
    vector<Event*> result;
    while (!events.empty())
    {
        result.push_back(events.front());
        events.pop();
    }
    return result;
}

bool EventQueue::IsEmpty() {
    return EventQueue::events.empty();
}