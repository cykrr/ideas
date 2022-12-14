#ifndef ball_h
#define ball_h

#include "raylib.h"
#include "reasings.h"

#include "drawable.hpp"
#include "animatable.hpp"
#include "animation.hpp"
#include <cstdio>

class Ball : public Drawable {
    public:
        Ball(const Color & color);
        Ball(const Vector2 & position, const Color & color, float radius);
        ~Ball();

        void draw() override;

        bool check_collision(const Vector2 & position) const override;

        const friend std::ostream& operator<<(std::ostream & ostream, const Ball& ball);
        void print(std::ostream & ostream) const;

        float get_radius() const;

        bool remove = false;

    protected:
        float radius; // Ball apparent radius
        float draw_radius; // Actual radius: used for animations
        bool visible = true;
        Animation *animation;
};

#endif
