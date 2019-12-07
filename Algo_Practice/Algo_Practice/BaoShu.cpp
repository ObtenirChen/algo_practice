//
//  BaoShu.cpp
//  Algo_Practice
//
//  Created by Obtenir Chen on 2019/12/7.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class BaoShu {

    
public:
    
    string countAndSay(int n) {
        string s("1");
        for(int i=1;i<n;++i){
            string t;
            int j=0;
            while(j < s.size()){
                int k=j;
                int c=0;
                while(k < s.size() && s[k] == s[j]){
                    ++c;
                    ++k;
                }
                t += to_string(c) + s[j];
                j = k;
            }
            s=t;
        }
        return s;
    }
    
};
