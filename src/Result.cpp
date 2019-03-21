#include "Result.hpp"

#include <set>
#include <iostream>
#include <assert.h>

void Result::mutate()
{
	int first_index = random_int(N);
	int second_index = random_int(N);
	while(first_index == second_index)
		second_index = random_int(N);
	flip(first_index, second_index);
}

void Result::flip(int first_index, int second_index)
{
	int first = res.at(first_index);
	int second = res.at(second_index);

	res.at(first_index) = second;
	res.at(second_index) = first;
}

bool Result::needs_fixing()
{
    std::set<int> s{};
    for(auto e : res) {s.insert(e);}
    return res.size() != s.size();
}

int Result::find_by_value(int value) {
    for (int i = 0; i < N; i++) {
        if (res.at(i) == (int) value)
            return i;
    }
    return -1;
}

// void Result::fix(){
//     if(not needs_fixing())
//         return;

//     for(int i = 0; i < N; i++) {
//         for(int j = N - 1; j > 0; j--){
//             int number = -2;
//             for(int k = 0; k < N; k++){
//                 if(find_by_value(k) == -1) number = k;
//             }
//             if(find_by_value(i) == find_by_value(j) && number != -2)
//                 res.at(j) = number;
//         }
//     }
// }

void Result::fix(){
    std::vector<int> not_used_cities{};
    for(int i = 0; i < N; i++)
        not_used_cities.push_back(i);
    std::set<int> to_remove_set{};
    for(auto gene : res)
        to_remove_set.insert(gene);

    std::vector<int> to_remove{};
    to_remove.assign(to_remove_set.begin(), to_remove_set.end());

    std::sort(to_remove.begin(), to_remove.end(), std::greater<int>());

    for(auto city : to_remove){
        not_used_cities.erase(not_used_cities.begin() + city);
    }

    if(not_used_cities.size() == 0)
        return;

    std::set<int> used_cities{};
    for(int i = 0; i < res.size(); i++)
    {
        int gene = res.at(i);
        if(used_cities.find(gene) != used_cities.end())
        {
            res.at(i) = not_used_cities.at(0);
            not_used_cities.erase(not_used_cities.begin());
        }
        else{
            used_cities.insert(gene);
        }
    }
}

Result Result::crossover(const Result& other, int pivot_index) const
{
    pivot_index = pivot_index == -1 ? random_int(N) : pivot_index;

    std::vector<int> child_res{};

    for(int i = 0; i < pivot_index; i++)
    {
        child_res.push_back(this->res.at(i));
    }
    for(int i = pivot_index; i < N; i++)
    {
        child_res.push_back(other.res.at(i));
    }

    assert(child_res.size() == N);

    Result result{child_res};
    result.fix();
    return result;
}
