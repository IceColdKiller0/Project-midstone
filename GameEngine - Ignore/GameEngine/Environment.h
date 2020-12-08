#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include "Circle.h"
#include "Collision.h"

class Environment {
public:
	Environment();
	~Environment();

	void initCircles(size_t size);
	void update(float deltatime);

	void CircleCollision();
	void setPullVel(float x, float y);
	bool _pullCircle(sf::Vector2f point);

	Circle* getPullCircle() const;
	std::vector<Circle> getCircles() const;

private:
	std::vector<Circle> circles;

	Circle* pullCircles;
	Collision collision;
};

#endif

