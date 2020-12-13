#include "Platform.h"

Platform::Platform(sf::Color texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	//body.setTexture(texture);
	body.setFillColor(texture);
	body.setPosition(position);

	groundHeight = 440;

}

Platform::~Platform()
{
}

//void Platform::Update(float deltatime)
//{
//	if (body.getPosition().y + body.getSize().y < groundHeight || velocity.y < 0)
//	{
//		velocity.y += gravity;
//	}
//	else
//	{
//		body.setPosition(body.getPosition().x, groundHeight - body.getSize().y);
//		velocity.y = 0;
//	}
//}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Platform::OnCollision(sf::Vector2f direction)
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
		//canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		velocity.y = 0.0f;

	}
}

