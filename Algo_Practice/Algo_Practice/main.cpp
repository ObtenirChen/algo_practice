//
//  main.cpp
//  Algo_Practice
//
//  Created by Obtenir Chen on 2019/11/22.
//  Copyright © 2019 Obtenir Chen. All rights reserved.
//

#include <iostream>
#include "AllSort.cpp"
#include "Permutation.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    AllSort *as = new AllSort();
    ListNode *node1 = new ListNode(5);
    ListNode *node2 = new ListNode(1);
    node1->next = node2;
    ListNode *node3 = new ListNode(4);
    node2->next = node3;
    ListNode *node4 = new ListNode(2);
    node3->next = node4;
    ListNode *node5 = new ListNode(9);
    node4->next = node5;
    ListNode *node6 = new ListNode(3);
    node5->next = node6;
    node6->next = NULL;
    
    as->quickSortList(node1, node6);
    
    vector<int> nums = {1,2, 3};
    Permutation *permute = new Permutation();
    vector<vector<int>> result = permute->permute(nums);
    
    return 0;
}
