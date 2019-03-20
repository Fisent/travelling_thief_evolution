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
		if(i % 100 == 0)
			std::cout << "Progress: " << i/10 << '%' << '\n';
		e.step();
		auto snap = e.take_snapshot();
		snap.save("DUPA");
	}
}

int main(){
	auto settings = get_test_setting();
	for(auto setting : settings)
		do_the_evolution(setting);

	Snapshot s1{10, 15, 0.5};
	Snapshot s2{15, 20, 1.5};

	s1.save("test.out");
	s2.save("test.out");
}
