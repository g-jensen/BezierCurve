#include "Line.h"

Line::Line(sf::Vector2f pos1, sf::Vector2f pos2)
{
	points = sf::VertexArray(sf::Lines, 2);
	this->points[0] = pos1;
	this->points[1] = pos2;
	this->pos1 = pos1;
	this->pos2 = pos2;
	float x = this->pos1.x - this->pos2.x;
	float y = this->pos1.y - this->pos2.y;
	this->length = sqrt((x * x) + (y * y));

	this->angle = acosf(
		(abs(pos1.x - pos2.x) / this->length)
	);
	angle *= 180 / M_PI;
}

sf::Vector2f Line::getPos1()
{
	return this->pos1;
}

sf::Vector2f Line::getPos2()
{
	return this->pos2;
}

float Line::getLength()
{
	return length;
}

sf::VertexArray Line::getVertexArray()
{
	return this->points;
}

float Line::getAngle()
{
	return angle;
}

void Line::setPos1(sf::Vector2f position)
{
	this->pos1 = position;
	this->points[0] = position;
	float x = pos1.x - pos2.x;
	float y = pos1.y - pos2.y;
	this->length = sqrt((x*x) + (y*y));
	this->angle = acosf(
		(abs(pos1.x - pos2.x) / this->length)
	);
	angle *= 180 / M_PI;
}

void Line::setPos2(sf::Vector2f position)
{
	pos2 = position;
	this->points[1] = position;
	float x = pos1.x - pos2.x;
	float y = pos1.y - pos2.y;
	this->length = sqrt((x * x) + (y * y));
	this->angle = acosf(
		(abs(pos1.x - pos2.x) / this->length)
	);
	angle *= 180 / M_PI;
}


