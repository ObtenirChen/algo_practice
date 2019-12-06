//
//  SubStrings.cpp
//  Algo_Practice
//
//  Created by Obtenir Chen on 2019/12/6.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class SubStrings {
    
public:
    
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        mp[s[0]] = 0;
        int i = 0;
        int j = 0;
        int count = j - i;
        while (j < s.size()) {
            if (mp.find(s[j]) != mp.end()) {
                i = max(mp[s[j]], i);
                
            }
            mp[s[j]] = j;
            count = max(count, j-i);
            j++;
        }
        
        return count;
    }
    
//    int mian(int argc, const char *argv[]) {
//
//        string s;
//        cin >> s;
//        cout << s;
//        
//        return 0;
//    }
    
};
