// Example program
#include <iostream>
#include <string>
#include <matrix.h>

#define SIZE 2000

using Matrix2f = Matrix<double, SIZE>;

using namespace std;
int main()
{
	std::array<double, SIZE> aa;
	aa.fill(20.12);

	std::array<double, SIZE> bb;
	bb.fill(31.2);

	std::array<double, SIZE> cc;
	cc.fill(48.8);

	Matrix2f mat_a{std::move(aa)};
	Matrix2f mat_b{std::move(bb)};
	Matrix2f mat_c{std::move(cc)};

	//const auto sum = mat_a + mat_b + mat_c;
	const Matrix2f sum = mat_a + mat_b + mat_c + mat_a + mat_a + mat_a + mat_a;
	logger(sum);
}

