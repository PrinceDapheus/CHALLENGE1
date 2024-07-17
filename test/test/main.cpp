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


class computer{
    
public:
    int size = 3;
    int *arr = new int [size];
    
    
    
    //Default constructor
    
    computer(int input = 0){
        
        int size = 3;

        
        for(int x = 0 ; x < size ; x++){
            arr[x] = input;
        }
        
    }
  
    
    
    
    //Copy constructor
    
    computer (computer const &obj1){
        
        int size = 3;
        for(int y = 0 ; y < size ; y++){
           arr[y] =  obj1.arr[y] ;
        }
        
    }
    
    
    //Print out
    
    void print(){
        
        for (int i = 0 ; i < size ; i++) {
            cout << arr[i] << endl;
        }
        
        cout << "----------" <<endl;
        
    }
    
    //Operator overloading+
    
    computer operator+ (computer const &obj2){
        int size = 3;
        
        computer result;
        for (int x = 0 ; x < size ; x++){
            result.arr[x] =  arr[x] + obj2.arr[x] ;
        }
        
        return result;
    }
    
    //Operator overloading =  
    
    computer operator= (computer const &obj3){
        int size = 3;
        //computer result;
        for (int x = 0 ; x < size ; x++){
            this->arr[x] = obj3.arr[x];
        }
      
        return *this;
    }
    
    
    //Destructor
    
    ~ computer (){
        
        delete [] arr;
        
        cout << "memory deleted!" <<endl;
        
    }
    

    
    
    
    
    
};

int main(){
    
    
    computer c1(10);
    computer c2(5);
    computer c3;
    
    c3 = c1 + c2;
    
    c1.print();
    c2.print();
    c3.print();

    
    
    return 0;
}

