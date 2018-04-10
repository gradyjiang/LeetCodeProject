//
//  CString.cpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/4/10.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

#include "CString.hpp"
#include <queue>

CString::CString(): data(nullptr), len(0)
{
    
}

CString::CString(const char *c_str): data(nullptr), len(0)
{
    while (*(c_str + len) != '\0')
    {
        len += 1;
    }
    
    data = new char[len+1];
    strncpy(data, c_str, len+1);
}

//拷贝构造函数
CString::CString(const CString &obj)
{
    this->len = obj.len;
    this->data = new char[len+1];
    strncpy(data, obj.data, len+1);
}

//无继承关系，不用virtual
CString::~CString()
{
    if (data != nullptr)
        delete [] data;
    len = 0;
}

int CString::length() const
{
    return len;
}

CString CString::subString(int position, int size) const
{
    assert(position > 0);
    assert(size > 0);
    assert(position < len);
    assert((position + size) <= len);
    
    char *tempChar = new char[size+1];
    tempChar[size] = '\0';
    strncpy(tempChar, this->data + position, size);
    CString str(tempChar);
    delete [] tempChar;
    
    return str;
}

CString &CString::operator=(const CString &obj)
{
    if (data != nullptr)
        delete [] data;
    
    len = obj.len;
    data = new char[len+1];
    strncpy(data, obj.data, len+1);
    return *this;
}

CString &CString::operator+=(const CString &obj)
{
    char *temp = data;
    len += obj.len;
    data = new char[len+1];
    memset(data, 0, len+1);
    if (temp != nullptr)
        strncpy(data, temp, len - obj.len);
    strncat(data, obj.data, obj.len);
    return *this;
}

bool CString::operator==(const CString &obj) const
{
    if (this == &obj)
        return true;
    
    if (len != obj.len)
        return false;
    
    for (int i = 0; i< len; i++)
    {
        if (*(data + i) != *(obj.data + i))
            return false;
    }
    //另一种写法
    //    if (strncmp(data, obj.data, len) == 0)
    //        return true;
    //    else
    //        return false;
    return true;
}

//重载!=运算符
bool CString::operator!=(const CString &obj) const
{
    return !(*this == obj);
}
//重载[]运算符
char CString::operator[](int index)
{
    if (index >= len)
        return NULL;
    
    return data[index];
}

//友元加，可两个不同类对象或同类对象加
//CString operator+(const CString &lObj, const CString &rObj)
//{
//    int length = lObj.len + rObj.len;
//    char *tempChar = new char[length+1];
//    memset(tempChar, 0, length+1);
//    if (lObj.len != 0)
//        strncat(tempChar, lObj.data, lObj.len);
//    if (rObj.len != 0)
//        strncat(tempChar, rObj.data, rObj.len);
//
//    CString str(tempChar);
//
//    return str;
//}

//成员加
CString CString::operator+(const CString &rObj)
{
     int length = this->len + rObj.len;
     char *tempChar = new char[length+1];
     memset(tempChar, 0, length+1);
     if (this->len != 0)
         strncat(tempChar, this->data, this->len);
     if (rObj.len != 0)
         strncat(tempChar, rObj.data, rObj.len);
 
     CString str(tempChar);
 
     return str;
}


std::ostream &operator<<(std::ostream &os, const CString &obj)
{
    if (obj.len > 0)
        os << obj.data << " -- " << obj.len;
    return os;
}

std::istream &operator>>(std::istream &is, CString &obj)
{
    char c;
    int i = 0;
    
    delete [] obj.data;
    obj.len = 0;
    
    std::queue<char> charQueue;
    while (1)
    {
        is >> std::noskipws;//noskipws不忽略空白符，skipws忽略空白符
        is >> c;
        if (c == '\n')
            break;
        else
        {
            charQueue.push(c);
            i++;
        }
    }
    
    if (i > 0)
    {
        obj.len = i;
        obj.data = new char[i+1];
        memset(obj.data, 0, i+1); //这里之前没有memset 多打印了\370\2018乱码，主要原因是忘记结束符了
        int index = 0;
        while (charQueue.size() > 0)
        {
            *(obj.data + index) = charQueue.front();
            index++;
            charQueue.pop();
        }
    }
    return is;
}




