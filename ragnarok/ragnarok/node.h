#pragma once
#include "object.h"
#include "undrawable.h"

class node : public object {
public:
	node() {}
	virtual ~node() {}

public:
	virtual const sf::Drawable& draw() { return _undrawable; };
	virtual const bool is_node() const { return true; }

private:
	undrawable _undrawable;
};