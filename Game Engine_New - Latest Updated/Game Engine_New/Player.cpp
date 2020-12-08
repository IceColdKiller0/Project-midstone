#include "Player.h"

Player::Player(sf::Texture* texture, float speed, float jumpHeight)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(30.0f, 30.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(100.0f, 500.0f);
	body.setTexture(texture);
	//body.scale(0.8f, 0.8f);
	//body.setScale(1.0f, 1.0f);
	
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	velocity.x = 0.0f;
	//velocity.x *= 0.5f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		velocity.x += speed;
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		velocity.y -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		velocity.y += speed * deltaTime;*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && canJump)
	{
		canJump = false;

		//How to jump - square root (2.0f * gravity * jumpheight);
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}

	velocity.y += 981.0f * deltaTime;

	/*if (movement.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;

		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}*/

	body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		velocity.x = 0.0f;
	}

	if (direction.y < 0.0f)
	{
		//Collision on the bottom
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		velocity.y = 0.0f;
		
	}
}
