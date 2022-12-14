#include "timer.hpp"
#include <stdio.h>

Timer::Timer(){}
Timer::~Timer(){}

void
Timer::start(double lifetime)
{
    this->start_time = GetTime();
    this->lifetime = lifetime;
}

bool Timer::done() const
{
    bool is_done = (GetTime() - start_time) >= lifetime;
    printf("lifetime: %lf\n"
           "elapsed_time: %lf\n"
           "done: %d\n",
           lifetime, get_elapsed(), is_done);
    return is_done;
}

double Timer::get_elapsed() const
{
    return GetTime() - start_time;
}
