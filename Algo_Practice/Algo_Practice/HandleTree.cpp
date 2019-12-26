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
#include <stack>
#include <iostream>

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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return root;
        }
        
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
    
    TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode *left = commonAncestor(root->left, p, q);
        TreeNode *right = commonAncestor(root->right, p, q);
        
        return left == NULL ? right : (right == NULL ? left : root);
    }
    

    void InOrderWithoutRecursion1(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        stack<TreeNode *> ss;
        TreeNode *p = root;
        while (!ss.empty() || p) {
            
            while (p != NULL) {
                ss.push(p);
                p = p->left;
            }
            if (!ss.empty()) {
                p = ss.top();
                ss.pop();
                cout << p->val << " ";
                p = p->right;
            }
            
        }
    }
    

    void PostOrderWithoutRecursion(TreeNode* root) {
        
    }
    
};
