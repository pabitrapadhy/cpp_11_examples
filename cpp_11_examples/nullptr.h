//
//  nullptr.h
//  cpp_11_examples
//
//  Created by Padhy, Pabitra on 15/06/18.
//  Copyright © 2018 Padhy, Pabitra. All rights reserved.
//

#ifndef nullptr_h
#define nullptr_h

#include <iostream>
using namespace std;

/*
 NOTE:
 The implementation of NULL can be different in different compilers
 Also, could be different with OS or the choice of language C or CPP
 So, NULL can behave differently, it's sometimes unpredictable like
 one of the below condition with long.
 
 clang 9.2 implementation : taken from xcode
 -------------------------------------------
 #ifdef __cplusplus
 #  if !defined(__MINGW32__) && !defined(_MSC_VER)
 #    define NULL __null
 #  else
 #    define NULL 0
 #  endif
 #else
 #  define NULL ((void*)0)
 #endif
 #ifdef __cplusplus
 
 */

namespace PP_CPP11 {
    void func(int num) {
        cout << "pabitra: integer overload func\n";
    }

    void func(char ch) {
        cout << "pabitra: character overload func\n";
    }

    void func(float fp) {
        cout << "pabitra: float overload func\n";
    }

    void func(double db) {
        cout << "pabitra: double overload func\n";
    }

    void func(bool bl) {
        cout << "pabitra: bool overload func\n";
    }
    
    // NOTE: exception for "long" and "signed long" encountered.
    // this is not considered an overload for some reason
    // that means the func(NULL) is not ambigious here
    // https://stackoverflow.com/questions/50881135/casting-null-to-long-is-not-ambigious
    void func(long int st) {
        cout << "pabitra: overload func\n";
    }
    
    void func(int* ptr) {
        cout << "pabitra: integer pointer overload func\n";
    }
    
    bool execute() {
        // NOTE: NULL can be implicitly converted or compared into integral types
        // i.e NULL can be a pointer and an integral type both.
        func(NULL);
        
        // NOTE: It is best to use nullptr
        // because use of NULL gives different behaviour as per compiler implementation of it.
        // so, if we use nullptr, it will always make sure to call the func(int* ptr)
        
        // func(nullptr);
        return true;
    }
}

#endif /* nullptr_h */
