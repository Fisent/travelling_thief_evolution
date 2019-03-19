#pragma once

struct Snapshot
{
	Snapshot(int worst_cost, int best_cost, float average_cost):
		worst_cost(worst_cost), best_cost(best_cost), average_cost(average_cost){}

	~Snapshot(){
		if(not saved)
			std::cout << "WARNING! snapshot wasn't written to file " << filename << '\n';
	}


	//TODO implement function that appends snapshot to file

	std::string filename;
	int best_cost;
	int worst_cost;
	float average_cost;

	bool saved{false};
};