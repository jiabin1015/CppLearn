//
//  MyString.cpp
//  ct
//
//  Created by Binson on 5/10/19.
//  Copyright © 2019 Binson. All rights reserved.
//

#include "MyString.h"

MyString::MyString() {
    // 初始化长度和缓存
    _length = 0;
    _buf = new char[_length+1];
    assert(_buf);
    memset(_buf, 0, _length+1);
}

// 拷贝构造函数
MyString::MyString(const MyString &str) {
    _length = str.getLength();
    
    _buf = new char[_length+1];
    assert(_buf);
    memcpy(_buf, str.charStr(), _length);
    _buf[_length] = 0;
}

MyString::MyString(const char *str) {
    _length = strlen(str);
    
    _buf = new char[_length+1];
    assert(_buf);
    memcpy(_buf, str, _length);
    _buf[_length] = 0;
}

MyString::~MyString() {
    _length = 0;
    if (_buf != NULL) {
        delete []_buf;
        _buf = NULL;
    }
}

// 获取字符串长度，const表示函数内部不允许修改成员变量
unsigned long MyString::getLength() const{
    return _length;
}

char* MyString::charStr() const {
    assert(_buf);
    return _buf;
}

// + 拼接
MyString MyString::operator + (const MyString &str) {
    assert(_buf&&str._buf);
    unsigned long tmpLen = _length+str.getLength()+1;
    char *tmpStr = new char[tmpLen];
    memcpy(tmpStr, _buf, _length);
    memcpy(tmpStr+_length, str.charStr(), str.getLength()+1);
    tmpStr[tmpLen] = 0;
    MyString s(tmpStr);
    delete []tmpStr;
    return s;
}

MyString MyString::operator + (const char *str) {
    assert(_buf&&str);
    unsigned long strLen = strlen(str);
    unsigned long tmpLen = _length+strLen+1;
    char *tmpStr = new char[tmpLen];
    memcpy(tmpStr, _buf, _length);
    memcpy(tmpStr+_length, str, strLen+1);
    tmpStr[tmpLen] = 0;
    MyString s(tmpStr);
    delete []tmpStr;
    return s;
}

// = 赋值
void MyString::operator = (const MyString &str) {
    _length = str.getLength()+1;
    _buf = (char*)realloc(_buf, _length); // 在原内存上扩展或减小， 也可能重新分配一内存并释放之前的内存。
    assert(_buf);
    memcpy(_buf, str.charStr(), _length);
    _buf[_length] = 0;
}

void MyString::operator = (const char *str) {
    _length = strlen(str)+1;
    _buf = (char*)realloc(_buf, _length); // 在原内存上扩展或减小， 也可能重新分配一内存并释放之前的内存。
    assert(_buf);
    memcpy(_buf, str, _length);
    _buf[_length] = 0;
}

// 比较
bool MyString::operator  < (const MyString &str) {
    assert(_buf && str.charStr());
    int res = strcmp(_buf, str.charStr());
    
    if (0 > res) {
        return true;
    } else {
        return false;
    }
}
                            
bool MyString::operator  > (const MyString &str) {
    assert(_buf && str.charStr());
    int res = strcmp(_buf, str.charStr());
    
    if (0 < res) {
        return true;
    } else {
        return false;
    }
}
                            
bool MyString::operator  == (const MyString &str) {
    assert(_buf && str.charStr());
    int res = strcmp(_buf, str.charStr());
    
    if (0 == res) {
        return true;
    } else {
        return false;
    }
}

// 下标索引
char MyString::operator [] (unsigned long index) {
    if (index >= _length) {
        return 0;
    }
    
    return _buf[index];
}

// 输出
std::ostream& operator<<(std::ostream& out, const MyString& s) {
    out << s.charStr();
    return out;
}
