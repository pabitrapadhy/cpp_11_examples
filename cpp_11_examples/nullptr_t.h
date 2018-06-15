//
//  nullptr_t.h
//  cpp_11_examples
//
//  Created by Padhy, Pabitra on 16/06/18.
//  Copyright © 2018 Padhy, Pabitra. All rights reserved.
//

#ifndef nullptr_t_h
#define nullptr_t_h

#include <iostream>
#include <cstddef> // NOTE: contains the nullptr_t

using namespace std;

namespace PP_CPP11 {
    std::nullptr_t np1;
    std::nullptr_t np2;
    /* comparing nullptr_t doesn't seem to be working in clang, but it's working in gcc. */
    
    // NOTE: comparing nullptr_t with >= or <= always gives true
    // whereas comparing with > or < gives false.
    // void compare_nullptr_t() {
    //     if (np1 <= np2) {
    //         cout << "can compare with <=\n";
    //     }

    //     if (np1 >= np2) {
    //         cout << "can compare with >=\n";
    //     }

    //     if (np1 < np2) {
    //         cout << "cannot compare with <\n";
    //     }

    //     if (np1 > np2) {
    //         cout << "cannot compare with >\n";
    //     }
    // }
    
    void compare_nullptr_nullptr_t() {
        char* ch = np1; // NOTE: same as ch = nullptr or ch = NULL
        if (ch == nullptr) {
            cout << "can compare nullptr_t with nullptr\n";
        }
        
        if (ch == NULL) {
            cout << "can compare nullptr_t with NULL\n";
        }
    }
    
    // NOTE: USE OF nullptr_t
    
    void func(int* ip) {
        cout << "overload integer pointer\n";
    }
    
    void func(float* fp) {
        cout << "overload floating pointer\n";
    }
    
    // NOTE: This is required for overloading functions
    // if both takes a pointer as argument.
    // in that case there would be two candidate for the call, if nullptr is passed
    // and keeping the below function solves it.
    void func(std::nullptr_t np) { // C++ 11
        cout << "overload nullptr\n";
    }
    
    bool execute() {
        // compare_nullptr_t();
        compare_nullptr_nullptr_t();
        
        func(nullptr);
        return true;
    }
}

#endif /* nullptr_t_h */
