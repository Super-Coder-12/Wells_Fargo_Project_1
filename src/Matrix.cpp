#include <iostream>
#include <vector>
#include <fstream>
#include "Matrix.h"
using namespace std;


// Access element at (row, col)
double& Matrix::operator()(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("Matrix indices are out of range");
        }
        return data[row][col];
}

const double& Matrix::operator()(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("Matrix indices are out of range");
        }
        return data[row][col];
}

// Get number of rows
int Matrix::getRows() const { return rows; }

// Get number of columns
int Matrix::getCols() const { return cols; }
    
// 2. Read matrix dimensions and a constant from a text file
Matrix Matrix::readFromTextFile(const std::string& filename) {
   std::ifstream file(filename);
   if (!file.is_open()) {
            throw std::runtime_error("Could not open text file");
   }

    int rows, cols;
    double constant;

    // Read the data
    if (!(file >> rows >> cols >> constant)) {
	throw std::runtime_error("Invalid file format");
     }

     Matrix matrix(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix(i, j) = constant; // Initialize all elements to the constant
            }
        }

        return matrix;
}
    
// 3. add two matrix element-wise.
Matrix Matrix::operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions must agree for addition");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] + other(i, j);
            }
        }
        return result;
 }

// Print the matrix
void Matrix::print() const {
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
}

