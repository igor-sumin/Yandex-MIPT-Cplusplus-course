#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
class Matrix {
private:
	int cols;
	int rows;
	vector<vector<int>> matr;

public:
	Matrix(int new_rows = 0, int new_cols = 0) {
		// if(new_rows < 0 || new_cols < 0) {
		// 	throw out_of_range("out_of_range");
		// }

		// rows = new_rows;
		// cols = new_cols;

		Reset(new_rows, new_cols);
	}

	// Принимает два целочисленных параметра, которые задают новое количество строк и столбцов матрицы соответственно. 
	// Меняет размеры матрицы на заданные и обнуляет все её элементы.
	void Reset(int new_rows, int new_cols) {
		if(new_rows < 0 || new_cols < 0) {
			throw out_of_range("out_of_range");
		} else if (new_rows == 0 || new_cols == 0) {
			new_rows = new_cols = 0;
		}

		rows = new_rows;
		cols = new_cols;

		matr.assign(rows, vector<int>(cols, 0));
	}

	// Возвращает значение в соответствущей ячейке матрицы
	int& At(int new_rows, int new_cols) {
		// if(new_rows >= rows && new_cols < 0 || new_cols >= cols && new_cols < 0) {
		// 	throw out_of_range("out_of_range");
		// }

		// return matr[new_rows][new_cols];

		return matr.at(new_rows).at(new_cols);
	}

	int At(int new_rows, int new_cols) const {
		// if(new_rows >= rows && new_cols < 0 || new_cols >= cols && new_cols < 0) {
		// 	throw out_of_range("out_of_range");
		// }

		// return matr[new_rows][new_cols];

		return matr.at(new_rows).at(new_cols);
	}

	int GetNumRows() const {
		return rows;
	}

	int GetNumColumns() const {
		return cols;
	}

	friend istream& operator>>(istream& stream, Matrix& mt) {
		int rows, cols;
		stream >> rows >> cols;

		mt.Reset(rows, cols);

		for(size_t i = 0; i < rows; i++) {
			for(size_t j = 0; j < cols; j++) {
				stream >> mt.At(i, j);		
			}
		}

		return stream;
	}

	friend ostream& operator<<(ostream& stream, const Matrix& mt) {
		stream << mt.rows << " " << mt.cols << endl;
		for(size_t i = 0; i < mt.rows; i++) {
			for(size_t j = 0; j < mt.cols; j++) {
				if(j > 0) {
					stream << " ";
				}
				// stream << mt.matr[i][j];		
				stream << mt.At(i, j);
			} stream << endl;
		}

		return stream;
	}

	bool operator==(const Matrix& op2) const {
		if(rows != op2.rows || cols != op2.cols) {
			return false;
		}

		// for(size_t i = 0; i < rows; i++) {
		// 	for(size_t j = 0; j < cols; j++) {
		// 		if(matr[i][j] != op2.matr[i][j]) {
		// 			return false;
		// 		}
		// 	}
		// }

		for(size_t i = 0; i < rows; i++) {
			for(size_t j = 0; j < cols; j++) {
				if(At(i, j) != op2.At(i, j)) {
					return false;
				}
			}
		}

		return true;
	}

	Matrix operator+(const Matrix& op2) const {
		if(rows != op2.rows || cols != op2.cols) {
			throw invalid_argument("invalid_argument");
		}

		Matrix new_matr(rows, cols);
		for(size_t i = 0; i < rows; i++) {
			for(size_t j = 0; j < cols; j++) {
				new_matr.At(i, j) = At(i, j) + op2.At(i, j);
			}
		}

		return new_matr;
	}

};

// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

int main() {
	try {
		Matrix one;
		Matrix two;

		cin >> one >> two;
		cout << one + two << endl;

	} catch(const invalid_argument& ia) {
		cout << ia.what() << endl;
	} catch(const out_of_range& oor) {
		cout << oor.what() << endl;
	} catch(const exception& ex) {
		cout << ex.what() << endl;
	}

	
  return 0;
}
