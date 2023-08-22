#include <iostream>
#include <fstream>

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    void fillMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Enter element at position " << i << " " << j << " ";
                std::cin >> data[i][j];
            }
        }
    }

    void printMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j];
            }
            std::cout << std::endl;
        }
    }

    void swap(int row1, int row2) {
        if (row1 < 0 || row1 >= rows || row2 < 0 || row2 >= rows) {
            std::cerr << "Number of row isn't matching" << std::endl;
            return;
        }

        for (int i = 0; i < cols; ++i) {
            int temp = data[row1][i];
            data[row1][i] = data[row2][i];
            data[row2][i] = temp;
        }
    }

    void PrintToFile(const std::string& filename) {
        std::ofstream File(filename);
        if (File.is_open()) {
            File << rows << " " << cols << std::endl;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    File << data[i][j] << " ";
                }
                File << std::endl;
            }
            File.close();
        }
        else {
            std::cerr << "Unable to open file " << filename << " for writing." << std::endl;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main() {
    int numRows, numCols;
    std::cout << "Enter number of rows: ";
    std::cin >> numRows;
    std::cout << "Enter number of columns: ";
    std::cin >> numCols;
    Matrix matrix(numRows, numCols);
    matrix.fillMatrix();
    std::cout << "real matrix" << std::endl;
    matrix.printMatrix();
    int row1, row2;
    std::cout << "Enter row to swap : ";
    std::cin >> row1 >> row2;
    matrix.swap(row1, row2);
    std::cout << "Matrix after swapping row " << row1 << " and " << row2 << ":" << std::endl;
    matrix.printMatrix();
    std::string filename = "matrix.txt";
    matrix.PrintToFile(filename);

    return 0;
}