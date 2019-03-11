#include "FileReader.hpp"
#include "Problem.hpp"
#include <iostream>


namespace file_reader
{

std::string read_sth(std::string filename)
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

std::string read_nth_line(std::string filename, int N)
{
    std::ifstream myfile;
    std::string line;
    myfile.open(FILE_PREFIX + filename);
    for(int i = 0; i < N; i++)
    {
        std::getline(myfile, line);
    }
    return line;
}

int read_number_of_cities(std::string filename)
{
	std::string output;
	std::string line;
	std::ifstream myfile;
	myfile.open(FILE_PREFIX + filename);
	for(int i = 0; i < 2; i++)
	{
		std::getline(myfile, line);
	}
	std::string dimension_line;
	std::getline(myfile, dimension_line);

	std::vector<std::string> results;
	boost::split(results, dimension_line, [](char c){return c == '\t';});

	auto result = results.back();
	boost::algorithm::trim(result);

	return boost::lexical_cast<int>(result);
}

int read_number_of_items(std::string filename)
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
    boost::split(results, dimension_line, [](char c){return c == ' ' or c == '\t';});

    auto result = results.back();
    boost::algorithm::trim(result);

    return boost::lexical_cast<int>(result);
}

std::vector<City> read_cities(std::string filename)
{
    std::string output;
    std::string line;
    std::ifstream myfile;
    myfile.open(FILE_PREFIX + filename);
    for(int i = 0; i < 10; i++)
    {
        std::getline(myfile, line);
    }

    int number_of_cities = read_number_of_cities(filename);
    std::vector<City> cities;
    std::string current_line;

    for(int i = 0; i < number_of_cities; i++)
    {
        std::getline(myfile, current_line);
        std::vector<std::string> split_results;
        boost::split(split_results, current_line, boost::is_any_of("\t "));

        for(auto& result : split_results) {boost::algorithm::trim(result);}
        int id = i + 1;
        int x = boost::lexical_cast<float>(split_results.at(1));
        int y = boost::lexical_cast<float>(split_results.at(2));

        assert(id == boost::lexical_cast<int>(split_results.at(0)));

        cities.push_back(City(id, x, y));
    }

    return cities;
}

std::vector<Item> read_items(std::string filename)
{
    std::string output;
    std::string line;
    std::ifstream myfile;
    myfile.open(FILE_PREFIX + filename);
    // skip headers in file
    for(int i = 0; i < 10; i++)
    {
        std::getline(myfile, line);
    }
    //skip cities
    int number_of_cities = read_number_of_cities(filename);
    for(int i = 0; i < number_of_cities; i++)
    {
        std::getline(myfile, line);
    }
    std::getline(myfile, line);
    
    int mnumber_of_items = read_number_of_items(filename);
    std::vector<Item> items_result;

    std::string current_line;
    for(int i = 0; i < mnumber_of_items; i++)
    {
        std::getline(myfile, current_line);
        std::vector<std::string> split_results;
        boost::split(split_results, current_line, boost::is_any_of("\t "));

        for(auto& result : split_results) {boost::algorithm::trim(result);}
        int id = i + 1;
        int profit = boost::lexical_cast<int>(split_results.at(1));
        int weight = boost::lexical_cast<int>(split_results.at(2));
        int city_id = boost::lexical_cast<int>(split_results.at(3));

        items_result.push_back(Item(id, profit, weight, city_id));
    }

    return items_result;
}

Problem read_problem(std::string filename)
{
    int dimension = read_number_of_cities(filename);
    int number_of_items = read_number_of_items(filename);
    int capacity;
    float min_speed;
    float max_speed;


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