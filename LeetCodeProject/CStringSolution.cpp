//
//  CStringSolution.cpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/4/3.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

#include "CStringSolution.hpp"
#include <stack>

char *CStringSolution::reverseString(char *s)
{
    if (s == NULL)
        return NULL;
    
    int sLen = -1;
    while((s[++sLen]) != '\0');
    
    int count = sLen / 2;
    for (int i = 0; i < count; i++)
    {
        int temp = s[i];
        s[i] = s[sLen - 1 - i];
        s[sLen - 1 - i] = temp;
    }
    
    return s;
}

std::string CStringSolution::reverseString(std::string s)
{
    if (s.size() == 0)
        return s;
    
    using std::string;
    string::size_type sLen = s.size();
    string::size_type count = (s.size() / 2);
    for (string::size_type i = 0; i < count; i++) {
        int temp = s[i];
        s[i] = s[sLen - i];
        s[sLen - i] = temp;
    }
    
    return s;
}

int CStringSolution::reverseInt(int x)
{
    if (x == 0 || x/10 == 0)
        return x;
    
    int flag = x > 0 ? 1: -1;
    
    int tmp = x;
    std::stack<int> m_IStack;
    while (tmp != 0)
    {
        m_IStack.push(tmp%10);
        tmp /= 10;
    }
    
    int reverseNum = 0;
    int factor = 1;
    while (!m_IStack.empty())
    {
        int increment = 0;
        if (flag == 1)
        {
            if (INT32_MAX / factor >= m_IStack.top())
                increment = m_IStack.top() * factor;
            else
                return 0;
            
            if (INT32_MAX - increment >= reverseNum)
            {
                reverseNum += increment;
            }
            else
            {
                return 0;
            }
        }
        else //负数
        {
            if (INT32_MIN / factor <= m_IStack.top())
                increment = m_IStack.top() * factor;
            else
                return 0;
            
            if (INT32_MIN - increment <= reverseNum)
            {
                reverseNum += increment;
            }
            else
            {
                return 0;
            }
        }

        m_IStack.pop();
        factor *= 10;
    }
    
    return reverseNum;
}
