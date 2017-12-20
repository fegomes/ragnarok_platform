#pragma once
#include <SFML\Graphics\Drawable.hpp>

#include "undrawable.h"

class object {

protected:
	object() : _is_node(false), _is_visible(true) {}

public:
	virtual ~object() {};

public:
	virtual const sf::Drawable& draw() const = 0;
	const bool is_node() const { return _is_node; }
	const bool is_visible() const { return _is_visible; }
protected:
	bool _is_node;
	bool _is_visible;
};