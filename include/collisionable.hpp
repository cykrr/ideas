#include "raylib.h"

class Collisionable {
    public:
        virtual bool check_collision(const Vector2 & position) const = 0;
        virtual void update_collision_box() = 0;
                void draw_collision_box() const;
                Rectangle & get_collision_box();

        virtual ~Collisionable(){}
    private:
        Rectangle collision_box;
};
