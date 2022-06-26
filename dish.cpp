#include "dish.h"

Dish::Dish(int rows_, int cols_) :		//
	rows(rows_),						//
	cols(cols_),						//
	bacillusNumber(0),					// <- parametric constructor with initiation list 
	coccusNumber(0),					//
	SpirillumNumber(0),					//
	lifeCycle(0),						//
	died(0),							//
	total(0)							//
{};										//

void Dish::performRound() {
	for (int y = 0; y < cols; y++) {
		for (int x = 0; x < rows; x++) {
			if (dish[y][x] != nullptr && total > 0) {
				std::vector<Bacteria*> eaten;
				eaten = dish[y][x]->status(nearby(rows, dish[y][x]->getRadius(), y, x));
				for (int i = 0; i < eaten.size(); i++) {
					if (dish[eaten[i]->getY()][eaten[i]->getX()]->name == 'B') {
						bacillusNumber--;
						died++;
						int y_ = eaten[i]->getY();
						int x_ = eaten[i]->getX();
						delete dish[y_][x_];
						dish[y_][x_] = nullptr;
					}
					else if (dish[eaten[i]->getY()][eaten[i]->getX()]->name == 'C') {
						coccusNumber--;
						died++;
						int y_ = eaten[i]->getY();
						int x_ = eaten[i]->getX();
						delete dish[y_][x_];
						dish[y_][x_] = nullptr;
					}
					else {
						SpirillumNumber--;
						died++;
						int y_ = eaten[i]->getY();
						int x_ = eaten[i]->getX();
						delete dish[y_][x_];
						dish[y_][x_] = nullptr;
					}
				}
			}
		}
	}
	cleanDeadBacteria();
	for (int y = 0; y < cols; y++) {
		for (int x = 0; x < rows; x++) {
			if (dish[y][x] != nullptr) {
				std::vector<int> coordinates;
				coordinates = dish[y][x]->clone(nearbyEmpty(rows, dish[y][x]->getRadius(), y, x));
				switch (dish[y][x]->name) {
				case 66:
					if (coordinates.size() > 0) {
						dish[coordinates[0]][coordinates[1]] = new Bacillus(coordinates[0], coordinates[1]);
						dish[coordinates[0]][coordinates[1]]->name = 'B';
						bacillusNumber++;
						break;
					}
				case 67:
					if (coordinates.size() > 0) {
						dish[coordinates[0]][coordinates[1]] = new Coccus(coordinates[0], coordinates[1]);
						dish[coordinates[0]][coordinates[1]]->name = 'C';
						coccusNumber++;
						break;
					}
				case 83:
					if (coordinates.size() > 0) {
						dish[coordinates[0]][coordinates[1]] = new Spirillum(coordinates[0], coordinates[1]);
						dish[coordinates[0]][coordinates[1]]->name = 'S';
						SpirillumNumber++;
						break;
					}
				}
			}
		}
	}
	system("cls");
	displayDish();
	lifeCycle++;
}

void Dish::initialFill() {
	int plantedBacteria = 0;
	std::random_device plagueSpreader;
	std::mt19937 rng(plagueSpreader());

	for (int y = 0; y < cols; y++) {
		std::vector<Bacteria*> v;
		for (int x = 0; x < rows; x++) {
			std::uniform_int_distribution<std::mt19937::result_type> numberOfBacteria(0, (1)); // fill aprox 50% of dish with bacteria
			if (numberOfBacteria(rng) >= 1) {
				std::uniform_int_distribution<std::mt19937::result_type> typeOfBacteria(1, (3)); //random bacteria type (1 of 3)

				switch (typeOfBacteria(rng)) {
				case 1:
					v.push_back(new Bacillus(y, x));
					plantedBacteria++;
					bacillusNumber++;
					v[x]->name = 'B';
					break;
				case 2:
					v.push_back(new Coccus(y, x));
					plantedBacteria++;
					coccusNumber++;
					v[x]->name = 'C';
					break;
				case 3:
					v.push_back(new Spirillum(y, x));
					plantedBacteria++;
					SpirillumNumber++;
					v[x]->name = 'S';
					break;
				}
			}
			else {
				v.push_back(nullptr);
			}
		}
		dish.push_back(v);
	}
	system("cls");
	displayDish();
}
	
void Dish::displayDish() {
	for (int y = 0; y < cols; y++) {
		for (int x = 0; x < rows; x++) {
			if (dish[y][x] != nullptr) {
				std::cout << dish[y][x]->name;
			}
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	total = bacillusNumber + coccusNumber + SpirillumNumber;
	std::cout << "Life Cycle: " << lifeCycle << std::endl;
	std::cout << "Bacillus units: " << bacillusNumber << " Coccus units: " << coccusNumber << " Spirillum units: " << SpirillumNumber << std::endl;
	std::cout << "total number of bacteria: " << total << "  died: " << died;
	_getch();
}

void Dish::cleanDeadBacteria() {
	for (int y = 0; y < cols; y++) {
		for (int x = 0; x < rows; x++) {
			if (dish[y][x] != nullptr) {
				if (dish[y][x]->name == 'B' && dish[y][x]->aliveStatus == 0) {
					bacillusNumber--;
					died++;
					delete dish[y][x];
					dish[y][x] = nullptr;
				}
				else if (dish[y][x]->name == 'C' && dish[y][x]->aliveStatus == 0) {
					coccusNumber--;
					died++;
					delete dish[y][x];
					dish[y][x] = nullptr;
				}
				else if (dish[y][x]->name == 'S' && dish[y][x]->aliveStatus == 0) {
					SpirillumNumber--;
					died++;
					delete dish[y][x];
					dish[y][x] = nullptr;
				}
			}
		}
	}
}

std::vector <Bacteria*> Dish::nearby(int size_, int radius, int y, int x) {
	std::vector <Bacteria*> nearbyV;
	for (int y_ = std::max(0, y - radius); y_ < std::min(size_, y + radius); y_++) {
		for (int x_ = std::max(0, x - radius); x_ < std::min(size_, x + radius); x_++) {
			if (dish[y_][x_] != nullptr &&  (y != y_ || x != x_)) {
				nearbyV.push_back(dish[y_][x_]);
			}
		}
	}
	return nearbyV;
}

std::vector< int> Dish::nearbyEmpty(int size_, int radius, int y, int x) {
	std::vector < int> nearbyEmptyV;
	for (int y_ = std::max(0, y - radius); y_ < std::min(size_, y + radius); y_++) {
		for (int x_ = std::max(0, x - radius); x_ < std::min(size_, x + radius); x_++) {
			if (dish[y_][x_] == nullptr && y != y_ && x != x_) {
				nearbyEmptyV.push_back(y_);
				nearbyEmptyV.push_back(x_);
			}
		}
	}
	return nearbyEmptyV;
}