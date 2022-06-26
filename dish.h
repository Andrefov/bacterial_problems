#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include "bacteriaInterface.h"
#include "bacteria.h"

class Dish {
public:
	int lifeCycle;
	int rows;
	int cols;
	int bacillusNumber;
	int coccusNumber;
	int SpirillumNumber;
	int total;
	int died;
	Dish(int rows, int cols);
	void performRound();
	void initialFill();
	void displayDish();
	void cleanDeadBacteria();
	std::vector <Bacteria*> nearby(int size_, int radius, int y, int x);
	std::vector <int> nearbyEmpty(int size_, int radius, int y, int x);
private:
	std::vector<std::vector<Bacteria*>> dish;
};