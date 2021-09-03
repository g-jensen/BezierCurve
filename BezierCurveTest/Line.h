#pragma once

#include <SFML/Graphics.hpp>
#include "Math.h"

class Line
{
public:
	Line(sf::Vector2f pos1, sf::Vector2f pos2);

	float lerpLength;

	sf::Vector2f getPos1();
	sf::Vector2f getPos2();
	float getLength();
	sf::VertexArray getVertexArray();
	float getAngle();

	void setPos1(sf::Vector2f position);
	void setPos2(sf::Vector2f position);
private:
	sf::VertexArray points;
	sf::Vector2f pos1;
	sf::Vector2f pos2;
	float length;
	float angle;
};

