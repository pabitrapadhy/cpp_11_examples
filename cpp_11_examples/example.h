//
//  example.h
//  cpp_11_examples
//
//  Created by Padhy, Pabitra on 15/06/18.
//  Copyright © 2018 Padhy, Pabitra. All rights reserved.
//

#ifndef example_h
#define example_h

#include <iostream>

using namespace std;

namespace PP_CPP11 {
    // variable declaration
    int num = 1;
    
    // function declaration
    void print(int num) {
        cout << "pabitra: test print " << num << "\n";
    }
    
    // logic execution
    bool execute() {
        print(num);
        return true;
    }
}

#endif /* example_h */
