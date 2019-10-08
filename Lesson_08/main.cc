#include <iostream>
#include <string>
#include "MyString.h"

using namespace std;

// string 类，极大的方便我们对字符串的使用。
int main1() {
    
//    char *name = NULL;
//    name = new char[100];
//    strcpy(name, "张三疯");
//    cout << name << endl;
//    delete []name;
//
//    string nameStr;
//    nameStr = "张三疯";
//    cout << nameStr << endl;
    
    // 更多用法：
    // + 重载
    string a = "hello";
    string b = " world";
    
    string c;
    c = a+b; // = 重载
    cout << c << endl;// << 重载
    
    cout << (a > b) << endl; // > 重载
    cout << (a < b) << endl; // < 重载
    cout << (a == c) << endl; // == 重载
    cout << a[0] << endl; // [] 重载
    
    return 0;
}

int main() {
    MyString a = "hello"; // 带参构造函数
    MyString b(" world");
    
    MyString c = (a+b); // 拷贝构造 、 +重载
    MyString d;
    d = c; // = 重载
    
    cout << c << endl; // << 重载
    
    cout << (a > b) << endl; // > 重载
    cout << (a < b) << endl; // < 重载
    cout << (d == c) << endl; // == 重载
    
    cout << a[0] << endl; // [] 重载
    
    
    return 0;
}
