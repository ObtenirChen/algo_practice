//
//  HandleStr.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/12/31.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <string>

using namespace std;

class HandleStr {
    
    
public:
    
    int FirstNotRepeatingChar(string str) {
        if (str.empty()) {
            return -1;
        }
        map<char, int> countMap;
        for (int i = 0; i < str.size(); i++) {
            countMap[str[i]]++;
        }
        int result = -1;
        for (int i = 0; i < str.size(); i++) {
            if (countMap[str[i]] == 1) {
                result = i;
                break;
            }
        }
        return result;
    }
    
    void revertStr(string &str, int lo, int hi) {
        while (lo < hi) {
            swap(str[lo++], str[hi--]);
        }
    }
    
    
    string ReverseSentence(string str) {
        revertStr(str, 0, (int)str.size() - 1);
        
        int i = 0;
        int lo = 0;
        int hi = 0;
        while (i < str.size()) {
            while (i < str.size() && str[i] == ' ') {
                i++;
            }
            lo = i;
            hi = i;
            while (i < str.size() && str[i] != ' ') {
                hi++;
                i++;
            }
            revertStr(str, lo, hi);
        }
        
        return str;
    }
    
};
