#pragma once
#include "object.h"
#include "undrawable.h"

class node : public object {
public:
	node() { _is_node = true; }
	virtual ~node() {}

	typedef std::map < const std::string&, object > map_object;
public:
	virtual const sf::Drawable& draw() const { return _undrawable; }

	const void draw(sf::RenderWindow& w) const {
		for (auto ci = _objects.begin(); ci != _objects.end(); ci++) {
			const object &obj = ci->second;

			if (obj.is_node()) {
				node& n = (node&)obj;
				n.draw();
			}
			else {
				if (obj.is_visible()) {
					w.draw(obj.draw());
				}
			}
		}
	}

	void push_back(const std::string& name, object& obj) {
		_objects[name] = obj;
	}

private:
	undrawable _undrawable;
	map_object _objects;
};