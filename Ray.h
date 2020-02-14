#pragma once
#include <SFML/Graphics.hpp>
#include "Boundary.h"
#include <math.h>

float vectorLength(float x, float y);

class Ray
{
	sf::Vector2f position;
	sf::Vector2f direction;

public:
	Ray(sf::Vector2f pos, float angle);
	void show(sf::RenderWindow& window);
	bool cast(const Boundary&, sf::Vector2f&);
	void lookAt(float x, float y);
};

