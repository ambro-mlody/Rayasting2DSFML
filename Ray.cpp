#include "Ray.h"

Ray::Ray(sf::Vector2f pos, float angle)
{
	position = pos;
	direction = {cos(angle), sin(angle)};
}

void Ray::show(sf::RenderWindow& window)
{
	sf::Vertex line[] = { sf::Vertex(position), sf::Vertex(position + direction * 4.f) };
	//sf::VertexArray line(sf::LinesStrip, 2);
	//sf::Color::Color(255, 255, 255, 100);

	//line[0] = sf::Vertex(position);
	//line[1] = sf::Vertex(position + direction * 4.f);

	//line[0].color = sf::Color::Red;
	//line[1].color = sf::Color::Red;

	window.draw(line, 2, sf::Lines);
	//window.draw(line);
}

bool Ray::cast(const Boundary& wall, sf::Vector2f& point)
{
	float x1 = wall.a.x;
	float y1 = wall.a.y;
	float x2 = wall.b.x;
	float y2 = wall.b.y;

	float x3 = position.x;
	float y3 = position.y;
	float x4 = position.x + direction.x;
	float y4 = position.y + direction.y;

	float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	if (den == 0)
		return false;

	float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
	float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

	if (t > 0 && t < 1 && u > 0)
	{
		point.x = x1 + t * (x2 - x1);
		point.y = y1 + t * (y2 - y1);
		return true;
	}

	return false;
}

void Ray::lookAt(float x, float y)
{
	direction.x = x - position.x;
	direction.y = y - position.y;

	float distance = vectorLength(direction.x, direction.y);
	direction.x /= distance;
	direction.y /= distance;
}

float vectorLength(float x, float y)
{
	return sqrt(x * x + y * y);
}
