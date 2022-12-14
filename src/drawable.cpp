#include "drawable.hpp"

void
Drawable::print(std::ostream & ostream) const {
    const Vector2 & pos = this->get_position();
    ostream << "pos: (" << pos.x << ", " << pos.y << ")\n";
}

const std::ostream &
operator<<(std::ostream & ostream, const Drawable& drawable) {
    drawable.print(ostream);
    return ostream;
}

void 
Drawable::set_position(const Vector2 &pos) {
    this->pos = pos;
}

void 
Drawable::set_position(int x, int y) {
    this->pos.x = x, this->pos.y = y;

}

const Vector2 &
Drawable::get_position() const {
    return this->pos;
}


void
Drawable::set_color(const Color & color) {
    this->color = color;
}

const Color &
Drawable::get_color() const {
    return this->color;
}

float
Drawable::get_alpha() const {
    return this->alpha;
}

void Drawable::set_alpha(const float a) {
    this->alpha = a;
}


Vector2
Drawable::get_screen_position(Camera2D & cam) const
{
    return GetWorldToScreen2D(this->get_position(), cam);
}
