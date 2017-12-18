#pragma once
#include <SFML\Graphics\Drawable.hpp>

class object {
protected:
	object() {}

public:
	virtual ~object() {};

public:
	virtual const sf::Drawable& draw() = 0;
	virtual const bool is_node() const { return false; }
};