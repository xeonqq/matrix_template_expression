#ifndef MATRIX_H
#define MATRIX_H
#include <sum.h>
#include <string>
#include <array>
#include <algorithm>

#define DEBUG 0

template <typename T>
void log(T s)
{
#if DEBUG
	std::cout << s << std::endl;
#endif
}

template <typename T, size_t dim>
std::array<T, dim> operator+(const std::array<T, dim>& a1, const std::array<T, dim>& a2)
{
	using Array=std::array<T, dim>;
	Array a;
	for (typename Array::size_type i = 0; i < a1.size(); ++i)
		a[i] = a1[i] + a2[i];
	return a;
}

template <typename Value, size_t dim_w>
class Matrix
{
	using Array=std::array<Value, dim_w>;
	using Self=Matrix<Value, dim_w>;
	public:
		Matrix(Array array):array{std::move(array)} {}
		const Self& eval() const {
			log("eval in Matrix");
			return *this;}
		const Array& row() const {return array;}
		Self operator+(const Self& other)
		{
			auto sum = array + other.array;
			return Self{sum};
		}
	private:
		 Array array;

};


template <typename T>
class Expression
{
	public:
		Expression(T exp):exp(std::move(exp)) {} //copy once in construction
		auto eval() const {return exp.eval();}
		operator auto () const {return exp.eval();}
	private:
		T exp;
};

template <typename T1, typename T2>
class Sum
{
	public:
		Sum(const T1& exp1, const T2& exp2):exp1{exp1}, exp2{exp2} {}
		auto eval() const
		{
			log("eval in Sum");
			return exp1.eval() + exp2.eval();}
	private:
		const T1& exp1;
		const T2& exp2;

};

template<typename Exp1, typename Exp2>
Expression<Sum<Exp1, Exp2>>
operator + (const Exp1& exp1, const Exp2& exp2)
{
	using ExpT=Expression<Sum<Exp1, Exp2>>;

	return ExpT(Sum<Exp1, Exp2>(exp1, exp2));
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const Expression<T>& mat)
{
	log("Expression ");
	return os << mat.eval() << std::endl;
}

template <typename T, size_t dim_w>
std::ostream& operator<<(std::ostream& os, const Matrix<T, dim_w>& mat)
{
	log("specalized");
	std::for_each(mat.row().begin(), mat.row().end(), [&os](const auto& v){os<<v<<",";});
	return os;
}


#endif /* MATRIX_H */
