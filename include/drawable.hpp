#ifndef drawable_h
#define drawable_h
#include "raylib.h"
#include <iostream>

class Drawable {
    public:
        virtual void draw() = 0;
        virtual ~Drawable(){};

        virtual bool check_collision(const Vector2 & pos) const = 0;

        const Vector2& get_position() const;
        Vector2 get_screen_position(Camera2D & cam) const;
                 virtual void  set_position(const Vector2 &pos);
                 void  set_position(int x, int y);

                 void  set_color(const Color &color);
        const   Color& get_color() const;

                 void  set_alpha(const float a);
                float  get_alpha() const;

                 void  print(std::ostream & ostream) const;

        const friend
            std::ostream& operator<<(std::ostream & ostream,
                const Drawable& drawable);
    private:
        Vector2 pos;
        Color color;
        float alpha = 0xff;

        // number of frames of the animation
        int duration = 50;
};

#endif
