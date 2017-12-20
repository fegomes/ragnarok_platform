#pragma once
#include "object.h"

#include <SFML\Graphics\RectangleShape.hpp>

class rectangle : public object
{
public:
	rectangle() {
		_rectangle.setSize(sf::Vector2f(100, 50));
		_rectangle.setOutlineColor(sf::Color::Red);
		_rectangle.setOutlineThickness(5);
		_rectangle.setPosition(10, 20);
	}
	~rectangle() {}

	const sf::Drawable& draw() const {
		return _rectangle;
	}

private:
	sf::RectangleShape _rectangle;
};