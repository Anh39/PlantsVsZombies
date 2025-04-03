#include "eventNode.h"

EventNode::EventNode() {
    this->feature = NodeFeatureMask::BASIC_NODE | NodeFeatureMask::EVENT_NODE;
    this->Name = "EventNode";
}
EventNode::~EventNode() {
    
}
void EventNode::ProcessEvent(Event* event) {

}
