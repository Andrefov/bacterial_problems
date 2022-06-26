#include "bacteriaInterface.h"

std::vector<int> Bacteria::clone(std::vector<int> nearbyEmpty_) {
	int index = 0;
	std::vector<int>coordinates;

	if (nearbyEmpty_.size() > 2) {
		std::random_device plagueSpreader;
		std::mt19937 rng(plagueSpreader());
		std::uniform_int_distribution<std::mt19937::result_type> indexOfNewBacteria(0, (nearbyEmpty_.size() - 1));
		index = indexOfNewBacteria(rng);
		if (index % 2 == 0 && index < nearbyEmpty_.size()) {
			coordinates.push_back(nearbyEmpty_[index]);
			coordinates.push_back(nearbyEmpty_[index + 1]);
			return coordinates;
		}
		else if (index % 2 == 1 && index < nearbyEmpty_.size()) {
			coordinates.push_back(nearbyEmpty_[index - 1]);
			coordinates.push_back(nearbyEmpty_[index]);
			return coordinates;
		}
	}
	else {
		coordinates = nearbyEmpty_;
		return coordinates;
	}
	return coordinates;
}