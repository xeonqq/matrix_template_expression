#ifndef MATRIX_H
#define MATRIX_H
#include <string>
#include <array>
#include <algorithm>
#include <iostream>

#define DEBUG 0

template <typename T>
void logger(T&& s)
{
#if DEBUG
	std::cout << s << std::endl;
#endif
}

template <typename T1, typename T2>
class Sum;

template <typename Value, size_t dim_rows, size_t dim_cols>
class Matrix
{
	using Array=std::array<Value, dim_rows*dim_cols>;
	using Self=Matrix<Value, dim_rows, dim_cols>;
	public:
	Matrix(Array array):array{std::move(array)} {}

	template <typename Exp1, typename Exp2>
		Matrix(Sum<Exp1, Exp2> sum) //copy constructor
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

	const Array& row() const {return array;}

	auto operator() (size_t row, size_t col) const
		{
			return array[row*dim_cols + col];
		}

	private:
		 Array array;

};


template <typename T1, typename T2>
class Sum
{
	public:
		Sum(const T1& exp1, const T2& exp2):exp1{exp1}, exp2{exp2} {}

		auto operator() (size_t row, size_t col) const
		{
			return exp1(row, col) + exp2(row, col);
		}
	private:
		const T1& exp1;
		const T2& exp2;

};

template<typename Exp1, typename Exp2>
Sum<Exp1, Exp2>
operator + (const Exp1& exp1, const Exp2& exp2)
{
	logger("Construct Sum");
	return Sum<Exp1, Exp2>(exp1, exp2);
}



template <typename T, size_t dim_rows, size_t dim_cols>
std::ostream& operator<<(std::ostream& os, const Matrix<T, dim_rows, dim_cols>& mat)
{
	std::for_each(mat.row().begin(), mat.row().end(), [&os](const auto& v){os<<v<<",";});
	return os;
}


#endif /* MATRIX_H */
