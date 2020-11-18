#include "Collision.h"

Collision::Collision() {}

Collision::~Collision() {}

bool Collision::circleOverlap(Circle circle1, Circle circle2) {
	float distance = distanceSquared(circle1.getPos(), circle2.getPos());
	float radiusSum = circle1.getR() + circle2.getR();

	return distance <= radiusSum * radiusSum;
}

bool Collision::circlePointOverlap(sf::Vector2f point, Circle circle) {
	float distance = distanceSquared(circle.getPos(), point);
	return distance < circle.getR()* circle.getR();
}

float Collision::distanceSquared(sf::Vector2f a, sf::Vector2f b) {
	float distX = a.x - b.x;
	float distY = a.y - b.y;
	return distX * distX + distY * distY;
}