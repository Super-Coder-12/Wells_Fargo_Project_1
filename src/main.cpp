#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <Matrix.h>

int main() {
    Matrix mat1(2, 2);
    mat1(0, 0) = 1.0;
    mat1(0, 1) = 2.0;
    mat1(1, 0) = 3.0;
    mat1(1, 1) = 4.0;

    Matrix mat2(2, 2);
    mat2(0, 0) = 5.0;
    mat2(0, 1) = 6.0;
    mat2(1, 0) = 7.0;
    mat2(1, 1) = 8.0;

    Matrix result = mat1 + mat2;

    std::cout << "Matrix 1:" << std::endl;
    mat1.print();

    std::cout << "Matrix 2:" << std::endl;
    mat2.print();

    std::cout << "Result (Matrix 1 + Matrix 2):" << std::endl;
    result.print();
    
    try {
        // Assume "input.txt" contains:
        // 2 2 3.5
        Matrix mat = Matrix::readFromTextFile("input.txt");
        
        std::cout << "Matrix initialized from text file:" << std::endl;
        mat.print();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    
    return 0;
}
