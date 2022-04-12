#pragma once
#include <iostream>
namespace AO
{
	template<typename T, int N, int M>
	class Matrix
	{
		// Абстракция
		// Инкапсуляция
		// Использование вне класса
	public:
		// Конструктор
		Matrix<T,N,M>();

		// Конструктор копирования
		Matrix<T,N,M>(const Matrix<T,N,M>& mat);

		// Присваивание
		Matrix<T, N, M>& operator=(const Matrix<T, N, M>& mat);

		// Оператор сложения
		Matrix<T, N, M> operator+(const Matrix<T, N, M>& mat);

		// Оператор сложения  C += A <=> C = C + A
		Matrix<T, N, M> operator+=(const Matrix<T, N, M>& mat);

		// Оператор умножения
		Matrix<T, N, M> operator*(const Matrix<T, N, M>& mat);

		// Деструктор
		~Matrix<T, N, M>();

		// friend - позволяет функции иметь доступ к private полям/методам класса
		template<typename T, int N, int M>
		friend std::istream& operator>>(std::istream& os, Matrix<T,N,M>& mat);
		template<typename T, int N, int M>
		friend std::ostream& operator<<(std::ostream& os, const Matrix<T,N,M>& mat);

		int Det();

		Matrix<T, N, M> transposition();

		Matrix<T, N, M> inv();

		// Использование внутри класса
	private:
		int m_n, m_m;		// Поле
		T m_mat[N][M]; // Matrix
	};
}
