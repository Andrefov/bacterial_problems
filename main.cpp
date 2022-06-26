#pragma once
#include <iostream>
#include <memory>
#include "bacteria.h"
#include "dish.h"


int main() {
	int lifeCycles = 0;
	std::cout << "welcome to bacteria life simulator.\n";
	std::cout << "please enter the number of life cycles:\n";
	std::cin >> lifeCycles;

	

	Dish dish = Dish(500, 500);
	dish.initialFill();
	dish.displayDish();
	while (lifeCycles != 0) {
		dish.performRound();
	}

	return 0;
}