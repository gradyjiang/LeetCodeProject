//
//  CDeleteNode.hpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/3/30.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

#ifndef CDeleteNode_hpp
#define CDeleteNode_hpp


#include <stdio.h>
#include "CStruct.hpp"

//编写一个函数，在给定单链表一个结点(非尾结点)的情况下，删除该结点。

//假设该链表为1 -> 2 -> 3 -> 4 并且给定你链表中第三个值为3的节点，在调用你的函数后，该链表应变为1 -> 2 -> 4。

//typedef struct _ListNode
//{
//    int value;
//    _ListNode *next;
//    _ListNode(int x) : value(x), next(NULL) {}
//} ListNode;

class CDeleteNode {
    
public:
    //编写一个函数，在给定单链表一个结点(非尾结点)的情况下，删除该结点。
    void deleteNode(ListNode* node);
    
    //给定一个链表，删除链表的倒数第 n 个节点并返回头结点。
    ListNode* removeNthFromEnd(ListNode* head, int n);
};
#endif /* CDeleteNode_hpp */
