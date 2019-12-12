//
//  HandleString.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/11.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class HandleString {
    
public:
    
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }
        
        if (s == " ") {
            return 0;
        }
        
        int count = 0;
        bool findChar = false;
        for (int i = (int)s.size() - 1; i > 0; i--) {
            if (s[i] != ' ') {
                findChar = true;
            }
            if (s[i] == ' ') {
                if (findChar) {
                    break;
                } else {
                    continue;
                }
            }
            count++;
        }
        
        return count;
    }
    
    
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }
        
        int result = -1;
        
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            bool match = true;
            for (int j = 0; j < needle.size(); j++) {
                if (haystack[i+j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result = i;
                break;
            }
        }
        
        return result;
    }
};
