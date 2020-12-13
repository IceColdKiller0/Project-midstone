#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>

class Circle {

public:
	Circle(float r);
	~Circle();

	void update(float deltatime);
	void draw(sf::RenderWindow& window);

	void Position(float x, float y);
	void setPull(bool pull);
	void Acceleration(float x, float y);
	void Velocity(float x, float y);

	//void Gravity();
	//void Gravity(float x, float y);

	sf::Vector2f getVel() const;
	sf::Vector2f getAcc() const;
	float getPull() const;
	float getMass() const;
	float getR() const;
	sf::Vector2f getPos() const;
	//void setVelocity()
	

private:
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::CircleShape circleShape;

	bool _pull;
	float mass;
	float gravity = 9.8f;
};

#endif

