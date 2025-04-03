#include "renderNode.h"

RenderNode::RenderNode() {
    this->feature = NodeFeatureMask::BASIC_NODE | NodeFeatureMask::RENDER_NODE;
    this->Name = "RenderNode";
}
RenderNode::~RenderNode() {

}
void RenderNode::Draw(Renderer* renderer, Vector2 absolutePosition) {

}