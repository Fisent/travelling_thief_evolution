#pragma once

#include "../src/Settings.hpp"
#include "../src/Evolution.hpp"

TEST(LauncherShould, runOneEvolution)
{
	auto settings = get_test_setting().at(0);

	Evolution e{settings.pop_size, settings.gen, settings.px, settings.pm, settings.tour, settings.filename};

	for(int i = 0; i < 10; i++)
	{
		e.step();
	}
}