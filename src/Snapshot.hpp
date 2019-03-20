#pragma once

#include <fstream>

const std::string OUTPUT_PREFIX{"../output/"};

//file structure: 3 columnst
// best_cost worst_cost average_cost

struct Snapshot
{
	Snapshot(int worst_cost, int best_cost, float average_cost):
		worst_cost(worst_cost), best_cost(best_cost), average_cost(average_cost){}

	bool save(std::string filename)
	{
		std::ofstream myfile;
		myfile.open(OUTPUT_PREFIX + filename,  std::ios_base::app);
		if(not myfile)
			return false;
		myfile << best_cost << " " << worst_cost << " " << average_cost << '\n';
		myfile.close();
		saved = true;
		return true;
	}

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