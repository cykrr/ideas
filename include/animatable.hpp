#ifndef animatable_h
#define animatable_h
class Animatable {
    public:
        virtual void animate() = 0;
        virtual ~Animatable(){}

        void inc_frame_count();
        const int get_frame_count();


        void set_should_animate(const bool should_animate);
        const bool should_animate();

    private:
        int frame_count = 0;
        int duration = 0;
        bool b_should_animate = false;
};
#endif
