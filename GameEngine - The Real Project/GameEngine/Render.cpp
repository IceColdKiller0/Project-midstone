#include "Render.h"

Render::Render(Environment& environment) : environment(environment) {}

Render::~Render() {}

void Render::render(sf::RenderWindow& window) const {
	renderCircles(window);
}

void Render::renderCircles(sf::RenderWindow& window) const {
	for (Circle circle : environment.getCircles()) {
		circle.draw(window);
	}
}