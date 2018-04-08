//
//  CStruct.hpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/4/2.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

#ifndef CStruct_hpp
#define CStruct_hpp

#include <stdio.h>
typedef struct _ListNode
{
    int val;
    _ListNode *next;
    _ListNode(int x) : val(x), next(NULL) {}
} ListNode;

typedef struct _TreeNode
{
    int val;
    _TreeNode *left;
    _TreeNode *right;
    _TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

#endif /* CStruct_hpp */
