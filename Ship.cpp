#include <iostream>
#include "Ship.hpp"


void Body::update(coordinate position, coordinate speed) {
		this->position = position;
		this->speed = speed;

		//cout << "Body: position:" << this->get_position().x << endl;
}
coordinate Body::get_position() {
	return this->position;
}

void Ship::init(coordinate initial_position, coordinate initial_speed) {
	this->update(initial_position, initial_speed);
}