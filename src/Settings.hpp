#pragma once1

#include <iostream>

struct Settings
{
	Settings(int pop_size, int gen, float px, float pm, int tour, std::string filename):
		pop_size(pop_size), gen(gen), px(px), pm(pm), tour(tour), filename(filename){}

	int pop_size;
	int gen;
	int tour;
	float pm;
	float px;
	std::string filename;
};

std::vector<std::string> problem_filenames{
	"trivial_0.ttp",
	"trivial_1.ttp",
	"easy_0.ttp",
	"easy_1.ttp",
	"easy_2.ttp",
	"easy_3.ttp",
	"easy_4.ttp",
	"medium_0.ttp",
	"medium_1.ttp",
	"medium_2.ttp",
	"medium_3.ttp",
	"medium_4.ttp",
	"hard_0.ttp",
	"hard_1.ttp",
	"hard_2.ttp",
	"hard_3.ttp",
	"hard_4.ttp"
};

std::vector<std::string> problem_filenames_ones{
	"trivial_1.ttp",
	"easy_3.ttp",
	"medium_4.ttp",
	"hard_0.ttp",
};

std::vector<int> pop_sizes{100};
std::vector<int> gens{1000};
std::vector<float> pxs{0.5, 0.7, 0.9};
std::vector<float> pms{0.02, 0.1};
std::vector<int> tours{10};

std::vector<Settings> get_all_settings(){
	std::vector<Settings> settings{};
	for(auto pop_size : pop_sizes)
	{
		for(auto gen: gens)
		{
			for(auto px : pxs)
			{
				for(auto pm : pms)
				{
					for(auto tour : tours)
					{
						for(auto filename : problem_filenames)
						{
							settings.push_back(Settings{pop_size, gen, px, pm, tour, filename});
						}
					}
				}
			}
		}
	}
	std::cout << "Number of settings: " << settings.size() << '\n';
	return settings;
}

std::vector<Settings> get_one_from_all_files_settings()
{
	std::vector<Settings> settings{};
	for(auto pop_size : pop_sizes)
	{
		for(auto gen: gens)
		{
			for(auto px : pxs)
			{
				for(auto pm : pms)
				{
					for(auto tour : tours)
					{
						for(auto filename : problem_filenames_ones)
						{
							settings.push_back(Settings{pop_size, gen, px, pm, tour, filename});
						}
					}
				}
			}
		}
	}
	std::cout << "Number of settings: " << settings.size() << '\n';
	return settings;
}

std::vector<Settings> easy_on_parameters_settings()
{
	std::vector<Settings> settings{};
	for(auto pop_size : pop_sizes)
	{
		for(auto gen: gens)
		{
			for(auto px : pxs)
			{
				for(auto pm : pms)
				{
					for(auto tour : tours)
					{
						settings.push_back(Settings{pop_size, gen, px, pm, tour, "easy_0.ttp"});
					}
				}
			}
		}
	}
	std::cout << "Number of settings: " << settings.size() << '\n';
	return settings;
}

std::vector<Settings> medium_on_parameters_settings()
{
	std::vector<Settings> settings{};
	for(auto pop_size : pop_sizes)
	{
		for(auto gen: gens)
		{
			for(auto px : pxs)
			{
				for(auto pm : pms)
				{
					for(auto tour : tours)
					{
						settings.push_back(Settings{pop_size, gen, px, pm, tour, "medium_0.ttp"});
					}
				}
			}
		}
	}
	std::cout << "Number of settings: " << settings.size() << '\n';
	return settings;
}

std::vector<Settings> get_test_setting(){
	return {Settings{100, 1000, 0.7, 0.02, 20, "trivial_0.ttp"}};
}

std::vector<Settings> get_hard_setting(){
	return {Settings{20, 1000, 0.7, 0.02, 10, "hard_0.ttp"}};
}

std::vector<Settings> get_easy_setting(){
	return {Settings{100, 500, 0.7, 0.02, 10, "easy_0.ttp"}};
}

std::vector<Settings> zero(){
	return {Settings{100, 500, 0.7, 0, 10, "easy_0.ttp"}, {Settings{100, 500, 0.5, 0.02, 10, "easy_0.ttp"}}};
}

std::vector<Settings> max(){
	return {Settings{100, 500, 0.7, 1, 10, "easy_0.ttp"}, {Settings{100, 500, 1, 0.02, 10, "easy_0.ttp"}}};
}



std::ostream& operator<<(std::ostream& o, Settings& settings)
{
	o << "Settings: ";
	o << "pop_size=" << settings.pop_size << ", ";
	o << "number_of_generations(gen)=" << settings.gen << ", ";
	o << "px=" << settings.px << ", ";
	o << "pm=" << settings.pm << ", ";
	o << "tour=" << settings.tour << ", ";
	o << "filename: " << settings.filename << '\n';

	return o;
}