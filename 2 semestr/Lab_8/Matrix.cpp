#include "Matrix.hpp"

namespace AO
{
	template<typename T, int N, int M>
	Matrix<T,N,M>::Matrix()
	{
		std::cout << "Constructor" << std::endl;
		m_n = N;
		m_m = M;
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = 0;
	}

	// Конструктор копирования
	template<typename T, int N, int M>
	Matrix<T,N,M>::Matrix(const Matrix<T,N,M>& mat)
	{
		std::cout << "Copy constructor" << std::endl;

		m_n = mat.m_n;
		m_m = mat.m_m;

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = mat.m_mat[i][j];
	}

	// Присваивание
	template<typename T, int N, int M>
	Matrix<T,N,M>& Matrix<T,N,M>::operator=(const Matrix<T,N,M>& mat)
	{
		std::cout << "Operator =" << std::endl;

		m_n = mat.m_n;
		m_m = mat.m_m;

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = mat.m_mat[i][j];

		return *this;
	}

	// Оператор сложения
	template<typename T, int N, int M>
	Matrix<T,N,M> Matrix<T,N,M>::operator+(const Matrix<T,N,M>& mat) {
		std::cout << "operator+" << std::endl;
		Matrix<T,N,M> tmp;
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
		return tmp;
	}

	// Оператор сложения  C += A <=> C = C + A
	template<typename T, int N, int M>
	Matrix<T,N,M> Matrix<T,N,M>::operator+=(const Matrix<T,N,M>& mat) 
	{
		std::cout << "operator+=" << std::endl;
		Matrix<T,N,M> tmp;
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
		return tmp;
	}

	// Оператор умножения
	template<typename T, int N, int M>
	Matrix<T,N,M> Matrix<T,N,M>::operator*(const Matrix<T,N,M>& mat)
	{
		std::cout << "operator*" << std::endl;
		Matrix<T,N,M> tmp;
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				tmp.m_mat[i][j] = 0;
				for (int k = 0; k < m_m; k++)
				{
					tmp.m_mat[i][j] += m_mat[i][k] * mat.m_mat[k][j];
				}
			}
		}
		return tmp;
	}
	// Деструктор
	template<typename T, int N, int M>
	Matrix<T,N,M>::~Matrix()
	{
		std::cout << "Destructor" << std::endl;
	}

	// Перегрузка оператора ввода
	template<typename T, int N, int M>
	std::istream& operator>>(std::istream& in, Matrix<T,N,M>& mat)
	{
		for (int i = 0; i < mat.m_n; i++)
			for (int j = 0; j < mat.m_m; j++)
				in >> mat.m_mat[i][j];
		return in;
	}

	// Перегрузка оператора вывода
	template<typename T, int N, int M>
	std::ostream& operator<<(std::ostream& out, const Matrix<T,N,M>& mat)
	{
		out << "Matrix " << mat.m_n << "x" << mat.m_m << std::endl;
		for (int i = 0; i < mat.m_n; i++) {
			for (int j = 0; j < mat.m_m; j++)
				out << mat.m_mat[i][j] << " ";
			out << std::endl;
		}
		return out;
	}

	// Определитель матрицы
	template<typename T, int N, int M>
	int Matrix<T,N,M>::Det()
	{
		if ((m_n == 2) && (m_m == 2))
		{
			return (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]);
		}
		else if ((m_n == 3) && (m_m == 3))
		{
			return (m_mat[0][0] * (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) - (m_mat[0][1] * (m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2])) + (m_mat[0][2] * (m_mat[1][0] * m_mat[2][1] - m_mat[1][1] * m_mat[2][0])));
		}
		else
		{
			std::cout << "\nOperation not work\n";
		}
	}

	//Транспонирование матрицы
	template<typename T, int N, int M>
	Matrix<T,N,M> Matrix<T,N,M>::transposition()
	{
		Matrix<T,N,M> tmp;
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				tmp.m_mat[i][j] = m_mat[j][i];
			}
		}
		return tmp;
	}
	//Обратная матрица
	template<typename T, int N, int M>
	Matrix<T,N,M> Matrix<T,N,M>::inv()
	{
		Matrix<T,N,M> tmp;
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				tmp.m_mat[i][j] = 0;
			}
		}
		if ((m_n == 2 && m_m == 2) || (m_n == 3 && m_m == 3))
		{
			int det = Det();
			if (det == 0) {
				std::cout << "Обратной матрицы не существует, Det = 0, (определитель равен 0)" << std::endl;
				return tmp;
			}
			if (m_n == 2) {
				tmp.m_mat[0][0] = m_mat[1][1] / det;
				tmp.m_mat[0][1] = -m_mat[0][1] / det;
				tmp.m_mat[1][0] = -m_mat[1][0] / det;
				tmp.m_mat[1][1] = m_mat[0][0] / det;
				return tmp;
			}
			if (m_n == 3) {
				tmp.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) / det;
				tmp.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[2][1] * m_mat[0][2]) / det;
				tmp.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[1][1] * m_mat[0][2]) / det;
				tmp.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2]) / det;
				tmp.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[2][0] * m_mat[0][2]) / det;
				tmp.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[1][0] * m_mat[0][2]) / det;
				tmp.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[2][0] * m_mat[1][1]) / det;
				tmp.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[2][0] * m_mat[0][1]) / det;
				tmp.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]) / det;
				return tmp;
			}
		}
		else
		{
			std::cout << "\nOperation not work\n";
		}
	}
}