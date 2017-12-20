#pragma once
#include <string>
#include <map>
#include <memory>

#include "node.h"

class layer {

public:
	layer(const std::string& name) : _name(name) { }
	virtual ~layer() {};

public:

	void draw(sf::RenderWindow& w) {
		for (auto ci = _layers.begin(); ci != _layers.end(); ci++) {
			const object &obj = ci->second;
			if (obj.is_node()) {
				node& n = (node&) obj;
				n.draw(w);
			} else {
				if (obj.is_visible()) {
					w.draw(obj.draw());
				}
			}
		}
	}

	const std::string& name() const {
		return _name;
	}

	void push_back(const std::string& name, object& obj) {
		_layers[name] = obj;
	}
	
private:
	std::string _name;
	std::map<const std::string&, object> _layers;
};