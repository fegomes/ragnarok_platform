#include "stdafx.h"
#include "character.h"


character::character()
{
}


character::~character()
{
}

void character::load_texture_from_file(const std::string & file)
{
	sf::Image image;
	image.loadFromFile(file);
	_texture.loadFromImage(image);
	_sprite.setTexture(_texture);
}

void character::load_moviment() {
	_action[moviment::idle].push_back(sf::IntRect(230, 75, 38, 75));

	_action[moviment::walk].push_back(sf::IntRect(265, 75, 50, 75));
	_action[moviment::walk].push_back(sf::IntRect(312, 75, 39, 75));
	_action[moviment::walk].push_back(sf::IntRect(38, 75, 32, 75));
	_action[moviment::walk].push_back(sf::IntRect(69, 75, 38, 75));
	_action[moviment::walk].push_back(sf::IntRect(105, 75, 50, 75));
	_action[moviment::walk].push_back(sf::IntRect(155, 75, 45, 75));
	_action[moviment::walk].push_back(sf::IntRect(198, 75, 35, 75));
	_action[moviment::walk].push_back(sf::IntRect(230, 75, 38, 75));

	_sprite.setTextureRect(*_action[moviment::idle].begin());
}

void character::execute(moviment m)
{
	if (m != _last_moviment) {
		_last_moviment = m;
		_it = _action[m].begin();
	}
	else {
		if (_it != _action[m].end()) {
			_it++;
		}

		if (_it == _action[m].end()) {
			_it = _action[m].begin();
		}
	}

	if (_it != _action[m].end()) {
		_sprite.setTextureRect(*_it);
	}
}

const sf::Drawable& character::draw()
{
	return _sprite;
}
