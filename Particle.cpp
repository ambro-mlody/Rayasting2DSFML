#include "Particle.h"

Particle::Particle(int screenWidth, int screenHeight)
{
	position.x = screenWidth / 2;
	position.y = screenHeight / 2;

	for (int i = 0; i < 360; i+=2)
	{
		rays.emplace_back(Ray(position, toRadians(i)));
	}
}

void Particle::show(sf::RenderWindow& window)
{
	float radius = 4.f;
	sf::CircleShape shape(radius);
	shape.setFillColor(sf::Color::White);
	shape.setPosition({ position.x - radius, position.y - radius });
	window.draw(shape);
	for (auto r : rays)
		r.show(window);
}

void Particle::look(const std::vector<Boundary>& walls, sf::RenderWindow& window)
{
	sf::Vector2f point;
	for (auto r : rays)
	{
		float closest = 80000.f;
		sf::Vector2f bestPoint;
		for (auto wall : walls)
		{
			if (r.cast(wall, point))
			{
				float d = vectorLength(point.x - position.x, point.y - position.y);
				if (d < closest)
				{
					closest = d;
					bestPoint = point;
				}

			}
		}

		if (closest != 80000.f)
		{
			sf::Vertex line[] = { sf::Vertex(position), sf::Vertex(bestPoint) };
			window.draw(line, 2, sf::Lines);
		}
		
	}
}

void Particle::update(sf::Vector2f pos)
{
	position = pos;
	rays.clear();
	for (int i = 0; i < 360; i+=2)
	{
		rays.emplace_back(Ray(position, toRadians(i)));
	}
}

float toRadians(float angle)
{
	return angle * M_PI / 180;
}
