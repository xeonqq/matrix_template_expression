#ifndef MATRIX_H
#define MATRIX_H
#include<sum.h>

//template <typename T>
//class Expression
//{
//	public:
//		Expression(const T& exp):exp(exp) {}
//		void eval() {return exp.eval()}
//	private:
//		T exp;
//};
//
//template <typename T1, typename T2>
//class Sum
//{
//	public:
//		Sum(const T1& exp1, const T2& exp2):exp1{exp1}, exp2{exp2} {}
//		void eval() {exp1.eval() + exp2.eval();}
//	private:
//		T1 exp1;
//		T2 exp2;
//
//};



template <typename T1, typename T2>
class Sum;
class Matrix
{
	public:
		Matrix(int v);
		template<typename T>
		Sum<Matrix, T> operator+(const T& mat);
		int getValue() const {return value;}

		template<typename Nested_T>
		Matrix operator+=(const Matrix& sum)
		{
			return value += sum.value;
		}
	private:
		int value;

};


Matrix::Matrix(int v):value{v}{}

	template<typename T>
Sum<Matrix, T> Matrix::operator+(const T& mat)
{
	return Sum<Matrix, T>(*this, mat);
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat)
{
	return os << mat.getValue() << std::endl;
}


template <typename T1, typename T2>
class Sum
{
public:
	Sum(const T1& lhs, const T2& rhs):lhs{lhs}, rhs{rhs}{}

	template<typename T>
	Sum<Sum<T1, T2>, T> operator+(const T& mat) const
	{
		return Sum<Sum<T1, T2>, T>(*this, mat);
	}

private:
	const T1& lhs;
	const T2& rhs;
};



//using MatrixE = Expression<Matrix>;
//using MatrixE = Expression<Matrix>;
#endif /* MATRIX_H */
