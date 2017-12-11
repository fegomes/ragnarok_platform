#pragma once
#include <string>
#include <unordered_map>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Sprite.hpp>

class character
{
public:
	character();
	~character();

public:
	enum moviment {
		idle,
		walk,
		run,
		attack,
		hurt,
		die
	};

	typedef std::unordered_map<moviment, std::vector<sf::IntRect>> action;

public:
	void load_texture_from_file(const std::string& file);
	void load_moviment();
    void execute(moviment m);
	sf::Sprite& draw();

private:
	sf::Texture _texture;
	sf::Sprite  _sprite;
	action      _action;
	moviment    _last_moviment;
	std::vector<sf::IntRect>::iterator _it;

};

