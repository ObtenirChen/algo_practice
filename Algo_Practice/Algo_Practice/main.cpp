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
#include "Parentheses.cpp"
#include "Matrix.cpp"
#include "DynamicPlanning.cpp"
#include "Seek.cpp"
#include "SubStrings.cpp"
#include "Jump.cpp"
#include "RemoveNum.cpp"
#include "HandleString.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    string s;
//    cin >> s;
//    cout << s;
    
//    vector<int> sortArr = {3, 5, 1, 30, 26, 19, 50, 99, 39, 41, 2};
//    AllSort *as = new AllSort();
//
//    as->quickSort(sortArr, 0, (int)sortArr.size() - 1);
//
//    for (int i = 0; i < sortArr.size(); i++) {
//        cout << sortArr[i] << " ";
//    }
//
//    ListNode *node1 = new ListNode(5);
//    ListNode *node2 = new ListNode(1);
//    node1->next = node2;
//    ListNode *node3 = new ListNode(4);
//    node2->next = node3;
//    ListNode *node4 = new ListNode(2);
//    node3->next = node4;
//    ListNode *node5 = new ListNode(9);
//    node4->next = node5;
//    ListNode *node6 = new ListNode(3);
//    node5->next = node6;
//    node6->next = NULL;
//
//    as->quickSortList(node1, node6);
//
//    vector<int> nums = {1, 2, 3};
//    Permutation *permute = new Permutation();
//    vector<vector<int>> result = permute->subsets(nums);
//
//    Parentheses *pa = new Parentheses();
//    bool valid = pa->isValid("");
    
//    MyMatrix *mm = new MyMatrix();
//    vector<vector<int>> input = {{1, 2, 3, 10}, {4, 5, 6, 11}, {7, 8, 9, 12}};
//    vector<int> result = mm->spiralOrder(input);
//
//    for (int i = 0; i < result.size(); i++) {
//        cout << result[i] << " ";
//    }
//
//    DynamicPlanning *dp = new DynamicPlanning();
//    dp->numPermsDISequence("DID");
//
//    Seek *sk = new Seek();
//    vector<int> num1 = {1, 3, 5, 6};
//    vector<int> num2 = {2};
//    cout << sk->findMedianSortedArrays(num1, num2);
//    cout << sk->searchInsert(num1, 7) << "\n";
    
//
//    SubStrings *ss = new SubStrings();
//    cout << ss->lengthOfLongestSubstring("abcdabcd");
//    Jump *jj = new Jump();
//    vector<int> rr = {2, 0 ,0};
//    jj->canJump(rr);
    
//    RemoveNum *rm = new RemoveNum();
//    vector<int> result = {3, 2, 2, 3, 2};
//    rm->removeElement(result, 3);
    
    HandleString *hs = new HandleString();
    hs->strStr("aaaaa", "bba");
    
    return 0;
}
