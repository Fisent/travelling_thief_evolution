#include <gtest/gtest.h>

#include "../src/Result.hpp"

class ResultTestable : public Result
{
public:
	ResultTestable(int N) : Result(N) {

	}
	using Result::repair;

	int getN(){
		return N;
	}
	std::vector<int> getRes(){
		return res;
	}
};

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

TEST(ResultShould, mutate)
{
	ResultTestable result{10};
	std::vector<int> res_before_mutation = result.getRes();
	result.mutate();
	std::vector<int> res_after_mutation = result.getRes();
	std::cout << res_before_mutation << '\n';
	std::cout << res_after_mutation << '\n';
	ASSERT_NE(res_after_mutation, res_before_mutation);

	//TODO make result initialized with content of the file and implement mutate method
}