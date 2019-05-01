#include<matrix.h>

#include<sum.h>
Matrix::Matrix(int v):value{v}{}

	template<typename T>
Sum<Matrix, T> Matrix::operator+(const T& mat)
{
	return Sum<Matrix, T>(*this, mat);
}

