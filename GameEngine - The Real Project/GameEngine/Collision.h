#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>
#include "Circle.h"

class Collision {
public:
	Collision();
	~Collision();

	bool circleOverlap(Circle circle, Circle circle2);
	bool circlePointOverlap(sf::Vector2f point, Circle circle);
	float distanceSquared(sf::Vector2f a, sf::Vector2f b);

};

#endif