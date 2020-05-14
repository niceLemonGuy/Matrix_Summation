#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <sstream>

using namespace std;

class Matrix {
public:
    Matrix() {
        matrix.clear();
        rows = 0;
        cols = 0;
    }

    Matrix(const int& num_rows, const int& num_cols) {
        if(num_rows < 0 || num_cols < 0) {
            throw out_of_range("");
        }
        matrix.clear();
        matrix.resize(num_rows * num_cols);
        rows = num_rows;
        cols = num_cols;
    }

    void Reset(const int& num_rows, const int& num_cols) {
        if(num_rows < 0 || num_cols < 0) {
            throw out_of_range("");
        }
        matrix.clear();
        matrix.resize(num_rows * num_cols);
        rows = num_rows;
        cols = num_cols;
    }

    int At(const int& row_num, const int& col_num) const {
        if(row_num < 0 || col_num < 0) {
            throw out_of_range("");
        }
        if(row_num > rows - 1 || col_num > cols - 1) {
            throw out_of_range("");
        }
        return matrix[(row_num * cols) + col_num];
    }

    int& At(const int& row_num, const int& col_num) {
        if(row_num < 0 || col_num < 0) {
            throw out_of_range("");
        }
        if(row_num > rows - 1 || col_num > cols - 1) {
            throw out_of_range("");
        }
        return matrix[(row_num * cols) + col_num];
    }

    int GetNumRows(void) const {
        return rows;
    }

    int GetNumColumns(void) const {
        return cols;
    }

private:
    vector<int> matrix;
    int rows;
    int cols;
};

istream& operator >> (istream& stream, Matrix& matrix) {
    int rows, cols;
    stream >> rows >> cols;
    matrix.Reset(rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            stream >> matrix.At(i, j);
        }
    }
    return stream;
}

ostream& operator << (ostream& stream, const Matrix& matrix) {
    stream << matrix.GetNumRows() << " "
           << matrix.GetNumColumns() << endl;
    for(int i = 0; i < matrix.GetNumRows(); i++) {
        for(int j = 0; j < matrix.GetNumColumns(); j++) {
            stream << matrix.At(i, j);
            if((j + 1) < matrix.GetNumColumns()) stream << " ";
        }
        if((i + 1) < matrix.GetNumRows()) stream << endl;
    }
    return stream;
}

bool operator == (const Matrix& lhs, const Matrix& rhs) {

    if((lhs.GetNumRows() == 0 || lhs.GetNumColumns() == 0) &&
       (rhs.GetNumRows() == 0 || rhs.GetNumColumns() == 0)) {
        return true;
    } else if(lhs.GetNumRows() == rhs.GetNumRows() &&
       lhs.GetNumColumns() == rhs.GetNumColumns()) {
        for(int i = 0; i < lhs.GetNumRows(); i++) {
            for(int j = 0; j < lhs.GetNumColumns(); j++) {
                if(lhs.At(i, j) != rhs.At(i, j)) {
                    return false;
                }
            }
        }
    } else {
        return false;
    }
    return true;
}

Matrix operator + (const Matrix& lhs, const Matrix& rhs) {
    if((lhs.GetNumRows() == 0 || lhs.GetNumColumns() == 0) &&
        (rhs.GetNumRows() == 0 || rhs.GetNumColumns() == 0)) {
        Matrix new_matrix;
        return new_matrix;
    }else if(lhs.GetNumRows() == rhs.GetNumRows() &&
       lhs.GetNumColumns() == rhs.GetNumColumns()) {
        Matrix new_matrix(lhs.GetNumRows(), lhs.GetNumColumns());
        for(int i = 0; i < lhs.GetNumRows(); i++) {
            for(int j = 0; j < lhs.GetNumColumns(); j++) {
                new_matrix.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
            }
        }
        return new_matrix;
    } else {
        throw invalid_argument("");
    }
}

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}

