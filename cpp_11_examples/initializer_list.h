//
//  initializer_list.h
//  cpp_11_examples
//
//  Created by Padhy, Pabitra on 16/06/18.
//  Copyright © 2018 Padhy, Pabitra. All rights reserved.
//

/* https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
NOTE:
It could be a best practise to use Uniform Initialisation policy of C++ 11
because it is optimal, solves issue for C++'s most vexing parse
https://stackoverflow.com/questions/180172/default-constructor-with-empty-brackets
i.e Base() may be treated as a function, but Base{} is always an object.

Base()                   -> Base{}
Base(x, y)               -> Base{x, y}
Base* obj = new Base()   -> Base* obj = new Base{};
*/

#ifndef initializer_list_h
#define initializer_list_h

#include <iostream>
using namespace std;

namespace PP_CPP11 {
    // basic types
    int num{};
    char ch{};
    float ft{};
    double dt{};
    bool bt{};
    
    
    /* USE OF INITIALZER LIST IS AVAILABLE FOR DATA MEMBERS OF A CLASS */
    
    // CASE: 1. Use of initializer list in constructors
    class Base {
    public:
        // member variables
        int p, q;
        
        // member functions
        /* another way of defining the constructor
        Base(int x, int y) {
            p = x;
            q = y;
        }
        */
        Base(int x, int y) : p(x), q(y) {}
        void print() {
            cout << "\npabitra: printing value of Base object: " << p << " and " << q;
        }
    };
    
    // CASE: 2. Use of initializer list to avoid <member variable hiding>
    class Basic {
    public:
        // member variables
        int x, y;
        
        // member functions
        /* NOTE: doing the below will make the instance variable to hide
         as the member variable name and the formal parameters name are same.
        Basic(int x, int y) {
            x = x;
            y = y;
        }
        */
        Basic(int x, int y) : x(x), y(y) {};
        void print() {
            cout << "\npabitra: printing value of Basic object: " << x << " and " << y;
        }
        
    };
    
    // CASE: 3. Use of initializer list to initalize <non-static const data members>
    class Test {
    public:
        // member variable
        const int num;
        const std::string data;
        
        // member function
        /* cannot be done in the below way
        Test(int n, std::string d) {
            num = n;
            data = d;
        }
        */

        // NOTE: this could only be performed with a constructor
        // see the below commented lines for issue with normal functions.
        Test(int num, std::string data) : num(num), data(data) {}
        
        // NOTE: cannot do : Only constructors take base initializers.
        // void init(int n, std::string d) : num(n), data(d) {}
    };
    
    // CASE: 4. Use of initializer list to initalize <reference type data members>
    class Test2 {
    public:
        // member variables
        int& num;
        
        // member functions
        /* cannot be done in the below way
        Test2(int& n) {
            num = n;
        }
        */
        Test2(int& n) : num(n) {}
        void print() {
            cout << "\npabitra: printing reference variable value: " << num;
            cout << "\npabitra: printing address of variable : " << &num;
        }
    };
    
    Test2* tp; // NOTE: kept in global scope to access num outside it's scope
    
    // CASE: 5. Use of initializer list to initalize <object of class not having default constructor
    // i.e having a constructor other than default constructor>
    class NonBasic {
    public:
        // member variable
        // NOTE: contains a variable of type class Basic, which has only a parameterized constructor defined.
        // so, in order to create an object of that class, it can only be done using initializer list.
        Basic bRef;
        
        // member function
        /* cannot be done in the below way
        NonBasic(int x, int y) {
            bRef(x, y);
        }
        */
        NonBasic(int x, int y) : bRef(x, y) {}
    };
    
    // CASE: 6. Use of initializer list to initalize <object of base class not having default constructor>
    class Derived : public Base {
    public:
        // member function
        Derived() : Base(10, 20) {}
    };
    
    // logic execution
    bool execute() {
        // 1. Uniform Initialization
        
        // prints everything as 0
        // char is converted to null, so it prints blank.
        cout << "\nInteger: " << num;
        cout << "\nChar: " << ch;
        cout << "\nFloat: " << ft;
        cout << "\nDouble: " << dt;
        cout << "\nBool: " << bt;
        
        // 2. Initializer List
        Base obj1{10, 20}; // created a object in stack memory.
        Basic obj2{10, 20}; // avoids member variable hiding using initializer list.
        Test obj3{10, "abc"}; // NOTE: non-static const data members must be initialized with initializer list.
        
        // NOTE: num is a variable in stack memory
        // since, we are keeping the address of the local variable as reference (within our Test class data member)
        // that means, even if we can't access the variable (num) by name, outside the scope of the execute()
        // we have it's address and as long as that is not taken by someone else, the value would still be there in the memory.
        int num = 10;
        cout << "\npabitra: printing address of local num : " << &num;
        tp = new Test2{num};
        
        NonBasic nbObj{10, 20};
        nbObj.bRef.print(); // to check if Basic object is initialized properly or not.
        
        // NOTE: Derived drObj() was treated as function declaration.
        // This is c++'s most vexing parse, details can be found below in the link.
        // https://stackoverflow.com/questions/180172/default-constructor-with-empty-brackets
        Derived drObj{};
        drObj.print();
        
        return true;
    }
}

#endif /* initializer_list_h */
