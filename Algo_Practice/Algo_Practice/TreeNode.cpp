//
//  TreeNode.cpp
//  Algo_Practice
//
//  Created by Obtenir on 2019/11/22.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <stdio.h>

#ifndef TREENODE
#define TREENODE

class TreeNode {
    
public:
    
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif
