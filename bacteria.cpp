#include "bacteria.h"

Bacillus::Bacillus(int& y_, int& x_) :  //|
	y(y_),								//|
	x(x_),								//| <- parametric constructor
	radius(4)							//|
{};										//|

std::vector<Bacteria*> Bacillus::status(std::vector<Bacteria*> nearby_) {
	aliveStatus = 0;
	std::vector<Bacteria*> food;
	for (int i = 0; i < (nearby_.size()); i++) {
		if (nearby_[i]->name == 'C' && food.size() < 2) {
			aliveStatus = 1;
			food.push_back(nearby_[i]);
			return food;
		}
	}
	return food;
}
int Bacillus::getRadius() {
	return radius;
}
int Bacillus::getX() {
	return x;
}
int Bacillus::getY() {
	return y;
}
/*-------------------------------------------------------------*/

Coccus::Coccus(int& y_, int& x_) :  //|
	y(y_),							//|
	x(x_),							//| <- parametric constructor
	radius(2)						//|
{};									//|

std::vector<Bacteria*> Coccus::status(std::vector<Bacteria*> nearby_) {
	std::vector<Bacteria*> food;
	int survive = 0;
	for (int i = 0; i < nearby_.size(); i++) {

		if (nearby_[i]->name != 'C' && food.size() < 3) {
			survive++;
			food.push_back(nearby_[i]);
		}
	}
	if (survive >= 2) {
		aliveStatus = 1;
		return food;		
	}
	else {
		aliveStatus = 0;
		return food;
	}
}
int Coccus::getRadius() {
	return radius;
}
int Coccus::getX() {
	return x;
}
int Coccus::getY() {
	return y;
}
/*-------------------------------------------------------------*/

Spirillum::Spirillum(int& y_, int& x_) :	//|
	y(y_),									//|
	x(x_),									//| <- parametric constructor
	radius(3)								//|
{};											//|

std::vector<Bacteria*> Spirillum::status(std::vector<Bacteria*> nearby_) {
	std::vector<Bacteria*> food;
	for (int i = 0; i < (nearby_.size()); i++) {
		if (nearby_[i]->name == 'B') {
			aliveStatus = 0;
			return food;
		}
	}
	aliveStatus = 1;
	return food;
}
int Spirillum::getRadius() {
	return radius;
}
int Spirillum::getX() {
	return x;
}
int Spirillum::getY() {
	return y;
}