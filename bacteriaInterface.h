#pragma once
#include <random>

class Bacteria {																// <- Abstract class
																				//
public:																			// 
	std::vector<int> clone(std::vector<int> nearbyEmpty_);						//<- virtual methods overloaded in derived classes
	virtual std::vector<Bacteria*> status(std::vector<Bacteria*> nearby_) = 0;	//
	virtual int getRadius() = 0;												//
	virtual int getX() = 0;														//
	virtual int getY() = 0;														//
	char name;																	//
	int aliveStatus;															//
};