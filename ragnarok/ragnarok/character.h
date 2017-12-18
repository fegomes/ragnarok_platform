#pragma once
#include <string>
#include <unordered_map>

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Window\Event.hpp>

#include <boost\signals2.hpp>

#include "object.h"

class character : public object
{
public:
	character();
	~character();

public:
	enum moviment {
		idle,
		walk,
		walk_back,
		run,
		run_back,
		attack,
		hurt,
		die
	};

	typedef std::unordered_map<moviment, std::vector<sf::IntRect>> action;

public:
	void load_texture_from_file(const std::string& file);
	void load_moviment();
    void execute(moviment m);
	const sf::Drawable& draw();

	void key_pressed(const sf::Event& k) {
		execute(character::moviment::walk);
	}

public:
	sf::Texture _texture;
	sf::Sprite  _sprite;
	action      _action;
	moviment    _last_moviment;
	std::vector<sf::IntRect>::iterator _it;

};

