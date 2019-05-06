// Example program
#include <iostream>
#include <string>
#include <matrix.h>

#define ROWS 20
#define COLS 20
#define SIZE ROWS*COLS

using Matrix2f = Matrix<double, ROWS, COLS>;

using namespace std;
int main()
{
	std::array<double, SIZE> aa;
	aa.fill(1);

	std::array<double, SIZE> bb;
	bb.fill(2);

	std::array<double, SIZE> cc;
	cc.fill(3);

	Matrix2f mat_a{std::move(aa)};
	Matrix2f mat_b{std::move(bb)};
	Matrix2f mat_c{std::move(cc)};

	const Matrix2f sum = mat_a + mat_b + mat_c;
	logger(sum);
}

