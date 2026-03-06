namespace cppnum {

class Matrix {
private:
    std::vector<std::vector<double>> data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(r, std::vector<double>(c, 0));
    }

    // Matrix multiplication
    Matrix matmul(const Matrix& other) {
        if (cols != other.rows) throw std::invalid_argument("Matrix dimensions do not match for multiplication.");
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Transpose of the matrix
    Matrix transpose() {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }

    // Determinant (for simplicity, only for 2x2 and 3x3 matrices)
    double determinant() {
        if (rows != cols) throw std::invalid_argument("Determinant is only defined for square matrices.");
        if (rows == 2) {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        } else if (rows == 3) {
            return data[0][0]*(data[1][1]*data[2][2] - data[1][2]*data[2][1]) - 
                   data[0][1]*(data[1][0]*data[2][2] - data[1][2]*data[2][0]) + 
                   data[0][2]*(data[1][0]*data[2][1] - data[1][1]*data[2][0]);
        }
        throw std::invalid_argument("Determinant can only be calculated for 2x2 or 3x3 matrices.");
    }

    // Scalar multiplication
    Matrix multiply(double scalar) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    // Eigenvalues placeholder (functionality to be implemented)
    std::vector<double> eigenvalue() {
        // Placeholder for actual eigenvalue calculation
        return std::vector<double>();
    }

    // Trace of the matrix
    double trace() {
        if (rows != cols) throw std::invalid_argument("Trace is only defined for square matrices.");
        double sum = 0.0;
        for (int i = 0; i < rows; ++i) {
            sum += data[i][i];
        }
        return sum;
    }
};

} // namespace cppnum
