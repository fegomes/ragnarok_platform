#pragma once
#include <string>
#include <vector>
#include <memory>

#include "object.h"

class layer : public std::vector<layer> {

public:
	layer(const std::string& name, object& obj) : _object(obj) { _name = name; }
	virtual ~layer() {};

public:
	void set_object(const object& obj) {
		_object = obj;
	}

	object& get_object() {
		return _object;
	}

	void draw(sf::RenderWindow& w) {
		for (auto ci = begin(); ci != end(); ci++) {
			object &obj = (*ci).get_object();

			if (obj.is_node()) {
				layer& l = (layer&)obj;
				l.draw(w);
			} else {
				w.draw(obj.draw());
			}
		}
	}

	
	
private:
	object&      _object;
	std::string  _name;
};