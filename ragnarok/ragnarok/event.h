#pragma once
#include <boost\signals2.hpp>
#include <SFML\Window\Event.hpp>
#include <SFML\Window\Keyboard.hpp>

#define SLOT
#define SIGNAL

class event : public sf::Event {
public:
	event() {}
	~event() {
		key_pressed.disconnect_all_slots();
	}

	typedef boost::signals2::signal< void(const sf::Event&) > key_event;

public:
	void run() {
		if (type == sf::Event::KeyPressed) {
			on_key_pressed(*this);
		}
	}

public SLOT:
    void do_key_pressed(const key_event::slot_type& slot) {
		key_pressed.connect(slot);
	}

public SIGNAL:
	void on_key_pressed(const sf::Event& e) {
		key_pressed(*this);
	}

private:
	key_event key_pressed;

};
