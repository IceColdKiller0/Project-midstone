#pragma once
#include <SFML/Graphics.hpp>
//#include "Circle.h"


class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	void Move(float dx, float dy) { body.move(dx, dy); }

	bool CheckCollision(Collider other, sf::Vector2f& direction, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

	/*bool circleOverlap(Circle circle, Circle circle2);
	bool circlePointOverlap(sf::Vector2f point, Circle circle);
	float distanceSquared(sf::Vector2f a, sf::Vector2f b);*/

private:
	sf::RectangleShape& body;
	//sf::CircleShape& circle;
};

