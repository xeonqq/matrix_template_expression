#ifndef MATRIX_H
#define MATRIX_H
#include<sum.h>

class Matrix
{
	public:
		Matrix(int v);
		int eval() const {return value;}

	private:
		int value;

};

Matrix::Matrix(int v):value{v}{}

template <typename T>
class Expression
{
	public:
		Expression(const T& exp):exp(exp) {}
		int eval() const {return exp.eval();}
	private:
		const T& exp;
};

template <typename T1, typename T2>
class Sum
{
	public:
		Sum(const T1& exp1, const T2& exp2):exp1{exp1}, exp2{exp2} {}
		int eval() const {return exp1.eval() + exp2.eval();}
	private:
		const T1& exp1;
		const T2& exp2;

};

template<typename Exp1, typename Exp2>
Sum<Exp1, Exp2>
operator + (const Exp1& exp1, const Exp2& exp2)
{
	return Sum<Exp1, Exp2>(exp1, exp2);
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const T& mat)
{
	return os << mat.eval() << std::endl;
}


using MatrixE = Expression<Matrix>;
using MatrixE = Expression<Matrix>;


#endif /* MATRIX_H */
