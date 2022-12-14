#include "raylib.h"

#include "raymath.h"
#include "math_overloads.hpp"


#include "ball.hpp"
#include "text_ball.hpp"
#include "drawable_collection.hpp"
#include "colors.h"

#include "raylib-cpp.hpp"


void loop(raylib::Window & window);


int main()
{
    raylib::Window window(1280, 720, "demo");
        SetTargetFPS(60);
        SetMouseCursor(MOUSE_CURSOR_CROSSHAIR);
    loop(window);
}

void 
loop(raylib::Window & window) {
    DrawableCollection<TextBall> balls;
    int cursor = (MOUSE_CURSOR_CROSSHAIR); // Mouse icon
    Ball *last_over_ball = NULL; // Last hovered ball
    raylib::Vector2 offset = {0}; // Ball offset from center
    raylib::Vector2 screen = {1280, 720};
    raylib::Camera2D camera(screen/2, {0, 0}, 0, 1);
    TextBall ball(screen/2, COLOR_GREY, 50);
    ball.update();

    while(!window.ShouldClose())
    {
        raylib::Vector2 mouse_position = raylib::Mouse::GetPosition();
        raylib::Vector2 mouse_delta = raylib::Mouse::GetDelta();
        raylib::Vector2 world_position = 
            camera.GetScreenToWorld(mouse_position);
        raylib::Vector2 mouse_wheel_move = raylib::Mouse::GetWheelMoveV();

        camera.target = world_position;
        camera.offset = world_position;

        window.BeginDrawing();
        ClearBackground(COLOR_WHITE);
        camera.BeginMode();
            balls.draw();
            ball.draw();
        camera.EndMode();

        if (window.IsResized())
            screen = window.GetSize();

        bool shift = IsKeyDown(KEY_LEFT_SHIFT);
        if (shift) cursor = MOUSE_CURSOR_POINTING_HAND;
        int gesture = GetGestureDetected();

        Ball *over_ball = balls.check_collision(world_position);


        printf("offset %f, %f\n", camera.offset.x, camera.offset.y);
        printf("target %f, %f\n", camera.target.x, camera.target.y);


        DrawCircle(camera.offset.x, camera.offset.y, 5, COLOR_RED);

        if (shift) {
            camera.zoom += mouse_wheel_move.y * 0.08;
        }



        if (mouse_delta.Length() > 0 &&
            (gesture == GESTURE_HOLD)) {
                gesture = GESTURE_DRAG;
        }


        switch (gesture)
        {
            case GESTURE_DOUBLETAP:
            case GESTURE_TAP:
                if (!over_ball && !shift)
                    over_ball = balls.insert_element(
                            new TextBall(world_position, COLOR_GREY, 50)
                            );
                else if (shift && over_ball) {
                    over_ball->remove = true;
                }

                break;
            case GESTURE_HOLD:

                if (over_ball)
                {
                    offset = mouse_position - 
                        over_ball->get_screen_position(camera);

                    DrawLine(
                            over_ball->get_screen_position(camera).x,
                            over_ball->get_screen_position(camera).y,
                            over_ball->get_screen_position(camera).x + offset.x,
                            over_ball->get_screen_position(camera).y + offset.y,
                            COLOR_RED);
                }
                    break;
            case GESTURE_DRAG:
                // if (!over_ball && last_over_ball) over_ball = last_over_ball;
                if (over_ball)
                {
                    cursor = (MOUSE_CURSOR_POINTING_HAND);
                    over_ball->set_position(camera.GetScreenToWorld(mouse_position - offset));
                }
                if (shift) camera.target -= raylib::Mouse::GetDelta();

            case GESTURE_NONE:
                if (over_ball && cursor != MOUSE_CURSOR_POINTING_HAND)
                {
                    cursor = (MOUSE_CURSOR_IBEAM);
                    last_over_ball = over_ball;
                }
            
                else  if (!over_ball)
                    cursor = (MOUSE_CURSOR_CROSSHAIR);
                break;
        }
        SetMouseCursor(cursor);
        window.EndDrawing();
    }
}
