#pragma once
#include <SFML/Graphics.hpp>
#include "Ray.h"
#include "Boundary.h"
#include <vector>
#define _USE_MATH_DEFINES
#include<math.h>

float toRadians(float angle);

class Particle
{
	sf::Vector2f position;
	std::vector<Ray> rays;

public:
	Particle(int screenWidth, int screenHeight);
	void show(sf::RenderWindow& window);
	void look(const std::vector<Boundary>& walls, sf::RenderWindow &window);
	void update(sf::Vector2f pos);
};

