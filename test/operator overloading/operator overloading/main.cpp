//
//  main.cpp
//  operator overloading
//
//  Created by David Phume on 2024/07/14.
//
#include <iostream>
using namespace std;


class area {
    
public:
    

    int room;
    
    area (int r)
    
    : room(r)
    
    {
        
    
//    room = width + length + height;
//      
//        cout << " Area is " << room <<endl;
    }
    
//    void print(){
//        
//        cout << " Area is " << room <<endl;
//    }
    
    
    friend ostream &operator<< (ostream &os, ostream const &obj1);
    
};

    ostream &operator<< (ostream &os, ostream const &obj1){
        os << obj1.room;
        return os;
    
}



int main(){
    
    area a1(8);

    
    cout << a1 <<endl;
    
    
    return 0;
}


