//
//  SingleLinkListSolution.cpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/4/2.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

#include "SingleLinkListSolution.hpp"



//反转链表
ListNode *SingleLinkListSolution::reverseList(ListNode* head)
{
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return head;

    ListNode *pNode = head;
    ListNode *pPrev = nullptr;
    printf("v1 = %d, v2=%d, v3=%d\n", pNode->val, pNode->next->val, pNode->next->next->val);
    while (pNode != nullptr)
    {
        ListNode *pNext = pNode->next;
        
        if (pNext == nullptr)
        {
            pNode->next = pPrev;
            break;
        }
        pNode->next = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    
    printf("v1 = %d, v2=%d, v3=%d\n", pNode->val, pNode->next->val, pNode->next->next->val);
    
    return pNode;
}

//合并两个已排序的链表，并将其作为一个新列表返回。新列表应该通过拼接前两个列表的节点来完成
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
ListNode *SingleLinkListSolution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr && l2 == nullptr)
        return nullptr;
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    
    ListNode *pNewHead = (l1->val >= l2->val) ? l2 : l1;

    if (l1->val >= l2->val)
        pNewHead->next = mergeTwoLists(l1, l2->next);
    else
        pNewHead->next = mergeTwoLists(l1->next, l2);
    
    
    return pNewHead;
}

//请检查一个链表是否为回文链表。(正向遍历和反向遍历是一样的，ex: {1,2,3,4,3,2,1})
bool SingleLinkListSolution::isPalindrome(ListNode* head)
{
    if (head == nullptr)
        return true;
    if (head->next == nullptr)
        return true;
    
    int listLen = 0;
    ListNode *node = head;
    while (node != nullptr) {
        listLen++;
        node = node->next;
    }
    
    bool isEvenNum = listLen%2 == 0 ? true : false;
    int arrLen = listLen/2;
    int *p_arr = new int[arrLen];
    int count = arrLen;
    node = head;
    
    if (isEvenNum)
    {
        for (int i = 0; i < listLen; i++)
        {
            if (i < count)
                *(p_arr + i) = node->val;
            else
            {
                if (*(p_arr + listLen - 1 - i) != node->val)
                {
                    delete [] p_arr;
                    return false;
                }
            }
            
            node = node->next;
        }
    }
    else
    {
        for (int i = 0; i < listLen; i++)
        {
            if (i < count)
                *(p_arr + i) = node->val;
            else if (i > count)
            {
                if (*(p_arr + listLen - 1 - i) != node->val)
                {
                    delete [] p_arr;
                    return false;
                }
            }
            
            node = node->next;
        }
    }
    delete [] p_arr;
    return true;
}

//给定一个链表，判断链表中否有环。
bool SingleLinkListSolution::hasCycle(ListNode *head)
{
    if (head == nullptr)
        return false;
    
    ListNode *firstNode = head;
    ListNode *doubleSpeedNode = head;
    
    while (true)
    {
        if (firstNode == nullptr || doubleSpeedNode == nullptr)
            return false;
        
        if (doubleSpeedNode->next == nullptr)
            return false;
        
        firstNode = firstNode->next;
        doubleSpeedNode = doubleSpeedNode->next->next;
        
        if (firstNode == doubleSpeedNode)
            return true;
    }
    
    return false;
}

