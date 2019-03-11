#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/lexical_cast.hpp>

#include "City.hpp"
#include "Item.hpp"

namespace file_reader
{

const std::string FILE_PREFIX = "../problem_files/";

int read_number_of_cities(std::string filename);
int read_number_of_items(std::string filename);
std::vector<City> read_cities(std::string filename);
std::vector<Item> read_items(std::string filename);

std::string read_sth(std::string filename);
std::vector<int>* file_content_to_vector(std::string input);

}// namespace file_reader
