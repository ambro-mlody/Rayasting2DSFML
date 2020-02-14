#pragma once
#include<SFML/Graphics.hpp>

class Boundary
{
	sf::Vector2f a;
	sf::Vector2f b;

public:
	Boundary(float x1, float y1, float x2, float y2);
	void show(sf::RenderWindow& window);

	friend class Ray;
};

