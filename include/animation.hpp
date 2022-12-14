#ifndef animation_h
#define animation_h

class Animation
{
public:
    Animation(
            // Animation function
            float (*animation)(float t, float b, float c, float d),
            // variable to animate
            float * parameter,
            float start, float end,
            // duration of the animation
            int duration);

    void run(); // execute the animation

    bool is_over();

    ~Animation(){};
private:
    float (*animation)(float t, float b, float c, float d);
    float * parameter;

    int duration;

    int frame_count = 0;

    float start = 0, end = 0; // start and end values

};

#endif // !animation_h
