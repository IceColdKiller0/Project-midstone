#ifndef RENDERER_H
#define RENDERER_H
#include <SFML/Graphics.hpp>
#include "Environment.h"

class Render {

public:
	Render(Environment& environment);
	~Render();

	void render(sf::RenderWindow& window) const;
	void renderCircles(sf::RenderWindow& window) const;

private:
	Environment& environment;
};

#endif

