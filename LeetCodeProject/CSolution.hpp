//
//  CSolution.hpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/3/30.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

#ifndef CSolution_hpp
#define CSolution_hpp

#include <stdio.h>
#include <vector>
/**
 给定一个有序数组，你需要原地删除其中的重复内容，使每个元素只出现一次,并返回新的长度。
 
 给定数组: nums = [1,1,2],
 
 你的函数应该返回新长度 2, 并且原数组nums的前两个元素必须是1和2
 不需要理会新的数组长度后面的元素
 */

//C++
class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;
        
        int preVal = nums.front();
        for (std::vector<int>::iterator it = nums.begin() + 1; it != nums.end();)
        {
            int tmp = *it;
            if (tmp == preVal)
                nums.erase(it);
            else
            {
                preVal = *it;
                it++;
            }
        }
        
        return static_cast<int>(nums.size());
    }
};
#endif /* CSolution_hpp */
