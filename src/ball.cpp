#include "ball.hpp"

Ball::Ball(const Vector2 & pos, const Color & color, float radius) {
    this->radius = radius;
    this->animation = new Animation(&EaseBounceOut, &(this->draw_radius), 0,
            this->radius, 50);

    set_position(pos);
    set_color(color);
}


void 
Ball::draw()
{
    const Vector2 & pos = get_position();

    if (!this->animation->is_over()) this->animation->run();

    DrawCircle(pos.x, pos.y,
            this->draw_radius, this->get_color());
}

Ball::~Ball() {

}

void Ball::print(std::ostream & ostream) const {
    ostream << "ball_radius: " << this->draw_radius << "\n"; 
}


const std::ostream &
operator<<(std::ostream & ostream, const Ball& ball) {
    ball.print(ostream);
    return ostream;
}


bool
Ball::check_collision(const Vector2 & pos) const
{
    return CheckCollisionPointCircle(pos, this->get_position(), this->radius);
}


float
Ball::get_radius() const
{
    return this->radius;
}



