// ragnarok.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <boost\signals2.hpp>

#include "layer.h"
#include "character.h"
#include "node.h"
#include "event.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 800), "Welcome");

	layer layers("Teste", node());
	character c;
	c.load_texture_from_file("resource\\novice_m.png");
	c.load_moviment();

	character c2;
	c2.load_texture_from_file("resource\\novice_m.png");
	c2.load_moviment();
	c2._sprite.setPosition(100, 100);
	layer player("player", c);
	layers.push_back(player);
	layers.push_back(layer("player2", c2));

	key_pressed.connect(boost::bind(&character::key_pressed, &c, _1));

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (event.type == sf::Event::KeyPressed) {
			key_pressed(event);
		}


		window.clear(sf::Color(92, 197, 242));
		layers.draw(window);
		window.display();
	}

	key_pressed.disconnect_all_slots();

	return 0;
}

//int main2()
//{
//	sf::RenderWindow window(sf::VideoMode(1024, 800), "SFML works!");
//	//sf::Texture texture;
//	//texture.loadFromFile();
//
//	character c;
//	c.load_texture_from_file("resource\\novice_m.png");
//	c.load_moviment();
//	
//	sf::Texture texture2;
//	texture2.loadFromFile("resource\\Tile_2.png");
//	texture2.setRepeated(true);
//
//	sf::Texture tpedra1;
//	tpedra1.loadFromFile("resource\\Object_2.png");
//
//	sf::Sprite pedra1;
//	pedra1.setTexture(tpedra1);
//	pedra1.setPosition(0, 540);
//	pedra1.scale(0.5, 0.5);
//	sf::Texture tpedra2;
//	tpedra2.loadFromFile("resource\\Object_3.png");
//
//	sf::Sprite pedra2;
//	pedra2.setTexture(tpedra2);
//
//	sf::Texture tarvore1;
//	tarvore1.loadFromFile("resource\\Object_16.png");
//
//	sf::Sprite arvore1;
//	arvore1.setTexture(tarvore1);
//
//	sf::Texture tarvore2;
//	tarvore2.loadFromFile("resource\\Object_17.png");
//
//	sf::Sprite arvore2;
//	arvore2.setTexture(tarvore2);
//
//	sf::Texture tgrama1;
//	tgrama1.loadFromFile("resource\\Object_6.png");
//
//	sf::Texture tgrama2;
//	tgrama2.loadFromFile("resource\\Object_7.png");
//	//sf::Sprite character;
//	//character.setTexture(texture);
//	//character.setOrigin({ 0, 0 });
//	//character.setTextureRect(sf::IntRect(312, 75, 39, 75));
//	
//	sf::Sprite map;
//	map.setTexture(texture2);
//	map.setPosition(0, 800 - map.getGlobalBounds().height);
//	map.setTextureRect(sf::IntRect(0, 0,3000, 800));
//
//	//character.setPosition(400, 800-200);
//	//c.draw().setScale(-1, 1);
//	//c.draw().setPosition(1024 / 2, 635 - 35);
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed) {
//				window.close();
//			}
//
//			if (event.type == sf::Event::KeyPressed) {
//				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//					c.execute(character::moviment::walk);
//					
//					auto pos = map.getPosition();
//					pos.x -= 5;
//					map.setPosition(pos);
//				}
//				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//					c.execute(character::moviment::walk_back);
//				}
//			}
//			else {
//				//c.execute(character::moviment::idle);
//			}
//		}
//
//		window.clear(sf::Color(92, 197, 242));
//		
//		window.draw(map);
//		window.draw(pedra1);
//		window.draw(c.draw());		
//		window.display();
//	}
//
//	return 0;
//}
