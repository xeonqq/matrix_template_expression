// Example program
#include <iostream>
#include <string>
#include <matrix.h>

using namespace std;
int main()
{
	Matrix2f a{{1,2}};
	Matrix2f b{{2,3}};
	Matrix2f c{{3,4}};
	MatrixE mat_a{a};
	MatrixE mat_b{b};
	MatrixE mat_c{c};

	//const auto sum = mat_a + mat_b + mat_c;
	const Matrix2f sum = mat_a + mat_b + mat_c;

	cout << sum << endl;
}

