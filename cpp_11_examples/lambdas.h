//
//  lambdas.h
//  cpp_11_examples
//
//  Created by Padhy, Pabitra on 29/07/18.
//  Copyright © 2018 Padhy, Pabitra. All rights reserved.
//

#ifndef lambdas_h
#define lambdas_h

#include <iostream>
#include <functional>

using namespace std;

namespace PP_CPP11 {
    // logic execution
    std::function<int (int, int)> callback() {
        return
        [] (int x, int y) -> int {
            return (x + y);
        };
    }
    
    int respond(const std::function<int (int, int)>& cb) {
        return cb(10, 20);
    }
    
    bool execute() {
        // NOTE:
        // -----
        // [] is called "lambda introducer"
        // [=, &] is called "capture" -- "&" means capture by reference and "=" means capture by value
        
        int val1 = 10;
        int val2 = 20;
        
        // 1. lambda without arguments
        [] {
            cout << "Hello Pabitra" << endl;
        } (); // NOTE: calling lambda with the () invocation
        
        // 2. lambda with arguments
        [] (int number) {
            cout << "Number is: " << number << endl;
        } (100);
        
        // 3. lambda with name and no arguments
        auto lambda = [] {
            cout << "Hello Again" << endl;
        };
        lambda(); // NOTE: local object call.
        
        // 4. lambda with name and arguments
        auto lmbd = [] (const std::string& name) {
            cout << "String is: " << name << endl;
        };
        lmbd("abcd");
        
        // 5. lambda with return type
        // NOTE: wont' work without the () even if it's taking no arguments.
        auto lbd = [] () -> int {
            return (1 > 2) ? 10 : 20;
        };
        cout << lbd() << endl;
        
        // 6. lambda with arguments and return type
        auto lbda = [] (int x, int y) -> bool {
            return (x != y) ? true : false;
        };
        cout << std::boolalpha << lbda(10, 20) << endl;
        
        // 7. lambda with capture everything by value
        auto lambValue = [=] {
            cout << val1 << endl;
        };
        lambValue(); // NOTE: cannot change the value of val1, it is non-mutable.
        
        // 8. lambda with capture everything by reference
        auto lambRef = [&] {
            val2++;
            cout << val2 << endl;
        };
        lambRef();
        
        // 9. lambda with capture specific variables by value or reference.
        auto lambValOrRef = [&, val2] {
            val1++;
            // val2++; // NOTE: everything except val2 is accessed by reference, only val2 is by value.
        };
        lambValOrRef();
        
        // 10. returning lambda as return type
        // NOTE: so to return the local object, it need to be contained by some container
        // std::function<> does this task, it can contain a lambda.
        auto lambdaReceived = callback();
        cout << lambdaReceived(val1, val2) << endl;
        
        // 11. passing a lambda as argument
        auto cb = [] (int x, int y) -> int {
            cout << "Callback Triggerred : " << endl;
            return (x + y);
        };
        int value = respond(cb);
        cout << "response value is: " << value << endl;
        
        return true;
    }
}

#endif /* lambdas_h */
