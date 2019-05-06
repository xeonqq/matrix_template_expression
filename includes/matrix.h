#ifndef MATRIX_H
#define MATRIX_H
#include <sum.h>
#include <string>
#include <array>
#include <algorithm>

#define DEBUG 0

template <typename T>
void log(T&& s)
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
		const Array& row() const {return array;}
		Self operator+(const Self& other)
		{
			const auto sum = array + other.array;
			return Self{sum};
		}
	private:
		 Array array;

};

template <typename T, size_t dim_w>
std::ostream& operator<<(std::ostream& os, const Matrix<T, dim_w>& mat)
{
	log("specalized");
	std::for_each(mat.row().begin(), mat.row().end(), [&os](const auto& v){os<<v<<",";});
	return os;
}


#endif /* MATRIX_H */
