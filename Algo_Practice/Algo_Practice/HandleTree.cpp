//
//  HandleTree.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/11/22.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.cpp"
#include <vector>

using namespace std;

class HandleTree {
    
public:
    
    int maxPathSum(TreeNode* root) {
        int m = root->val;
        maxPathSum1(root, m);
        return m;
    }
    
    int maxPathSum1(TreeNode* root, int &m) {
        if (root == NULL) {
            return 0;
        }
        int result = 0;
        int left = maxPathSum1(root->left, m);
        int right = maxPathSum1(root->right, m);
        if (left < 0) {
            left = 0;
        }
        if (right < 0) {
            right = 0;
        }
        result = root->val + left + right;
        m = max(result, m);
        return max(root->val + left, root->val + right);
    }
    
    
    
};
