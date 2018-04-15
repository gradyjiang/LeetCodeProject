//
//  SingleLinkListSolution.hpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/4/2.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

#ifndef SingleLinkListSolution_hpp
#define SingleLinkListSolution_hpp

#include <stdio.h>
#include "CStruct.hpp"

//typedef  struct _ListNode {
//    int val;
//    _ListNode *next;
//} ListNode;

class SingleLinkListSolution
{
public:
    //反转链表
    ListNode *reverseList(ListNode* head);
    //合并有序链表
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2);
    
    //回文链表
    bool isPalindrome(ListNode* head);
    
    //有环链表
    bool hasCycle(ListNode *head);
    
    //两数相加
    ListNode *addTwoNumbers(ListNode* l1, ListNode* l2);
    
private:
    ListNode *addTwoNumbersWithCarry(ListNode *l1, ListNode *l2, bool carry);
};

#endif /* SingleLinkListSolution_hpp */
