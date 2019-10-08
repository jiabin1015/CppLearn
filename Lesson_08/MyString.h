//
//  MyString.hpp
//  ct
//
//  Created by Binson on 5/10/19.
//  Copyright © 2019 Binson. All rights reserved.
//

#ifndef MyString_hpp
#define MyString_hpp

#include <iostream>
//#include <ostream>

class MyString {
    
public:
    // 构造方法
    MyString();
    MyString(const MyString &str);
    MyString(const char *str);
    ~MyString();
    
    // 成员方法
    unsigned long getLength() const;
    char* charStr() const;
    
    // 运算符重载
    // + 拼接
    MyString operator + (const MyString &str);
    MyString operator + (const char *str);
    
    // = 赋值
    void operator = (const MyString &str);
    void operator = (const char *str);
    
    // < > ==
    bool operator  < (const MyString &str);
    bool operator  > (const MyString &str);
    bool operator  == (const MyString &str);
    
    // []
    char operator [] (unsigned long index);
private:
    unsigned long _length; // 字符串长度
    char *_buf; // 缓存
};

// << 输出
std::ostream& operator<<(std::ostream& out, const MyString& s);

#endif /* MyString_hpp */
