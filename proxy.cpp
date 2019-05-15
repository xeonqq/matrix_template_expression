// Example program
#include <iostream>
#include <string>
#include <matrix.h>
#include <utility>

#define ROWS 2
#define COLS 2
#define SIZE ROWS*COLS

using Matrix2f = Matrix<double, ROWS, COLS>;

using namespace std;

int main()
{
	constexpr std::array<double, SIZE> aa = {1,2,3,7};
	constexpr std::array<double, SIZE> bb = {1,2,3,5};
	constexpr std::array<double, SIZE> cc = {1,2,3,6};


	constexpr Matrix2f mat_a{std::move(aa)};
	constexpr Matrix2f mat_b{std::move(bb)};
	constexpr Matrix2f mat_c{std::move(cc)};

	constexpr Matrix2f sum = mat_a + mat_b - mat_c;
	logger(sum);
}

