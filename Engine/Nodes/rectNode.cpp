#include "rectNode.h"

RectNode::RectNode() {
    this->Name = "RectNode";
    this->size = Vector2(0, 0);
}
RectNode::~RectNode() {

}
Rect RectNode::GetRect() {
    return Rect(this->position.x, this->position.y, this->size.x, this->size.y);
}
void RectNode::SetRect(const Rect& rect) {
    this->position.x = rect.x;
    this->position.y = rect.y;
    this->size.x = rect.w;
    this->size.y = rect.h;
}