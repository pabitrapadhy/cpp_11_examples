//
//  Array.h
//  cpp_11_examples
//
//  Created by Padhy, Pabitra on 29/07/18.
//  Copyright © 2018 Padhy, Pabitra. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <iostream>
#include <array>

using namespace std;

namespace PP_CPP11 {
    // print the  1D array
    void printArray1D(const std::array<int, 5>& container) {
        for (int i = 0; i < container.size(); ++i) {
            cout << "Array Element : " << container.at(i) << endl;
        }
    }
    
    // print the 2D array
    void printArray2D(const std::array<std::array<int, 3>, 3>& containerMD) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << containerMD.at(i).at(j) << "\t";
            }
            cout << endl;
        }
    }
    
    // functionalities test
    void testFunctionalities(const std::array<int, 5>& container) {
        // printing only the first element
        cout << "FirstElement : " << container.front() << endl; // first element of the container
        cout << "LastElement : " << container.back() << endl; // last element of the container
        cout << "Container Data : " << container.data() << endl;
        cout << "Is Empty ? : " << std::boolalpha << container.empty() << endl; // check, if container is empty
        cout << "Maximum Size : " << container.max_size() << endl; // max_size of the container
        cout << "Element at index 0 : " << container.at(0) << endl; // element at 0th index
    }
    
    // logic execution
    bool execute() {
        std::array<int, 5> container1 = {}; // NOTE: all elements are 0
        std::array<int, 5> container2;
        container2 = {1,2,3,4,5};
        
        printArray1D(container1);
        container1 = std::move(container2); // NOTE: works, if type and element count are same in both arrays.
        cout << endl << endl;
        printArray1D(container2);
        
        // test functionality
        cout << endl << endl;
        testFunctionalities(container1);
        
        // 2D array
        cout << endl << endl;
        std::array<std::array<int, 3>, 3> containerMD = { {{1,2,3}, {4,5,6}, {7,8,9}} }; // NOTE: outer brackets are uniform initializer.
        printArray2D(containerMD);
        
        return true;
    }
}

#endif /* Array_h */
