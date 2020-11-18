#include <iostream>
#include <SFML/Graphics.hpp>
#include "Render.h"
#include "Environment.h"
#include "Circle.h"
#include <vector>
#include <time.h>

int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Circle Collision");

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

		window.clear(sf::Color::White);
		render.render(window);

		if (pull) {
			window.draw(line, 2, sf::Lines);
		}
		window.display();

	}

	return 0;
}