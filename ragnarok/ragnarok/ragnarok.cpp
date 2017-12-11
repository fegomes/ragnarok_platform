// ragnarok.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "character.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 800), "SFML works!");
	//sf::Texture texture;
	//texture.loadFromFile();

	character c;
	c.load_texture_from_file("resource\\novice_m.png");
	c.load_moviment();

	//sf::Texture texture2;
	//texture2.loadFromFile("resource\\Tile_2.png");
	//sf::Sprite character;
	//character.setTexture(texture);
	//character.setOrigin({ 0, 0 });
	//character.setTextureRect(sf::IntRect(312, 75, 39, 75));
	
	//sf::Sprite map;
	//map.setTexture(texture2);
	//map.setPosition(0, 800 - map.getGlobalBounds().height);

	//sf::Sprite map2 = map;
	//map2.setPosition(map2.getGlobalBounds().width, 800-map2.getGlobalBounds().height);

	//character.setPosition(400, 800-200);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::KeyPressed) {
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					c.execute(character::moviment::walk);
				}
			}
		}

		window.clear();
		window.clear(sf::Color(92,197,242));
		window.draw(c.draw());		
		window.display();
	}

	return 0;
}