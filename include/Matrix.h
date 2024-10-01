#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <vector>
#include <fstream>
#include "Matrix.h"
using namespace std;

class Matrix {
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<double>(cols, 0.0));
    }

    // Access element at (row, col)
    double& operator()(int row, int col);

    const double& operator()(int row, int col) const; 

    // Get number of rows
    int getRows() const;

    // Get number of columns
    int getCols() const;
    
    // 2. Read matrix dimensions and a constant from a text file
    static Matrix readFromTextFile(const std::string& filename);
    
    // 3. add two matrix element-wise.
    Matrix operator+(const Matrix& other) const;

    // 4. Print the matrix
    void print() const;

private:
    int rows, cols;
    std::vector<std::vector<double> > data;
};


#endif
