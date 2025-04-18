#include "bucketZombie.h"

BucketZombie::BucketZombie() {
    this->Name = "BucketZombie";
    this->colorRect->color = Color(100, 100, 100); // Màu xám
}

BucketZombie::~BucketZombie() {
}

BaseZombie* BucketZombie::Copy() {
    return new BucketZombie(*this);
}
