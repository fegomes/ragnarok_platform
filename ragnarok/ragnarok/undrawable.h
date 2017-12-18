#pragma once
#include <SFML\Graphics\RenderStates.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\Drawable.hpp>

class undrawable : public sf::Drawable
{
public:
	undrawable() {};
	~undrawable() {}

public:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const {}
};