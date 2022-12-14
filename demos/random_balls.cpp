#include "ball.hpp"
#include "drawable.hpp"
#include "drawable_collection.hpp"
#include "timer.hpp"
#include "util.h" 
#include "colors.h" 

int
main()
{

    DrawableCollection<Ball> drawables;
    Timer t;
    Vector2 screen = {0};
    double timer_duration = 0.0;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(720, 1280, "draw");
    SetTargetFPS(60);
    t.start(timer_duration);

    while (!WindowShouldClose())
    {
        if (IsWindowResized()) {
            screen.x = GetScreenWidth();
            screen.y = GetScreenHeight();
        }
        if (t.done()) {
            const Vector2 rand_pos = {
                (float)random_number(0, screen.x),
                (float)random_number(0, screen.y)
            };

            drawables.insert_element(
                    new Ball(rand_pos, COLOR_RANDOM, random_number(10, 50))
                    );

            t.start(timer_duration);
        }
        BeginDrawing();
            ClearBackground(COLOR_WHITE);
            drawables.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
