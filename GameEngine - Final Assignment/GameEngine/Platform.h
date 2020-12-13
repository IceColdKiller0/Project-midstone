#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Platform
{
public:
	Platform(sf::Color texture, sf::Vector2f size, sf::Vector2f position);
	~Platform();

	//void Update(float deltatime);

	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

	void OnCollision(sf::Vector2f direction);

	

private:
	sf::RectangleShape body;
	sf::CircleShape circle;
	sf::Vector2f velocity;

	const float gravity = 0.3f;
	int groundHeight;
};

