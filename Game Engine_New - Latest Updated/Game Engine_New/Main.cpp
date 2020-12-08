#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"

static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 650), "Game Engine", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("ball2.png");

	Player player(&playerTexture, 100.0f, 170.0f);

	std::vector<Platform> platforms;

	platforms.push_back(Platform(sf::Color::Green, sf::Vector2f(35.0f, 50.0f), sf::Vector2f(250.0f, 430.0f)));
	platforms.push_back(Platform(sf::Color::Green, sf::Vector2f(35.0f, 50.0f), sf::Vector2f(450.0f, 430.0f)));
	platforms.push_back(Platform(sf::Color::Green, sf::Vector2f(35.0f, 30.0f), sf::Vector2f(750.0f, 400.0f)));
	platforms.push_back(Platform(sf::Color::Red, sf::Vector2f(1000.0f, 150.0f), sf::Vector2f(500.0f, 150.0f)));
	platforms.push_back(Platform(sf::Color::Yellow, sf::Vector2f(1000.0f, 100.0f), sf::Vector2f(500.0f, 500.0f)));
	//Platform platform1(sf::Color::Green, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
	//Platform platform2(sf::Color::Red, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));
	//Platform platform3(sf::Color::Yellow, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f));
	
	float deltaTime = 0.0f;
	sf::Clock clock;
	
	while (window.isOpen()) 
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;

		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}

		}

		player.Update(deltaTime);

		sf::Vector2f direction;

		/*for (int i = 0; i < platforms.size(); i++)
		{
			Platform& platform = platforms[i];

		}*/

		for (Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction);


		view.setCenter(player.GetPosition());

		window.clear(sf::Color(150, 150, 150));
		window.setView(view);
		//window.draw(player);
		player.Draw(window);

		for (Platform& platform : platforms)
		platform.Draw(window);

		window.display();
	}

	return 0;
}
