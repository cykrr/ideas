#include <stdexcept>

#include "animation.hpp"

Animation::Animation(
            // Animation function
            float (*animation)(float, float, float, float),
            // variable to animate
            float * parameter,
            // duration of the animation
            float start, float end, 
            int duration
        ) {
    this->animation = animation;
    this->parameter = parameter;
    this->duration = duration;

    this->start = start;
    this->end = end;

    
}

void
Animation::run()
{
    if (!this->parameter) throw std::runtime_error("Null parameter");

    this->frame_count++;

    *(this->parameter) = this->animation(this->frame_count,
            this->start, this->end, duration);
    // printf("Animating %f\n", *this->parameter);
} 

bool 
Animation::is_over()
{
    if (this->frame_count < duration) return false;
    return true;
}
