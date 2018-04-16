//
//  SortSolution.cpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/4/16.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

#include "SortSolution.hpp"

//冒泡排序
void SortSolution::BubbleSort(int *arr, int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//简单选择排序
void SortSolution::SimpleSelectSort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int k = i;
        for (int j = i+1; j < len; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }
        
        if (k != i)
        {
            int t = arr[i];
            arr[i] = arr[k];
            arr[k] = t;
        }
    }
}

void SortSolution::QuickSort(int *arr, int low, int high)
{
    int i , j , t , m;
    i = j = t = m = 0;
    
    if (low < high)
    {
        i = low;
        j = high;
        t = arr[low];
        while(i < j)
        {
            while(i < j && arr[j] > t)//从右边找出小于轴的数
                j--;
            
            if(i < j)//将小于轴的数array[j]放到左边array[i]的位置
            {
                m = arr[i];
                arr[i] = arr[j];
                arr[j] = m;
                i++;
            }
            
            while(i < j && arr[i] <= t)//从左边找出大于轴的数
                i++;
            
            if(i < j)//将大于轴的数array[i]放在右边array[j]的位置
            {
                m = arr[j];
                arr[j] = arr[i];
                arr[i] = m;
                j--;
            }
        }
        
        arr[i] = t;//轴放在中间,现在就有两个区域了分别是[0 i-1]和[i+1 hight],分别快排
        QuickSort(arr, 0, i-1);
        QuickSort(arr, i+1, high);
    }

}
