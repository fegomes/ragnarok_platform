#pragma once
#include <boost\signals2.hpp>

#include <SFML\Window\Keyboard.hpp>

class event {
public:
	event() {}
	~event() {}


};
boost::signals2::signal< void ( const sf::Event& ) > key_pressed;
boost::signals2::signal< void ( const sf::Event& ) > key_released;
