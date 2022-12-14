#include "animatable.hpp"

const int Animatable::get_frame_count() {
    return this->frame_count;
}

void Animatable::inc_frame_count() {
    this->frame_count++;
}

void Animatable::set_should_animate(const bool should_animate) {
    this->b_should_animate = should_animate;
}

const bool Animatable::should_animate() {
    return this->b_should_animate;
}

