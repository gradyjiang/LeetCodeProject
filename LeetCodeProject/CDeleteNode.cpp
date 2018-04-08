//
//  CDeleteNode.cpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/3/30.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//


#include "CDeleteNode.hpp"
#include <iostream>
//编写一个函数，在给定单链表一个结点(非尾结点)的情况下，删除该结点。

//假设该链表为1 -> 2 -> 3 -> 4 并且给定你链表中第三个值为3的节点，在调用你的函数后，该链表应变为1 -> 2 -> 4。

void CDeleteNode::deleteNode(ListNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    
    ListNode *pTempNode = node->next;
    
    node->val = pTempNode->val;
    node->next = pTempNode->next;
    pTempNode->next = nullptr;
}


//给定一个链表: 1->2->3->4->5, 并且 n = 2.
//当删除了倒数第二个节点后链表变成了 1->2->3->5.
//说明:

//给的 n 始终是有效的。

//尝试一次遍历实现。
ListNode* CDeleteNode::removeNthFromEnd(ListNode* head, int n)
{
    if (head == nullptr || n <= 0)
        return nullptr;

    if (n == 1 && head->next == nullptr)
    {
        return nullptr;
    }
    
    ListNode *pFristNode = head;
    ListNode *pSecondNode = head;
    ListNode *pTempNode = head;
    

    
    for (int i = 0 ; i < n-1; i++)
    {
        if (pTempNode->next == nullptr)
        {
            return nullptr;
        }
        pTempNode = pTempNode->next;
    }


    pSecondNode = pTempNode;
    pTempNode = head;
    while (pSecondNode->next != nullptr)
    {
        pTempNode = pFristNode;
        pFristNode = pFristNode->next;
        pSecondNode = pSecondNode->next;
    }
    
    if (pFristNode == head)//相等说明后指针没有移动过
    {
        
        head = head->next;
        std::cout << head->val << std::endl;
    }
    else
    {
        pTempNode->next = pFristNode->next;
    }
    
    ListNode *tempNode = head;
    while (tempNode != NULL) {
        std::cout << tempNode->val;
        tempNode = tempNode->next;
    }
    std::cout << std::endl;
    
    return head;
}
