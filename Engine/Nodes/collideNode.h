#pragma once
#include "rectNode.h"
/// @brief Mask for collision handling
enum CollideMask 
{
    CollideLayer1 = 0b1,
    CollideLayer2 = 0b10,
    CollideLayer3 = 0b100,
    CollideLayer4 = 0b1000,
    CollideLayer5 = 0b10000,
    CollideLayer6 = 0b100000,
    CollideLayer7 = 0b1000000,
    CollideLayer8 = 0b10000000
};

/// @class CollideNode
/// @brief Node that process Collide
class CollideNode: public RectNode
{
public:
    /// @brief Mask which Node this should collide with
    unsigned int collideMask = 0;
    /// @brief Filter which Mask this Node should being interacte with
    unsigned int collideFilter = 0;

    CollideNode();
    ~CollideNode();

    /// @brief On collide with other node.
    virtual void OnCollide(CollideNode* other);
    /// @brief On collided with other node.
    virtual void OnCollided(CollideNode* other);
};