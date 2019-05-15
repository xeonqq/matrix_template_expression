#ifndef MATRIX_H
#define MATRIX_H
#include <string>
#include <array>
#include <algorithm>
#include <iostream>

#define DEBUG 0

template <typename T>
constexpr void logger(T&& s)
{
#if DEBUG
	std::cout << s << std::endl;
#endif
}

template <typename T1, typename T2, typename Operator>
class BinaryOpExpression;


template <typename Value, size_t dim_rows, size_t dim_cols>
class Matrix
{
	using Array=std::array<Value, dim_rows*dim_cols>;
	using Self=Matrix<Value, dim_rows, dim_cols>;
	public:
	constexpr Matrix(Array array):array{std::move(array)} {}

	template <typename Exp1, typename Exp2, typename Operator>
	constexpr Matrix(BinaryOpExpression<Exp1, Exp2, Operator> sum) //copy constructor
	{
		logger("Copy Ctr in Matrix");
		for (size_t row=0;row<dim_rows;++row)
		{
			for (size_t col=0;col<dim_cols;++col)
			{
				array[row * dim_cols + col] = sum(row, col);
			}
		}
	}

	constexpr Array& row() const {return array;}

	constexpr auto operator() (size_t row, size_t col) const
		{
			return array[row*dim_cols + col];
		}
	private:
		 Array array;

};


template <typename T1, typename T2, typename Operator>
class BinaryOpExpression
{
	public:
		constexpr BinaryOpExpression(const T1& exp1, const T2& exp2, const Operator& op):exp1{exp1}, exp2{exp2}, op{op}{}

		constexpr auto operator() (size_t row, size_t col) const
		{
			return op(exp1(row, col), exp2(row, col));
		}
	private:
		const T1& exp1;
		const T2& exp2;
		const Operator& op;

};

template<typename Exp1, typename Exp2, typename Operator=std::plus<>>
BinaryOpExpression<Exp1, Exp2, Operator>
constexpr operator + (const Exp1& exp1, const Exp2& exp2)
{
	logger("Construct + BinaryOpExpression");
	return BinaryOpExpression<Exp1, Exp2, Operator>(exp1, exp2, std::plus<>());
}

template<typename Exp1, typename Exp2, typename Operator=std::minus<>>
BinaryOpExpression<Exp1, Exp2, Operator>
constexpr operator - (const Exp1& exp1, const Exp2& exp2)
{
	logger("Construct - BinaryOpExpression");
	return BinaryOpExpression<Exp1, Exp2, Operator>(exp1, exp2, std::minus<>());
}

template <typename T, size_t dim_rows, size_t dim_cols>
std::ostream& operator<<(std::ostream& os, const Matrix<T, dim_rows, dim_cols>& mat)
{
	std::for_each(mat.row().begin(), mat.row().end(), [&os](const auto& v){os<<v<<",";});
	return os;
}


#endif /* MATRIX_H */
