#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Player
{
public:
	Player(sf::Color playerTexture, float moveSpeed, float jumpSpeed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::FloatRect getGlobalBounds() { return body.getGlobalBounds(); }


	//sf::Vector2f GetPosition() { return circle.getPosition(); }

	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
	//sf::CircleShape circle;
	//unsigned int row;
	//float speed;
	//bool faceRight;

	sf::Vector2f velocity;
	bool canJump;
	//float jumpHeight;

	float moveSpeed, jumpSpeed;

	const float gravity = 0.3f;
	int groundHeight;
	//sf::Vector2f velocity(sf::Vector2f(0.0f, 0.0f));
};

