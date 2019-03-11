#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/lexical_cast.hpp>


#include <iostream>

namespace file_reader
{

const std::string FILE_PREFIX = "../problem_files/";

int is_not_digit(int ch)
{
	return not isdigit(ch);
}

std::string read(std::string filename)
{
	std::string output;
    std::string line;
    std::ifstream myfile;
    myfile.open(FILE_PREFIX + filename);
    while(std::getline(myfile, line)){
        output += line;
    }
    myfile.close();
    return output;
}

int read_number_of_cities(std::string filename)
{
	std::string output;
	std::string line;
	std::ifstream myfile;
	myfile.open(FILE_PREFIX + filename);
	for(int i = 0; i < 3; i++)
	{
		std::getline(myfile, line);
	}
	std::string dimension_line;
	std::getline(myfile, dimension_line);

	std::vector<std::string> results;
	boost::split(results, dimension_line, [](char c){return c == ' ';});

	auto result = results.back();
	boost::algorithm::trim(result);

	return boost::lexical_cast<int>(result);
}

std::vector<int>* file_content_to_vector(std::string input)
{
	input += "   ";
    auto result = new std::vector<int>;
    for(int i = 0; i<input.size(); i++){
        std::string number = "";
        if(std::isdigit(input.at(i))){
            int temp_i = i;
            while(std::isdigit(input.at(temp_i)) && temp_i<input.size()){
                number += input.at(temp_i);
                temp_i++;
            }
            result->push_back(std::stoi(number));
            i = temp_i;
        }
    }
    return result;
}

}// namespace file_reader