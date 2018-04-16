//
//  SortSolution.hpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/4/16.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

#ifndef SortSolution_hpp
#define SortSolution_hpp

#include <stdio.h>

class SortSolution
{
public:
    void BubbleSort(int *arr, int len);
    void SimpleSelectSort(int *arr, int len);
    void QuickSort(int *arr, int low, int high);
}

#endif /* SortSolution_hpp */
