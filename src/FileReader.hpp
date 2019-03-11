#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/lexical_cast.hpp>

#include "City.hpp"
#include "Item.hpp"
#include "Problem.hpp"

class Problem;

namespace file_reader
{

const std::string FILE_PREFIX = "../problem_files/";

std::string read_nth_line(std::string filename, int N);
int read_number_of_cities(std::string filename);
int read_number_of_items(std::string filename);
std::vector<City> read_cities(std::string filename);
std::vector<Item> read_items(std::string filename);
Problem read_problem(std::string filename);

template <typename T>
T read_nth_line_value(std::string filename, int N)
{
	std::string line = read_nth_line(filename, N);

	std::vector<std::string> results;
	boost::split(results, line, [](char c){return c == '\t' or c == ' ';});

	auto result = results.back();
	boost::algorithm::trim(result);

	return boost::lexical_cast<T>(result);
}

std::string read_sth(std::string filename);
std::vector<int>* file_content_to_vector(std::string input);

}// namespace file_reader
