#ifndef text_ball_h
#define text_ball_h
#include "raylib-cpp.hpp"
#include "ball.hpp"

class TextBall : public Ball
{
    public:
        TextBall(const Vector2 & pos, const Color & color, float radius);
        ~TextBall(){};
        void update();
        void draw() override;
        void set_position(const Vector2 & pos) override;
    private:
        raylib::Rectangle text_box;
        raylib::Rectangle & get_text_box();
        const raylib::Rectangle & peak_text_box() const;

};
#endif
