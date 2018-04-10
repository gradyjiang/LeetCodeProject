//
//  CString.hpp
//  LeetCodeProject
//
//  Created by JiangZhongjin on 2018/4/10.
//  Copyright © 2018年 JiangZhongjin. All rights reserved.
//

#ifndef CString_hpp
#define CString_hpp

#include <stdio.h>
#include <iostream>

class CString
{
private:
    char *data;
    int  len;
    
public:
    //默认构造函数
    CString();
    //带参数的构造函数
    CString(const char *c_str);
    //拷贝构造函数
    CString(const CString &obj);
    //析构函数
    ~CString();
    
    //返回字符串长度
    int length() const;
    //从position位置开始取连续len个字符组成的字符串
    CString subString(int position, int len) const;
    
    //重载赋值运算符
    CString &operator=(const CString &obj);
    //重载+=运算符
    CString &operator+=(const CString &obj);
    //重载==运算符
    bool operator==(const CString &obj) const;
    //重载!=运算符
    bool operator!=(const CString &obj) const;
    //重载[]运算符
    char operator[](int index);
    
    //friend       1. 修饰非成员函数，表示该非成员函数对该类的所有成员具有访问权限
    //             2. 修饰另一个类类名，表示另一个类对此类的所有成员有访问权限
    //             3. 修饰另一个类::成员函数，表示另一个类中的此成员函数对该类的所有成员具有访问权限
    //重载+运算符
    //friend CString operator+(const CString &lObj, const CString &rObj);
    //这里两个同类对象相加完全可以不用友元
    CString operator+(const CString &rObj);
    
    //重载<<运算符
    friend std::ostream &operator<<(std::ostream &os, const CString &obj);
    //重载>>运算符
    friend std::istream &operator>>(std::istream &is, CString &obj);
};

#endif /* CString_hpp */
