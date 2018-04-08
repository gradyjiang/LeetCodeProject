//
//  CMaxProfit.cpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/3/29.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//


//假设有一个数组，它的第 i 个元素是一个给定的股票在第 i 天的价格。
//设计一个算法来找到最大的利润。你可以完成尽可能多的交易（多次买卖股票）。然而，你不能同时参与多个交易（你必须在再次购买前出售股票）。

#include "CMaxProfit.hpp"

using std::vector;

int CMaxProfit::maxProfit(vector<int> &prices)
{
    if (prices.size() == 0)
    {
        return 0;
    }
    
    int buyValue = INT_MAX;
    int gainSum = 0;
    
    for (vector<int>::iterator it = prices.begin(); it != prices.end() - 1; it++)
    {
        int curItVal = *it;
        int nextItVal = *(it+1);
        if (curItVal <= nextItVal)
        {
            //买第一手
            if (buyValue == INT_MAX)
            {
                buyValue = curItVal;
            }
            
            if (it == prices.end() - 2) //最后一个元素了，要抛掉
            {
                gainSum += nextItVal - buyValue;
            }
        }
        else if (buyValue != INT_MAX)
        {
            //下一次开始下跌，这里须全部抛出
            gainSum += curItVal - buyValue;
            buyValue = INT_MAX;
        }
    }
    return gainSum;
}
