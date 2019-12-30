//
//  StringSort.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/29.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class StringSort {
    
static bool compare(const string &s1, const string &s2) {
    string str1 = s1 + s2;
    string str2 = s2 + s1;
    return str1 < str2;
}
    
public:
    string PrintMinNumber(vector<int> numbers) {
        string result;
        
        if (numbers.empty()) {
            return result;
        }
        
        vector<string> strNum;
        for (int i = 0; i < numbers.size(); i++) {
            strNum.push_back(to_string(numbers[i]));
        }
        sort(strNum.begin(), strNum.end(), compare);
        for (int i = 0; i < strNum.size(); i++) {
            result.append(strNum[i]);
        }
        
        cout << result << "\n";
        return result;
    }
};
