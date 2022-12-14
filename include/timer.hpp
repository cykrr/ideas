#ifndef timer_h
#define timer_h

#include "raylib.h"

class Timer {
    public:
        Timer();
        ~Timer();
        void start(double lifetime);
        bool done() const;
        double get_elapsed() const;
    private:
        double start_time = 0;
        double elapsed_time = 0;
        double lifetime;
};


#endif
