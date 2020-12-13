#include "Player.h"

Player::Player(sf::Color texture, float moveSpeed, float jumpSpeed)
{
	this->moveSpeed = moveSpeed;
	this->jumpSpeed = jumpSpeed;
	//row = 0;
	//faceRight = true;

	
	
	groundHeight = 440;

	body.setSize(sf::Vector2f(50.0f, 50.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(50.0f, 0.0f);
	body.setFillColor(texture);
	//body.scale(0.8f, 0.8f);
	//body.setScale(1.0f, 1.0f);

	//const float gravity = 0.3f;
	//int groundHeight = 440;
	//velocity(sf::Vector2f(0, 0));

	//float moveSpeed = 1.0f, jumpSpeed = 4.0f;

}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	//velocity.x = 0.0f;
	////velocity.x *= 0.5f;

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	//	velocity.x -= speed;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	//	velocity.x += speed;
	///*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	//	velocity.y -= speed * deltaTime;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	//	velocity.y += speed * deltaTime;*/

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && canJump)
	//{
	//	canJump = false;

	//	//How to jump - square root (2.0f * gravity * jumpheight);
	//	velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	//}

	//velocity.y += 981.0f * deltaTime;

	///*if (movement.x == 0.0f)
	//{
	//	row = 0;
	//}
	//else
	//{
	//	row = 1;

	//	if (movement.x > 0.0f)
	//		faceRight = true;
	//	else
	//		faceRight = false;
	//}*/

	//body.move(velocity * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			velocity.x = moveSpeed;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			velocity.x = -moveSpeed;
		else
			velocity.x = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))

			velocity.y = -jumpSpeed;
			//velocity.y = -sqrtf(2.0f * 981.0f * jumpSpeed);

		//velocity.y += 981.0f * deltatime;

		if (body.getPosition().y + body.getSize().y < groundHeight || velocity.y < 0)
		{
			velocity.y += gravity;
		}
		else
		{
			body.setPosition(body.getPosition().x, groundHeight - body.getSize().y);
			velocity.y = 0;
		}

		body.move(velocity.x, velocity.y);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	//window.draw(circle);
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
