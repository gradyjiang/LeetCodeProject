//
//  main.cpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/3/29.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//



#include <iostream>
#include <vector>
#include "CMaxProfit.hpp"
#include "CSolution.hpp"
#include "CRotateArr.hpp"
#include "CDeleteNode.hpp"
#include "SingleLinkListSolution.hpp"
#include "CStringSolution.hpp"
#include "BinaryTreeSolution.hpp"
#include "CString.hpp"

using namespace std;


//C
/**
 给定一个有序数组，你需要原地删除其中的重复内容，使每个元素只出现一次,并返回新的长度。
 
 给定数组: nums = [1,1,2],
 
 你的函数应该返回新长度 2, 并且原数组nums的前两个元素必须是1和2
 不需要理会新的数组长度后面的元素
 */
bool erase(int *nums, int index, int arrLen);

int removeDuplicates(int* nums, int numsSize)
{
    if (nums == NULL || numsSize <= 0)
        return 0;
    
    int arrLen = numsSize;
    int preVal = *nums;
    for (int i = 1; i < arrLen;)
    {
        int tmp = nums[i];
        if (tmp == preVal)
        {
            erase(nums, i, arrLen);
            arrLen -= 1;
        }
        else
        {
            preVal = nums[i];
            i++;
        }
    }
    
    return arrLen;
}

bool erase(int *nums, int index, int arrLen)
{
    if (nums == NULL || arrLen <= 0 || index < 0 || index >= arrLen)
        return false;
    
    for (int i = index; i < arrLen; i++) {
        nums[i] = nums[i+1];
    }
    
    return false;
}

/******************************************************************************/

//假设有一个数组，它的第 i 个元素是一个给定的股票在第 i 天的价格。
//设计一个算法来找到最大的利润。你可以完成尽可能多的交易（多次买卖股票）。然而，你不能同时参与多个交易（你必须在再次购买前出售股票）。

int MaxProfit(int* prices, int pricesSize)
{
    
    if (prices == NULL || pricesSize == 0)
        return 0;
    
    int buyValue = INT_MAX;
    int gainSum = 0;
    
    for (int i = 0; i < pricesSize - 1; i++) {
        int curVal = prices[i];
        int nextVal = prices[i+1];
        
        if (curVal <= nextVal)
        {
            //买第一手
            if (buyValue == INT_MAX)
            {
                buyValue = curVal;
            }
            
            if (i == pricesSize-2) //最后一个元素了，要抛掉
            {
                gainSum += nextVal - buyValue;
            }
        }
        else if (buyValue != INT_MAX)
        {
            //下一次开始下跌，这里须全部抛出
            gainSum += curVal - buyValue;
            buyValue = INT_MAX;
        }
    }
    
    return gainSum;
}

/******************************************************************************/
//将包含 n 个元素的数组向右旋转 k 步。

//例如，如果  n = 7 ,  k = 3，给定数组  [1,2,3,4,5,6,7]  ，向右旋转后的结果为 [5,6,7,1,2,3,4]。
void rotate(int* nums, int numsSize, int k) {
    if (numsSize <= 0 || k <= 0)
    {
        return;
    }
    
    k %= numsSize;
    int tempVec[k];
    
    for (int i = 0; i < k; i++)
    {
        tempVec[i] = nums[numsSize - k + i];
    }
    
    for (int i = numsSize - 1; i >= 0; i--)
    {
        nums[i] = nums[i - k];
    }
    
    for (int i = 0; i < k; i++)
    {
        nums[i] = tempVec[i];
    }
}

/******************************************************************************/

//TEST
void testRemoveDuplicates()
{
    vector<int> testVec;
    testVec.push_back(1);
    testVec.push_back(1);
    testVec.push_back(2);
    testVec.push_back(2);
    testVec.push_back(3);
    cout << "before: " << testVec.size() << endl;
    Solution solu;
    cout << solu.removeDuplicates(testVec) << endl;
    
    int testArr[] = {1,1,2,2,3,4,4,5};
    int arrLen = 8;
    cout << "after: " << removeDuplicates(testArr, arrLen) << endl;
}


void testMaxProfit()
{
    vector<int> testVec;
    testVec.push_back(1);
    testVec.push_back(2);
    testVec.push_back(3);
    testVec.push_back(1);
    testVec.push_back(2);
    testVec.push_back(5);
    testVec.push_back(1);
    cout << "before: " << testVec.size() << endl;
    CMaxProfit mp;
    cout << "挣了: " << mp.maxProfit(testVec) << endl;
    
    int testArr[] = {1,2,3,1,2,5,1};
    int arrLen = 7;
    cout << "挣了: " << MaxProfit(testArr, arrLen) << endl;
}


void testRotateArr()
{
    vector<int> testVec;
    testVec.push_back(1);
    testVec.push_back(2);
    testVec.push_back(3);
    testVec.push_back(4);
    testVec.push_back(5);
    testVec.push_back(6);
    testVec.push_back(7);
    
    CRotateArr ra;
    for (int seg : testVec) {
        std::cout << seg;
    }
    std::cout << std::endl;
    ra.rotate(testVec, 10);
    for (int seg : testVec) {
        std::cout << seg;
    }
    std::cout << std::endl;
    
    int testArr[] = {1,2,3,4,5,6,7};
    int arrLen = 7;
    rotate(testArr, arrLen, 10);
    for (int i = 0; i < arrLen; i++)
    {
        std::cout << testArr[i] << std::endl;
    }
}

void testDeletNode()
{
    ListNode head(1);
    ListNode node2(2);
    head.next = &node2;
    ListNode node3(3);
    node2.next= &node3;
    
    CDeleteNode dn;
    dn.removeNthFromEnd(&head, 3);
    
}

void testReverseList()
{
    ListNode head(1);
    ListNode node2(2);
    head.next = &node2;
    ListNode node3(3);
    node2.next= &node3;
    
    SingleLinkListSolution sll;
    
    ListNode *tempNode = sll.reverseList(&head);;
    while (tempNode != nullptr) {
        cout << tempNode->val << " p: " << tempNode<< endl;
        tempNode = tempNode->next;
    }
}

void testReverseInt()
{
    int testNum = 12345;
    
    CStringSolution ss;

    cout << ss.reverseInt(testNum) << endl;
}

void testIsPalindrome()
{
    ListNode head(1);
    ListNode node2(2);
    head.next = &node2;
    ListNode node3(2);
    node2.next= &node3;
    ListNode node4(2);
    node3.next= &node4;
    
    SingleLinkListSolution sll;
    
    cout << true << endl;
    cout << sll.isPalindrome(&head) << endl;
}

void testIsValidBST()
{
    //[-2147483648,-2147483648]
    //[2147483647,null,-2147483648]
    TreeNode root(2147483647);
    //TreeNode node1(Null);
    TreeNode node2(-2147483648);
    root.left = nullptr;
    root.right = &node2;

    CBinaryTreeSolution bts;
    cout << bts.isValidBST(&root) << endl;
}

void testlevelOrderTree()
{
    int arr[] = {1,2,3,NULL,4,5};
    CBinaryTreeSolution bts;
    std::vector<int> vec(arr, arr+6);
    TreeNode *root = bts.makeBinayTree(vec);
    std::vector<std::vector<int>> vecIntVec = bts.levelOrder(root);
    
    for (std::vector<std::vector<int>>::iterator it = vecIntVec.begin(); it != vecIntVec.end(); it++)
    {
        std::vector<int> intVec = *it;
        
        std::cout << " [ ";
        for (std::vector<int>::iterator iter = intVec.begin(); iter != intVec.end(); iter++)
        {
            std::cout << *iter << " ,";
        }
        std::cout << " ] " << endl;
    }
}

void testSortedArrayToBST()
{
    //[-10,-3,0,5,9]
    int arr[] = {-10,-3,0,5,9};
    CBinaryTreeSolution bts;
    std::vector<int> vec(arr, arr+5);
    TreeNode *root = bts.sortedArrayToBST(vec);
    std::vector<std::vector<int>> vecIntVec = bts.levelOrder(root);
    
    for (std::vector<std::vector<int>>::iterator it = vecIntVec.begin(); it != vecIntVec.end(); it++)
    {
        std::vector<int> intVec = *it;
        
        std::cout << " [ ";
        for (std::vector<int>::iterator iter = intVec.begin(); iter != intVec.end(); iter++)
        {
            std::cout << *iter << " ,";
        }
        std::cout << " ] " << endl;
    }
}

void testCString()
{
    CString str("Hello World123");
//    std::cout << str << std::endl;
//    std::cin >> str;
//    std::cout << str << std::endl;
    // >> << 测试通过
    CString str2("World Hello NI HAO");
    CString str3 = str + str2;
    std::cout << str3 << std::endl;
    //加法通过
    std::cout << str3[30] << std::endl;
    //[] 通过
    std::cout << (str == str3) << std::endl;
    CString str4("Hello World123");
    std::cout << (str != str4) << std::endl;
    // == != 通过
    CString str5(str2);
    std::cout << str5 << std::endl;
    std::cout << (str5 == str2) << std::endl;
    //拷贝构造函数通过
    CString str6 = str5.subString(15, 3);
    std::cout << str6 << std::endl;
    //subString OK
    str2 += str;
    std::cout << str2 << std::endl;
    //+= OK
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    //testMaxProfit();
    //testRotateArr();
    //testDeletNode();
    //testReverseList();
    //testReverseInt();
    //testIsPalindrome();
    //testIsValidBST();
    //testlevelOrderTree();
    //testSortedArrayToBST();
    testCString();
    return 0;
}
