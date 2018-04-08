//
//  BinaryTreeSolution.hpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/4/2.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

#ifndef BinaryTreeSolution_hpp
#define BinaryTreeSolution_hpp

#include <stdio.h>
#include "CStruct.hpp"
#include <vector>
//typedef struct _TreeNode {
//    int val;
//    _TreeNode *left;
//    _TreeNode *right;
//    _TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//} TreeNode;

class CBinaryTreeSolution
{
public:
    //最大深度
    int maxDepth(TreeNode* root);
    
    //是否是二叉搜索树
    bool isValidBST(TreeNode* root);
    
    //是否是对称二叉树
    bool isSymmetric(TreeNode* root);
    
    //二叉树的层次遍历
    std::vector<std::vector<int>> levelOrder(TreeNode *root);
    
    //数组建二叉树
    TreeNode *makeBinayTree(const std::vector<int> &intVec);
    
private:
    bool validateRange(TreeNode* root, int  min, int max);
    bool isEqualNode(TreeNode *tn1, TreeNode *tn2);
   
    //前序打印
    void printByPreOrder(TreeNode *root);
};

#endif /* BinaryTreeSolution_hpp */
