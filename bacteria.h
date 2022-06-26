#pragma once
#include <vector>
#include "bacteriaInterface.h"
#include "dish.h"


/*					Declarations only					*/

class Bacillus : public Bacteria {
private:
	int x;
	int y;
	int radius;
public:
	Bacillus(int& y, int& x);
	std::vector<Bacteria*> status(std::vector<Bacteria*> nearby_) override;
	int getRadius() override;
	int getX() override;												
	int getY() override;
	
};

class Coccus : public Bacteria {
private:
	int x;
	int y;
	int radius;
public:
	Coccus(int& y, int& x);
	std::vector<Bacteria*> status(std::vector<Bacteria*> nearby_) override;
	int getRadius() override;
	int getX() override;												
	int getY() override;
	
};

class Spirillum : public Bacteria {
private:
	int x;
	int y;
	int radius;
public:
	Spirillum(int& y, int& x);
	std::vector<Bacteria*> status(std::vector<Bacteria*> nearby_) override;
	int getRadius() override;
	int getX() override;												
	int getY() override;
};