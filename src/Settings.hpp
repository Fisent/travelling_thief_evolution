#pragma once1

#include <iostream>

const std::string PREFIX{"../problem_files/"};

struct Settings
{
	Settings(int pop_size, int gen, float px, float pm, int tour, std::string filename):
		pop_size(pop_size), gen(gen), px(px), pm(pm), tour(tour), filename(PREFIX + filename){}

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

std::vector<int> pop_sizes{100};
std::vector<int> gens{1000};
std::vector<float> pxs{0.7};
std::vector<float> pms{0.1};
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
	return settings;
}

std::vector<Settings> get_test_setting(){
	return {Settings{100, 10, 0.7, 0.1, 10, "trivial_0.ttp"}};
}

std::ostream& operator<<(std::ostream& o, Settings& settings)
{
	o << "Settings: ";
	o << "pop_size=" << settings.pop_size << ", ";
	o << "number_of_generations(gen)=" << settings.gen << ", ";
	o << "px=" << settings.px << ", ";
	o << "pm=" << settings.pm << ", ";
	o << "tour=" << settings.tour << '\n';

	return o;
}