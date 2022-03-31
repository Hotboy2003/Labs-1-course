#include <iostream>

class Matrix
{
public:
	//Конструктор
	Matrix(int n, int m)
	{
		m_n = n;
		m_m = m;
		m_mat = new int* [m_n];
		for (int i = 0; i < m_n; i++)
			m_mat[i] = new int[m_m];
	}

	friend std::istream& operator>>(std::istream& in, Matrix& mat);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& mat);
	
private:
	int m_n, m_m;
	int** m_mat;

	//Деструктор
	~Matrix()
	{
		std::cout << "Destructor" << std::endl;
		for (int i = 0; i < m_n; i++)
			delete[] m_mat[i];
		delete m_mat;
	}

	int getN() const { return m_n; }
	int getM() const { return m_m; }
	int get(int i, int j) const { return m_mat[i][j]; }
	void set(int i, int j, T data) { m_mat[i][j] = data; }


	//Конструктор копирования
	Matrix& operator=(const Matrix& mat)
	{
		std::cout << "Oprator =" << std::endl;

		m_n = mat.m_n;
		m_m = mat.m_m;

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = mat.m_mat[i][j];

		return *this;
	}

	//Оператор присваивания
	Matrix& operator=(const Matrix& mat)
	{
		std::cout << "Operator =" << std::endl;

		m_n = mat.m_n;
		m_m = mat.m_m;

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = mat.m_mat[i][j];
	}
	
	Matrix operator*(const Matrix& mat)
	{
		Matrix tmp(3,4);
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < mat.m_m; j++)
			{
				int sum = 0;
				for (int k = 0; k < m_m; k++)
					sum += m_mat[i][k] * m_mat[i][j];
				tmp.set(i, j, sum);
			}

			return tmp;
	}
};

//Оператор перегрузки ввода
std::istream& operator>>(std::istream& in, Matrix& mat)
{
	for (int i = 0; i < mat.m_n; i++)
		for (int j = 0; j < mat.m_m; j++)
			in >> mat.m_mat[i][j];
	return in;
}

//Оператор перегрузки вывода
std::ostream& operator<<(std::ostream& out, const Matrix& mat)
{
	out << mat.m_n << std::endl;
	for (int i = 0; i < mat.m_n; i++)
	{
		for (int j = 0; j < mat.m_m; j++)
			out << mat.m_mat[i][j] << " ";
		out << std::endl;
	}
	return out;
}

int main()
{
	return 0;
}