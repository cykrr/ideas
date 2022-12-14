#include "math_overloads.hpp"
Vector2 
operator+=(Vector2 & a, Vector2 b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vector2 
operator-=(Vector2 & a, Vector2 b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}


Vector2 
operator*(Vector2 & a, int b)
{
    a.x *= b;
    a.y *= b;
    return a;
}
