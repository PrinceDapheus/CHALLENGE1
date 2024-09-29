//
//  main.cpp
//  test
//
//  Created by David Phume on 2024/06/17.
//
// create a dynamic array in a class
// using operator+ overloading 
// you should be able to add the objects that carry the values in arrays.

#include <iostream>
using namespace std;

class matrix {
public:
    int rows;
    int numbers;
    int value;
    int **grid;

    // Main constructor
    matrix(int input1 = 0, int input2 = 0, int input3 = 0)
    : rows(input1), numbers(input2), value(input3) {
        grid = new int*[rows];
        for (int i = 0; i < rows; i++) {
            grid[i] = new int[numbers];
            for (int j = 0; j < numbers; j++) {
                grid[i][j] = value;
            }
        }
    }

    // Copy constructor
    matrix(const matrix &obj) {
        rows = obj.rows;
        numbers = obj.numbers;
        grid = new int*[rows];
        for (int i = 0; i < rows; i++) {
            grid[i] = new int[numbers];
            for (int j = 0; j < numbers; j++) {
                grid[i][j] = obj.grid[i][j];
            }
        }
    }

    // Assignment operator
    matrix& operator=(const matrix &rhs) {
        if (this != &rhs) {  // Protect against invalid self-assignment
            // 1. Deallocate old memory
            for (int i = 0; i < rows; i++) {
                delete[] grid[i];
            }
            delete[] grid;

            // 2. Allocate new memory and copy elements
            rows = rhs.rows;
            numbers = rhs.numbers;
            grid = new int*[rows];
            for (int i = 0; i < rows; i++) {
                grid[i] = new int[numbers];
                for (int j = 0; j < numbers; j++) {
                    grid[i][j] = rhs.grid[i][j];
                }
            }
        }
        return *this;
    }

    // Addition operator
    matrix operator+(const matrix &rhs) {
        matrix result(rows, numbers, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < numbers; j++) {
                result.grid[i][j] = grid[i][j] + rhs.grid[i][j];
            }
        }
        return result;
    }

    // Print function
    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < numbers; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << "---------" << endl;
    }

    // Destructor to handle deallocation
    ~matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] grid[i];
        }
        delete[] grid;
    }
};

int main() {
    matrix m1(3, 4, 2);  // 3x4 matrix with all values set to 2
    m1.print();
    matrix m2(3, 4, 5);  // 3x4 matrix with all values set to 0
    m2.print();
    matrix m3;
    m3 = m1 + m2;
    m3.print();

    return 0;
}
