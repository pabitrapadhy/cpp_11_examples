//
//  ranged_based_for_loop.h
//  cpp_11_examples
//
//  Created by Padhy, Pabitra on 17/06/18.
//  Copyright © 2018 Padhy, Pabitra. All rights reserved.
//

// https://www.geeksforgeeks.org/range-based-loop-c/

#ifndef ranged_based_for_loop_h
#define ranged_based_for_loop_h

#include <iostream>
#include <vector>
#include <map>
using namespace std;

namespace PP_CPP11 {
    // NOTE: this uses the uniform initialization & initializers list of C++11
    std::vector<int> mylist = {1,2,3,4,5};
    std::map<std::string, int> mymap = {{"a", 97}, {"b", 98}, {"c", 99}, {"d", 100}};
    
    // logic execution
    bool execute() {
        for (auto& i : mylist) {
            i *= 2;
            cout << "\nitem : " << i;
        }
        
        for (auto i : {1,2,3,4,5}) {
            cout << "\nitem : " << i;
        }
        
        for (auto it : mymap) {
            cout << "\n map key is: " << it.first << ", map value is: " << it.second;
        }
        return true;
    }
}

#endif /* ranged_based_for_loop_h */
