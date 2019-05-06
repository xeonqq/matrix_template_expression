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

template <typename Value, size_t dim_w>
class Matrix
{
	using Array=std::array<Value, dim_w>;
	using Self=Matrix<Value, dim_w>;
	public:
		Matrix(Array array):array{std::move(array)} {}

		template <typename Exp1, typename Exp2>
		Matrix(Sum<Exp1, Exp2> sum) //copy constructor
		{
			logger("Copy Ctr in Matrix");
			for (size_t i=0;i<array.size();++i)
			{
				array[i] = sum(i);
			}
		}

		const Array& row() const {return array;}

		auto operator() (size_t i) const
		{
			return array[i];
		}

	private:
		 Array array;

};


template <typename T1, typename T2>
class Sum
{
	public:
		Sum(const T1& exp1, const T2& exp2):exp1{exp1}, exp2{exp2} {}

		auto operator() (size_t i) const
		{
			return exp1(i) + exp2(i);
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



template <typename T, size_t dim_w>
std::ostream& operator<<(std::ostream& os, const Matrix<T, dim_w>& mat)
{
	logger("specalized");
	std::for_each(mat.row().begin(), mat.row().end(), [&os](const auto& v){os<<v<<",";});
	return os;
}


#endif /* MATRIX_H */
