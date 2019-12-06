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
#include <vector>

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
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
    void backtrack(vector<string> &result, string cur, int open, int close, int max) {
        if (cur.size() == 2 * max) {
            result.push_back(cur);
            return;
        }
        
        if (open < max) {
            backtrack(result, cur + "(", open+1, close, max);
        }
        if (close < open) {
            backtrack(result, cur + ")", open, close+1, max);
        }
    }
    
};
