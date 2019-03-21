#pragma once

#include <gtest/gtest.h>
// #include <gmock/gmock.h>

#include "../src/Result.hpp"

using namespace ::testing;

class ResultTestable : public Result
{
public:
	ResultTestable(int N) : Result(N) {

	}
	using Result::flip;
	using Result::fix;
	using Result::crossover;

	int getN(){
		return N;
	}
	std::vector<int>& getRes(){
		return res;
	}

	void setRes(std::vector<int> res){
		this->res = res;
	}
};

bool no_duplicates(std::vector<int>& vec)
{
	std::set<int> s{};
	for(auto e : vec) {s.insert(e);}
	return vec.size() == s.size();
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

TEST(ResultShould, beCreated)
{
	ResultTestable r{10};
}

TEST(ResultShould, flip)
{
	std::vector<int> res{1,2,3,4,5,6,7,8,9,10};
	ResultTestable result{10};
	result.setRes(res);
	result.flip(0, 9);
	// ASSERT_THAT(result.getRes(), ElementsAre(10,2,3,4,5,6,7,8,9,1));

	result.setRes({ 6, 8, 4, 9, 1, 2, 7, 3, 5, 0 });
	result.flip(0, 8);
	// ASSERT_THAT(result.getRes(), ElementsAre(5, 8, 4, 9, 1, 2, 7, 3 ,6, 0));
}

TEST(ResultShould, mutate)
{
	for(int i = 0; i < 1000; i++)
	{
		ResultTestable result{10};
		std::vector<int> res_before_mutation = result.getRes();
		result.mutate();
		std::vector<int> res_after_mutation = result.getRes();
		ASSERT_NE(res_after_mutation, res_before_mutation);
	}
}

TEST(ResultShould, fixItself)
{
	ResultTestable broken_result{10};
	broken_result.setRes({1,1,3,4,5,6,7,8,9,10});
	broken_result.fix();
	ASSERT_TRUE(no_duplicates(broken_result.getRes()));

	broken_result.setRes({1,1,1,1,1,1,1,1,1,1});
	broken_result.fix();
	ASSERT_TRUE(no_duplicates(broken_result.getRes()));

	for(int i = 0; i < 1000; i++)
	{
		const int N{20};

		ResultTestable result{N};
		std::vector<int> maybe_broken_res{};
		for(int i = 0; i < N; i++) {maybe_broken_res.push_back(random_int(N) + 1);}
		result.setRes(maybe_broken_res);
		result.fix();
		ASSERT_TRUE(no_duplicates(result.getRes()));
	}
}

TEST(ResultShould, crossoverInCornerCases)
{
	ResultTestable result1{10};
	ResultTestable result2{10};

	result1.setRes({10,9,8,7,6,5,4,3,2,1});
	result2.setRes({1,2,3,4,5,6,7,8,9,10});

	auto r1 = result1.crossover(result2, 0);
	auto crossovered1 = *static_cast<ResultTestable*>(&r1);
	// ASSERT_THAT(crossovered1.getRes(), ElementsAre(1,2,3,4,5,6,7,8,9,10));

	auto r2 = result1.crossover(result2, 10);
	auto crossovered2 = *static_cast<ResultTestable*>(&r2);
	// ASSERT_THAT(crossovered2.getRes(), ElementsAre(10,9,8,7,6,5,4,3,2,1));
}

TEST(ResultShould, crossoverInComplexCases)
{
	ResultTestable result1{10};
	ResultTestable result2{10};

	result1.setRes({5,4,3,2,1,10,9,8,7,6});
	result2.setRes({1,2,3,4,5,6,7,8,9,10});

	auto r1 = result1.crossover(result2, 5);
	auto crossovered1 = *static_cast<ResultTestable*>(&r1);
	// ASSERT_THAT(crossovered1.getRes(), ElementsAre(5,4,3,2,1,6,7,8,9,10));

	auto r2 = result2.crossover(result1, 5);
	auto crossovered2 = *static_cast<ResultTestable*>(&r2);
	// ASSERT_THAT(crossovered2.getRes(), ElementsAre(1,2,3,4,5,10,9,8,7,6));
}