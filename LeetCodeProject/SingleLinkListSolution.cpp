//
//  SingleLinkListSolution.cpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/4/2.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

#include "SingleLinkListSolution.hpp"
#include <stack>



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


//给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
//你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//示例：
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
ListNode *SingleLinkListSolution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    
    return addTwoNumbersWithCarry(l1, l2, false);;
}

//@carry bool 表示是否带进位
ListNode *SingleLinkListSolution::addTwoNumbersWithCarry(ListNode *l1, ListNode *l2, bool carry)
{
    int carryInt = carry == true ? 1 : 0;
    ListNode *node = nullptr;
    bool carryFlag = false;
    if (l1 != nullptr && l2 != nullptr)
    {
        int sum = l1->val + l2->val + carryInt;
        if (sum >= 10)
        {
            sum -= 10;
            carryFlag = true;
        }
        node = new ListNode(sum);
        node->next = addTwoNumbersWithCarry(l1->next, l2->next, carryFlag);
    }
    else if (l1 != nullptr)
    {
        int sum = l1->val + carryInt;
        if (sum >= 10)
        {
            sum -= 10;
            carryFlag = true;
        }
        node = new ListNode(sum);
        node->next = addTwoNumbersWithCarry(l1->next, nullptr, carryFlag);
    }
    else if (l2 != nullptr)
    {
        int sum = l2->val + carryInt;
        if (sum >= 10)
        {
            sum -= 10;
            carryFlag = true;
        }
        node = new ListNode(sum);
        node->next = addTwoNumbersWithCarry(l2->next, nullptr, carryFlag);
    }
    else
    {
        if (carryInt)
        {
            node = new ListNode(carryInt);
        }
    }
    
    return node;
}



//这个答案也可以使用，不过看错了，看成表头是最高位，链表尾是最低位了(难度也提升了一点)
//
//给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
//你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//示例：
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：8 -> 0 -> 7
//原因：243 + 564 = 807
//ListNode* SingleLinkListSolution::addTwoNumbers(ListNode* l1, ListNode* l2)
//{
//    if (l1 == nullptr)
//        return l2;
//    if (l2 == nullptr)
//        return l1;
//
//    std::deque<ListNode *> deque1;
//    std::deque<ListNode *> deque2;
//
//    ListNode *tempNode = l1;
//    while (tempNode)
//    {
//        deque1.push_back(tempNode);
//        tempNode = tempNode->next;
//    }
//
//    tempNode = l2;
//    while (tempNode)
//    {
//        deque2.push_back(tempNode);
//        tempNode = tempNode->next;
//    }
//
//    int carry = 0;
//    tempNode = nullptr;
//    while (true)
//    {
//        if (deque1.size() == 0 && deque2.size() == 0)
//            break;
//
//        int lVal = 0;
//        int rVal = 0;
//        if (deque1.size() != 0)
//        {
//            lVal = deque1.back()->val;
//            deque1.pop_back();
//        }
//
//        if (deque2.size() != 0)
//        {
//            rVal = deque2.back()->val;
//            deque2.pop_back();
//        }
//
//        int sum = lVal + rVal + carry;
//        if (sum >= 10)
//        {
//            sum -= 10;
//            carry = 1;
//        }
//        else
//            carry = 0;
//
//        ListNode *node = new ListNode(sum);
//        node->next = tempNode;
//        tempNode = node;
//    }
//
//    return tempNode;
//}
