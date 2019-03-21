#include <iostream>

#include "Evolution.hpp"
#include "Settings.hpp"

void do_the_evolution(Settings settings)
{
	std::cout << "Starting the evolution\n";
	std::cout << settings;

	Evolution e{settings.pop_size, settings.gen, settings.px, settings.pm, settings.tour, settings.filename};

	for(int i = 0; i < settings.gen; i++)
	{
		if(i % 10 == 0)
			std::cout << "Progress: " << (i/float{settings.gen}) * 100 << '%' << '\n';
		e.step();
		auto snap = e.take_snapshot();
		snap.save(e.get_output_filename());
	}
}

int main(){
	auto settings = max();
	for(auto setting : settings)
		do_the_evolution(setting);
}
