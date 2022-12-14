#include "text_ball.hpp"
#include "colors.h"

const raylib::Rectangle &
TextBall::peak_text_box() const
{
    return this->text_box;
}

raylib::Rectangle &
TextBall::get_text_box() 
{
    return this->text_box;
}

void
TextBall::update()
{
    raylib::Rectangle & text_box = this->get_text_box();
    text_box.x = this->get_position().x - this->draw_radius*sqrt(2)/2;
    text_box.y = this->get_position().y - this->draw_radius*sqrt(2)/2;
    if (!this->animation->is_over()) 
    {
        text_box.width = this->draw_radius * sqrt(2);
        text_box.height = this->draw_radius * sqrt(2);
    }
}

void
TextBall::draw()
{   
    Ball::draw();
    const raylib::Rectangle & text_box = this->peak_text_box();
    if (!this->animation->is_over()) {
        this->update();
    }
    text_box.Draw((raylib::Color(255,255,255,60)));
    
}

TextBall::TextBall(const Vector2 & pos, const Color & color, float radius) 
    : Ball(pos, color, radius)
{
    raylib::Rectangle & text_box = this->get_text_box();
    text_box.width = this->draw_radius * sqrt(2);
    text_box.height = this->draw_radius * sqrt(2);
    this->update();
}

void
TextBall::set_position(const Vector2 & pos)
{
    Ball::set_position(pos);
    this->update();
}
