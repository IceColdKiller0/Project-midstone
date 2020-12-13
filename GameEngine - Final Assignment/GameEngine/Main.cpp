#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include "Render.h"
#include "Environment.h"
#include "Circle.h"
#include "Player.h"
#include "Platform.h"


int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 650), "Circle Collision");

	//const float gravity = 0.3f;
	//int groundHeight = 440;
	//sf::Vector2f velocity(sf::Vector2f(0, 0));

	//sf::RectangleShape rect(sf::Vector2f(40.0f, 40.0f));
	//rect.setPosition(50, 0);
	//rect.setFillColor(sf::Color::Blue);

	//float moveSpeed = 1.0f, jumpSpeed = 4.0f;

	Player player(sf::Color::Blue, 1.0f, 2.0f);

	std::vector<Platform> platforms, platforms1;
	std::vector<Circle> circles, circles1;

	platforms.push_back(Platform(sf::Color::Red, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(500.0f, 390.0f)));
	platforms1.push_back(Platform(sf::Color::Cyan, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(300.0f, 390.0f)));

	srand((unsigned)(time(NULL)));

	Environment environment;
	Render render(environment);

	sf::Vertex line[] = { sf::Vertex(sf::Vector2f(-1, -1)), sf::Vertex(sf::Vector2f(-1, -1)) };

	bool pull = false;

	float deltatime = 0.f;
	sf::Clock clock;


	while (window.isOpen()) {
		sf::Event event;

		deltatime = clock.restart().asSeconds();
		if (deltatime > 1.0f / 20.0f)
			deltatime = 1.0f / 20.0f;

		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {

					sf::Vector2i point = sf::Mouse::getPosition(window);

					if (environment._pullCircle(sf::Vector2f((float)point.x, (float)point.y))) {
						pull = true;
					}
				}
				break;

			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left) {

					environment.setPullVel(line[1].position.x, line[1].position.y);

					pull = false;
				}
				break;
			}
		}

		if (pull) {
			sf::Vector2i point = sf::Mouse::getPosition(window);

			line[0] = sf::Vertex(sf::Vector2f(environment.getPullCircle()->getPos()), sf::Color::Blue);
			line[1] = sf::Vertex(sf::Vector2f((float)point.x, (float)point.y), sf::Color::Blue);
		}

		environment.update(deltatime);
		player.Update(deltatime);

		sf::Vector2f direction;

		for (Platform& platform : platforms)
		{
			//platform.Update(deltatime);
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
				player.OnCollision(direction);
		}

		for (Platform& platform1 : platforms1)
		{
			//platform1.Update(deltatime);
			if (platform1.GetCollider().CheckCollision(player.GetCollider(), direction, 0.5f))
				player.OnCollision(direction);
		}

		for (Platform& platform2 : platforms1)
		{
			for (Platform& platform3 : platforms)
			{
				if (platform3.GetCollider().CheckCollision(platform2.GetCollider(), direction, 1.0f))
				{
					platform2.OnCollision(direction);
					player.OnCollision(direction);

				}
			}
		}

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			velocity.x = moveSpeed;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			velocity.x = -moveSpeed;
		else
			velocity.x = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		
			velocity.y = -jumpSpeed;*/
			//velocity.y = -sqrtf(2.0f * 981.0f * jumpSpeed);
		
		//velocity.y += 981.0f * deltatime;

		/*if (rect.getPosition().y + rect.getSize().y < groundHeight || velocity.y < 0)
		{
			velocity.y += gravity;
		}
		else
		{
			rect.setPosition(rect.getPosition().x, groundHeight - rect.getSize().y);
			velocity.y = 0;
		}

		rect.move(velocity.x, velocity.y);*/


		window.clear(sf::Color::White);
		render.render(window);

		player.Draw(window);

		for (Platform& platform : platforms)
			platform.Draw(window);

		for (Platform& platform1 : platforms1)
			platform1.Draw(window);

		//window.draw(rect);

		if (pull) {
			window.draw(line, 2, sf::Lines);
		}

		window.display();

	}

	return 0;
}