#include "Circle.h"

Circle::Circle(float r) : _pull(false), mass(r * 20.f), circleShape(sf::CircleShape(r)) {
	circleShape.setFillColor(sf::Color::Green);
	circleShape.setOrigin(40, 60);
}

Circle::~Circle() {}

void Circle::update(float deltatime) {
	
	Acceleration(-getVel().x * 0.9f * deltatime, -getVel().y * 0.9f * deltatime);
	Velocity(getVel().x + (getAcc().x), getVel().y + (getAcc().y));

	circleShape.move(getVel());

	circleShape.rotate(10 * deltatime * 10);

	//circleShape.move();

	if (getPos().x < getR()) {
		Position(getR(), getPos().y);
		Velocity(-getVel().x, getVel().y);
		//Gravity(getPos().x, getPos().y);
	}
	else if (getPos().x > 1000 - getR()) {
		Position(1000 - getR(), getPos().y);
		Velocity(-getVel().x, getVel().y);
		//Gravity(getPos().x, getPos().y);
	}

	if (getPos().y < getR()) {
		Position(getPos().x, getR());
		Velocity(getVel().x, -getVel().y);
		//Gravity(getPos().x, getPos().y);
	}
	else if (getPos().y > 600 - getR()) {
		Position(getPos().x, 600 - getR());
		Velocity(getVel().x, -getVel().y);
		//Gravity(getPos().x, getPos().y);
	}
}

void Circle::draw(sf::RenderWindow& window) {
	window.draw(circleShape);
}

void Circle::Position(float x, float y) {
	this->circleShape.setPosition(sf::Vector2f(x, y));
}

float Circle::getR() const {
	return circleShape.getRadius();
}

sf::Vector2f Circle::getPos() const {
	return circleShape.getPosition();
}

void Circle::Velocity(float x, float y) {

	//x = -0.1;
	//y = -0.1;
	this->velocity = sf::Vector2f(x, y);
}

void Circle::Acceleration(float x, float y) {

	//x = -9.8;
	//y = -9.8;
	this->acceleration = sf::Vector2f(x, y);
}

void Circle::setPull(bool pull) {
	this->_pull = pull;
}

float Circle::getMass() const {
	return mass;
}

float Circle::getPull() const {
	return _pull;
}

sf::Vector2f Circle::getVel() const {
	return velocity;
}

sf::Vector2f Circle::getAcc() const {
	return acceleration;
}
