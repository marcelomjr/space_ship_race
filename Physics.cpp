#include "Physics.hpp"
#include <iostream>
#include <cmath>        // std::abs

void Physics::init(std::vector<Body*>* body_list, Screen* screen_reference) {
	this->screen_reference = screen_reference;
	this->body_list = body_list;
}

bool Physics::has_colision(coordinate point_1, coordinate point_2) {
	double delta_x = abs(point_1.x - point_2.x - 5);
	double delta_y = abs(point_1.y - point_2.y);
	
	if (delta_x < 8.0 && delta_y < 4.0) {
		return true;
	}
	
	return false;
	
}
void Physics::update(double deltaT){
	
	for (int body = 0; body < this->body_list->size(); body++){

		coordinate pos =   (*this->body_list)[body]->get_position();
		coordinate speed = (*this->body_list)[body]->get_speed();

		pos.x += speed.x * deltaT;
		pos.y += speed.y * deltaT;
		
		(*this->body_list)[body]->update(pos, speed);
		
	}
	
	for (int body = 1; body < this->body_list->size(); body++){
		
		if (has_colision((*this->body_list)[0]->get_position(), (*this->body_list)[body]->get_position())) {
			
			coordinate zero = {.x = 0, .y =0 };
			coordinate speed = {.x = 0, .y =10 };
			(*this->body_list)[0]->update(zero, speed);
		}
		
	}
	

}