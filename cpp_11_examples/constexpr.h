//
//  constexpr.h
//  cpp_11_examples
//
//  Created by Padhy, Pabitra on 15/07/18.
//  Copyright © 2018 Padhy, Pabitra. All rights reserved.
//

#ifndef constexpr_h
#define constexpr_h

#include <iostream>
using namespace std;

/*
 RULE OF THUMB:
 -------------
 constexpr      : value of the variable will not change, initializer is known at compile-time.
 const          : value of the variable will not change, initializer is NOT known at compile-time.
 */
namespace PP_CPP11 {
    // calculates the value of the function/expression in compile-time.
    // so when running it in run-time, it returns the value of the function directly.
    // therefore, it is an optimization technique.
    void doSomething() {}
    
    constexpr int multiply(int a, int b) {
        // doSomething(); // NOTE: compilation error - a constexpr func, can only call other constexpr func.
        return a*b;
    }
    
    int getValue() {
        return 100;
    }
    
    class Test {
    public:
        // NOTE: since the object is a const object,
        // we need to promise the compiler that none of it's function will modify the object.
        // so we have to mark getArea() as 'const'
        // Also, to calculate the value of the expression in compile-time, it's constexpr.
        constexpr int getArea(int l, int b) const {
            return l*b;
        }
    };
    
    bool execute() {
        constexpr int result = multiply(2, 3); // NOTE: in this case, optimization works.
        constexpr Test obj{}; // NOTE: object will be created in compile time.
        cout << obj.getArea(10, 20); // the value of getArea() is calculated in compile-time.
        
        // Use of 'const' vs 'constexpr'
        constexpr int a = 10; // NOTE: No change in value, Initialier known at compile time (use constexpr)
        // constexpr int b = getValue();
        const int b = getValue(); // NOTE: it can't be constexpr, because initializer is not known at compile time.
        
        return true;
    }
}

#endif /* constexpr_h */
