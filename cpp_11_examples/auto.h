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

namespace PP_CPP11 {
    // variables
    auto var = 11; // int
    auto fl = 20.3f; // float
    auto dl = 120.4; // double
    auto cond = (5 > 2); // bool
    
    // return types
    auto print() { // expecting a void
        cout << "hello pabitra\n";
    }
    
    auto isTrue() { // expecting a bool
        return (3 < 10);
    }
    
    auto fp = isTrue(); // fp should have a type bool
    
    // logic execution
    bool execute() {
        print();
        if (isTrue()) {
            cout << "returning bool correctly\n";
        }
        return true;
    }
}

#endif /* auto_h */
