//
//  main.cpp
//  matrix
//
// Created by David Phume on 2024/06/07.
// Matrix Class with Operator Overloading:
// Task: Create a class Matrix that can store a two-dimensional matrix of integers.
// Implement constructor, destructor, and copy constructor. Overload the + operator
// to add two matrices, and the << operator to output the matrix.

#include <iostream>
using namespace std;

int main(){
    
    
    int rows = 3;
    int numbers = 4;
    
    int **row1 = new int* [rows];
    
    
    for ( int i = 0 ; i < numbers ; i++ ){
        
        row1[i] = new int;
        
    }
    
    for (int x = 0 ; x < rows ; x++){
        
        for (int y = 1 ; y < numbers+1 ; y++){
            row1[x][y] = y;
            cout << row1[x][y] << " " ;
        }
        
        cout << endl;
    }
    
    

    
    
    return 0;
}
    
    
    
    
    



