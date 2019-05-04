// Example program
#include <iostream>
#include <string>
#include <matrix.h>

using namespace std;
int main()
{
	Matrix a{1};
	Matrix b{2};
	Matrix c{3};
	MatrixE mat_a{a};
	MatrixE mat_b{b};
	MatrixE mat_c{c};

	//const auto sum = mat_a + mat_b + mat_c;
	const auto sum = MatrixE{a} + mat_b + mat_c;

	cout << sum << endl;
}

