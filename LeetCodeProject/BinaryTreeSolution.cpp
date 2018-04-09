//
//  BinaryTreeSolution.cpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/4/2.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

#include "BinaryTreeSolution.hpp"
#include <stdint.h>
#include <queue>
#include <iostream>

//求二叉树的最大深度
int CBinaryTreeSolution::maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
        
    int leftHeight = 0;
    int rightHeight = 0;
    leftHeight = maxDepth(root->left);
    rightHeight = maxDepth(root->right);
    
    return (leftHeight > rightHeight) ? leftHeight+1 : rightHeight+1;
}

bool CBinaryTreeSolution::validateRange(TreeNode* root, int min, int max)
{
    if (root == nullptr)
        return true;
    
    if (root->val == INT32_MIN && root->left != nullptr)
        return false;
    
    if (root->val == INT32_MAX && root->right != nullptr)
        return false;
    
    if (root->val < min || root->val > max)
        return false;
    
    bool leftFlag  = validateRange(root->left, min, root->val-1);
    bool rightFlag = validateRange(root->right, root->val+1, max);
    
    return leftFlag && rightFlag;
}

//求此二叉树是否为搜索二叉树
bool CBinaryTreeSolution::isValidBST(TreeNode* root)
{
    return validateRange(root, INT32_MIN, INT32_MAX);
}

bool CBinaryTreeSolution::isEqualNode(TreeNode *tn1, TreeNode *tn2)
{
    if (tn1 == nullptr && tn2 == nullptr)
        return true;
    
    if (tn1 != nullptr && tn2 != nullptr && tn1->val == tn2->val)
        return isEqualNode(tn1->left, tn2->right) && isEqualNode(tn1->right, tn2->left);
    
    return false;
}

//求此二叉树是否为对称二叉树
bool CBinaryTreeSolution::isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;
    
    if (root->left == nullptr && root->right == nullptr)
        return true;
    
    if ((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr))
        return false;
    
    return isEqualNode(root->left, root->right);
}

//给定一个二叉树，返回其按层次遍历的节点值
std::vector<std::vector<int>> CBinaryTreeSolution::levelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> retVec;
    if (root == nullptr)
    {
        return retVec;
    }
    
    std::queue<TreeNode *> nodeQueue; //queue 单向队列， deque（Double Ended Queue）双向队列
    
    nodeQueue.push(root);
    
    while (nodeQueue.size() != 0)
    {
        std::vector<int> intVec;
        std::vector<TreeNode *> nodeVec;
        
        while (nodeQueue.size() != 0)
        {
            intVec.push_back(nodeQueue.front()->val);
            nodeVec.push_back(nodeQueue.front());
            nodeQueue.pop();
        }
        
        retVec.push_back(intVec);
        
        for (std::vector<TreeNode *>::iterator it = nodeVec.begin(); it != nodeVec.end(); it++)
        {
            if (*it && (*it)->left)
                nodeQueue.push((*it)->left);
            if (*it && (*it)->right)
                nodeQueue.push((*it)->right);
        }
    }
    
    return retVec;
}

//数组转二叉树
TreeNode *CBinaryTreeSolution::makeBinayTree(const std::vector<int> &intVec)
{
    if (intVec.size() == 0)
        return nullptr;
    
    TreeNode *root = new TreeNode(intVec[0]);
    TreeNode *node = root;
    std::queue<TreeNode *> nodeQueue;
    
    for (int i = 0; i < intVec.size(); i++)
    {
        if (2*i+1 < intVec.size())
        {
            if (intVec[2*i+1] != NULL)
            {
                node->left = new TreeNode(intVec[2*i+1]);
                nodeQueue.push(node->left);
            }
            else
                nodeQueue.push(nullptr);
        }


        if (2*i+2 < intVec.size())
        {
            if (intVec[2*i+2] != NULL)
            {
                node->right = new TreeNode(intVec[2*i+2]);
                nodeQueue.push(node->right);
            }
            else
                nodeQueue.push(nullptr);
        }

        std::cout << node->val << " ";
        if (node->left) {
            std::cout << " Left " << node->left->val ;
        }
        else
            std::cout << " Left " << "N" ;

        if (node->right) {
            std::cout <<" Right " << node->right->val ;
        }
        else
            std::cout << " Right " << "N" ;
        std::cout << std::endl;

        if (nodeQueue.size() == 0)
            break;
        
        while (nodeQueue.size() > 0)
        {
            node = nodeQueue.front();
            nodeQueue.pop();
            if (node != nullptr) {
                break;
            }
        }
    }
    
    //printByPreOrder(root);
    
    return root;
}


void CBinaryTreeSolution::printByPreOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    
    std::cout << root->val;
    std::cout << " ";
    printByPreOrder(root->left);
    printByPreOrder(root->right);
    
    //std::cout << std::endl;
}

//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
//此题中，一个高度平衡二叉树是指一个二叉树每个节点的左右两个子树的高度差的绝对值不超过1。
//给定有序数组: [-10,-3,0,5,9],
//一种可行答案是：[0,-3,9,-10,null,5]，它可以表示成下面这个高度平衡二叉搜索树：
TreeNode *CBinaryTreeSolution::sortedArrayToBST(std::vector<int> &nums)
{
    //这里利用二分查找，始终将数组分为两等分，以确定树的平衡
    return sortedArrayToBSTByIndex(nums, 0, nums.size() - 1);
}

TreeNode *CBinaryTreeSolution::sortedArrayToBSTByIndex(std::vector<int> &nums, unsigned long begin, unsigned long end)
{
    if (nums.size() == 0)
        return nullptr;
    if (end < begin)
        return nullptr;
    
    //本机测试unsigned long最大值也是18446744073709551615  unsigned long long的最大值：18446744073709551615
    //这里仅存在理论上溢出的可能，实际中不可能有这么多元素
    unsigned long middle = (end + begin)/2;
    
    TreeNode *node = new TreeNode(nums[middle]);
    
    if (middle == 0)
    {
        node->left = nullptr;
        node->right = sortedArrayToBSTByIndex(nums, middle+1, end);
    }
    else if (middle == UINT_MAX)
    {
        node->left = sortedArrayToBSTByIndex(nums, begin, middle-1);
        node->right = nullptr;
    }
    else
    {
        node->left = sortedArrayToBSTByIndex(nums, begin, middle-1);
        node->right = sortedArrayToBSTByIndex(nums, middle+1, end);
    }
    
    return node;
}

