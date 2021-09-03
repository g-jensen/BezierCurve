#include "Math.h"

sf::Vector2f Math::getCoordsToDrawLine(float x, float y, float distance, float angle)
{
    sf::Vector2f vec;
    float new_x = (cosf((angle * -1) * (M_PI / 180)) * distance) + x;
    float new_y = (sinf((angle * -1) * (M_PI / 180)) * distance) + y;
    vec.x = (new_x);
    vec.y = (new_y);
    return vec;
}

float Math::Length(sf::Vector2f v1, sf::Vector2f v2)
{
    float x = v1.x - v2.x;
    float y = v1.y - v2.y;
    return sqrt((x*x) + (y*y));
}
