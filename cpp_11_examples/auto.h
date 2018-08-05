//
//  auto.h
//  cpp_11_examples
//
//  Created by Padhy, Pabitra on 16/06/18.
//  Copyright © 2018 Padhy, Pabitra. All rights reserved.
//

#ifndef auto_h
#define auto_h

#include <iostream>
using namespace std;

/*
 Type Inference:
 ---------------
 Use of 'auto' could also be done with return types of a function, which was introduced in C++14.
 That would be covered in the 'cpp_14_examples' project.
 */
namespace PP_CPP11 {
    // NOTE:
    // something like - auto var; // throws a compilation error
    // because compiler can't do type inference.
    
    // 1. Type Inference while defining a variable.
    auto var = 11; // int
    auto fl = 20.3f; // float
    auto dl = 120.4; // double
    auto cond = (5 > 2); // bool
    
    // 2. Type Inferece with return types
    bool doSomething() {
        cout << "hello pabitra\n";
        return true;
    }
    auto boolVal = doSomething(); // fp should have a type bool
    
    // 3. Type Inference with Class members
    class Foo {
    public:
        // auto mVar = 10; // Compilation Error : auto not allowed in non-static class members. (also need to make it const)
        static const auto mVal = 10; // NOTE: no benefit in using this
        void print() { cout << mVal << endl; }
    };
    
    // logic execution
    bool execute() {
        if (boolVal) {
            cout << "returning bool correctly\n";
        }
        Foo f;
        f.print();
        return true;
    }
}

#endif /* auto_h */
