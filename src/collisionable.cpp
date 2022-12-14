#include "collisionable.hpp"

void
Collisionable::draw_collision_box() const
{
    DrawRectangle(this->collision_box.x, this->collision_box.y,
            this->collision_box.width, this->collision_box.height,
            (Color) {0xff, 0xff, 0xff, 0x20} );
}

