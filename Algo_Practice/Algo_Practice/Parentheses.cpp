//
//  Parentheses.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/11/24.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

class Parentheses {
    
public:
    
    bool isValid(string s) {
        if (!s.size()) {
            return false;
        }
        map<char, char> input;
        input[')'] = '(';
        input['}'] = '{';
        input[']'] = '[';
        
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            char cc = s[i];
            if (input[cc]) {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if (top != input[cc]) {
                    return false;
                }
            } else {
                st.push(cc);
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
    
};
