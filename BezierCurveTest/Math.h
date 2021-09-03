#pragma once

#include <SFML/System/Vector2.hpp>
#include <cmath>
// #include <math.h>
#define M_PI 3.14159265358979323846

class Math
{
public:
	static sf::Vector2f getCoordsToDrawLine(float x, float y, float distance, float angle);
	static float Length(sf::Vector2f v1, sf::Vector2f v2);
};

