//
//  CRotateArr.cpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/3/30.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

//将包含 n 个元素的数组向右旋转 k 步。

//例如，如果  n = 7 ,  k = 3，给定数组  [1,2,3,4,5,6,7]  ，向右旋转后的结果为 [5,6,7,1,2,3,4]。
#include "CRotateArr.hpp"
#include <iostream>

using std::vector;

void CRotateArr::rotate(vector<int>& nums, int k)
{
    if (nums.size() == 0 || k < 0)
    {
        return;
    }
    
    k %= nums.size();
    
    vector<int> tempVec(k);
    
    for (int i = 0; i < k; i++)
    {
        tempVec[i] = nums[nums.size() - k + i];
    }
    
    for (int i = (int)nums.size() - 1; i >= 0; i--)
    {
        nums[i] = nums[i - k];
    }
    
    for (int i = 0; i < k; i++)
    {
        nums[i] = tempVec[i];
    }
}
