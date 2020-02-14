#include "Boundary.h"

Boundary::Boundary(float x1, float y1, float x2, float y2)
{
	a.x = x1;
	a.y = y1;

	b.x = x2;
	b.y = y2;
}

void Boundary::show(sf::RenderWindow& window)
{
	sf::Vertex line[] = { sf::Vertex(a), sf::Vertex(b) };
	window.draw(line, 2, sf::Lines);
}
