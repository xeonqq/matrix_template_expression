// Example program
#include <iostream>
#include <string>
#include <matrix.h>
#include <utility>

#define ROWS 2
#define COLS 2
#define SIZE ROWS*COLS

using Matrix2f = Matrix<double, ROWS, COLS>;
//using Array=std::array<double, SIZE>;
using Array=double[SIZE];

using namespace std;

int main()
{
	constexpr Array aa = {4,2,3,7};
	constexpr Array bb = {1,2,3,5};
	constexpr Array cc = {1,2,3,6};


	constexpr Matrix2f mat_a(aa);
	constexpr Matrix2f mat_b(bb);
	constexpr Matrix2f mat_c(cc);

	constexpr Matrix2f sum = mat_a + mat_b - mat_c;
	logger(sum);

	Matrix<double, static_cast<size_t>(sum.at(0)), static_cast<size_t>(sum.at(1))> test;
}

