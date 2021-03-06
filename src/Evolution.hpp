#pragma once

#include <memory>
#include <vector>

#include "Problem.hpp"
#include "Result.hpp"
#include "FileReader.hpp"
#include "Snapshot.hpp"

class Evolution
{
public:
	Evolution(int pop_size, int gen, float px, float pm, int tour, std::string filename);
	void step();
    Snapshot take_snapshot();
    std::string get_output_filename();

protected:
	bool mutation_condition();
	bool crossover_condition();
    //return indexes of selected results
    std::pair<int, int> selection();
    int tournament();
    void crossover();
    void mutation();
    void warnings();

    std::vector<int> random_selection(int how_many);

    std::vector<float> best_worst_average();

    void delete_file_content();

	int pop_size;
    int gen;
    float px;
    float pm;
    int tour;
    std::string filename;

    std::vector<std::shared_ptr<Result>> population;
    Problem problem;
};
