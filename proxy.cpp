// Example program
#include <iostream>
#include <string>
#include <matrix.h>

#define SIZE 2000

using MatrixE = Expression<Matrix<double,SIZE>>;
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

	Matrix2f a{std::move(aa)};
	Matrix2f b{std::move(bb)};
	Matrix2f c{std::move(cc)};
	MatrixE mat_a{a};
	MatrixE mat_b{b};
	MatrixE mat_c{c};

	//const auto sum = mat_a + mat_b + mat_c;
	const Matrix2f sum = mat_a + mat_b + mat_c + mat_a + mat_a + mat_a + mat_a;

	log(sum);
}

