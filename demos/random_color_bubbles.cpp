#include "raylib.h"
#include <iostream>


#include "colors.h"

#include "drawable.hpp"
#include "drawable_collection.hpp"

#include "ball.hpp"
#include "util.h"

#include "timer.hpp"



int main(void)
{
    // Initialization
    srand(time(NULL));

    int screenWidth = 800;
    int screenHeight = 450;

    DrawableCollection<Ball> balls;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(screenWidth, screenHeight, "new");

    Vector2 touchPosition = { 0, 0 };

    // Rectangle touchArea = { 220, 10,
    //     screenWidth - 230.0f, screenHeight - 20.0f };

    int currentGesture = GESTURE_NONE;
    float deltaAccumulation = 0;
    bool consumeGesture = false;
    int prevGesture = GESTURE_NONE;


    // Enable only some gestures to be detected
    //SetGesturesEnabled(0b0000000000001001);   

    SetTargetFPS(60);  // Set our game to run at 60 frames-per-second

    // int state = 1;
    // int framesCounter = 0;

    Vector2 offset = {0};
    Ball * touched = NULL;
    Ball * lastTouched = NULL;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Handle window resize
        if (IsWindowResized()) {
            screenWidth = GetScreenWidth();
            screenHeight = GetScreenHeight();
        }

        // Update
        currentGesture = GetGestureDetected();
        touchPosition = GetTouchPosition(0);
        // printf("double_click count: %ld\n", balls.size());


        switch (GetKeyPressed()) {
            case KEY_R:
                balls.clear();
            break;
            case KEY_Q:
                CloseWindow();
                return 0;
            break;
        }

        BeginDrawing();
            ClearBackground((Color){0x20, 0x20, 0x20, 0xff});
            balls.draw();

                touched = (Ball*)balls.check_collision(touchPosition);


            switch (currentGesture)
            {
                case GESTURE_TAP: // 1
                case GESTURE_DOUBLETAP: // 2
                    if (!touched)
                        touched = balls.insert_element(new Ball(touchPosition, COLOR_RANDOM, 50));
                case GESTURE_HOLD: // 4
                    if (!touched) touched = lastTouched;

                    offset = {
                        touchPosition.x - touched->get_position().x,
                        touchPosition.y - touched->get_position().y,
                    };

                    DrawLine(touched->get_position().x, touched->get_position().y,
                            touched->get_position().x + offset.x,
                            touched->get_position().y + offset.y, COLOR_RED);
                    break;
                case GESTURE_DRAG: // 8
                    if (!touched) touched = lastTouched;
                    touched->set_position(touchPosition.x - offset.x, touchPosition.y - offset.y);
                case GESTURE_NONE: // 0
                    if (currentGesture != prevGesture) printf("%d\n", currentGesture);
                default:
                    prevGesture = currentGesture;
                    if (touched) lastTouched = touched;
            }
            balls.update();
        EndDrawing();
    }
    CloseWindow();        // Close window and OpenGL context
}
