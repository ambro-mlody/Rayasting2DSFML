#include <SFML/Graphics.hpp>
#include <iostream>
#include "Boundary.h"
#include "Ray.h"
#include "Particle.h"

#define W 800
#define H 600

int main()
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(W, H), "Raycasting2D");
	std::vector<Boundary> walls;
	for (int i = 0; i < 5; i++)
	{
		int x1 = rand() % W;
		int y1 = rand() % H;
		int x2 = rand() % W;
		int y2 = rand() % H;

		walls.emplace_back(Boundary(x1, y1, x2, y2));

	}

	walls.emplace_back(Boundary(0, 0, 0, H));
	walls.emplace_back(Boundary(0, 0, W, 0));
	walls.emplace_back(Boundary(0, H, W, H));
	walls.emplace_back(Boundary(W - 1, 0, W - 1, H));
	
	//Ray ray(100, 200);
	Particle particle(W, H);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}

		window.clear();

		sf::Vector2i mousePos = sf::Mouse::getPosition();
		sf::Vector2i windowPos = window.getPosition();
		if (mousePos.x > windowPos.x&& mousePos.x < windowPos.x + W && mousePos.y > windowPos.y&& mousePos.y < windowPos.y + H)
		{
			sf::Vector2f newPos = { (float)mousePos.x - windowPos.x, (float)mousePos.y - windowPos.y };
			particle.update(newPos);
		}
		

		particle.show(window);
		for (auto wall : walls)
		{
			wall.show(window);
		}
		
		particle.look(walls, window);

		window.display();
	}

	return 0;
}