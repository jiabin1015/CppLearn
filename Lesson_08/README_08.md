# Lesson 08 自定义string类
> C++ 标准库提供了 `string` 类，跟方便字符串的处理。

## 一、string基本使用

### 1. C风格字符串对比

```cpp
char *name = NULL;
name = new char[100];
strcpy(name, "张三疯");
cout << name << endl;
delete []name;
```

C风格字符串，需要自己申请内存，释放内存，使用`strcpy`(字符串拷贝)等库函数进行处理。

而，`string`字符串相比较就比较简单：

```cpp
string nameStr;
nameStr = "张三疯";
cout << nameStr << endl;
```

string对象，不需要使用者管理内存，使用 `=`直接赋值，简单直观。

### 2. string运算符使用

```cpp
string a = "hello";
string b = " world";
    
string c;
c = a+b; // = 重载
cout << c << endl;// << 重载
    
cout << (a > b) << endl; // > 重载
cout << (a < b) << endl; // < 重载
cout << (a == c) << endl; // == 重载
cout << a[0] << endl; // [] 重载
```

上述使用了，`=`、`<<`、`<`、`>`、`==`、`[]`运算符。如果是C风格的字符串，相对来说比较麻烦，这里则不做对比。



## 二、自定义string类

> `string`类功能很强大，我们可以利用前几节所学知识，自实现一个基础的MyString类。

### 1、构造和析构函数

```cpp
class MyString {
    
public:
    // 构造方法
    MyString(); // ①
    MyString(const MyString &str);// ②
    MyString(const char *str);// ③
    ~MyString();// ④
    
    // 成员方法 ⑤
    unsigned long getLength() const;
    char* charStr() const;
    
private:
    unsigned long _length; // 字符串长度
    char *_buf; // 缓存
};
```

- ①用来实例化默认对象，如`MyString s;`或`MyString *ps = new MyString;`。
- ②拷贝构造函数，用于一个已知对象创建另一个对象。
- ③使用`常量字符串`创建一个对象，如`MyString a = "hello";`或`MyString b(" world");`。
- ④析构函数，当对象被释放或销毁的时候调用。
- ⑤此两个成员方法，是只读的，为了保证私有成员的安全性。

其实现如下：

```cpp
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

// 获取字符串长度，const表示函数内部不允许修改成员
unsigned long MyString::getLength() const{
    return _length;
}

char* MyString::charStr() const {
    assert(_buf);
    return _buf;
}
```

### 2. 运算符重载

public成员方法：

```cpp
// 运算符重载
// + 拼接 // ①
MyString operator + (const MyString &str); // ①.1
MyString operator + (const char *str);// ①.2
    
// = 赋值 ②
void operator = (const MyString &str); // ②.1
void operator = (const char *str); // ②.2
    
// < > == ③
bool operator  < (const MyString &str);
bool operator  > (const MyString &str);
bool operator  == (const MyString &str);
    
// [] ④
char operator [] (unsigned long index);
```

- ①分别实现两个对象拼接和，一个对象与常量字符串拼接，如：

```cpp
MyString a = "hello"; 
MyString b(" world");
a + b; // ①.1
a + " world"; // ①.2
```

- ②分别实现将一个已知对象赋值给一个已知对象和，将一个常量字符串赋值给一个已知对象，如：

```
MyString a = "hello"; 
MyString b;
b = a;// ②.1
b = "Hello" // ②.2
```

- ③两个对象进行比较，如`a > b;`、`a < b;`、`a == b;`
- ④下标索引，获取第N个下标对应的值。如`cout << a[0] << endl;`

具体实现如下：

``` cpp
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
```

上述代码中，最后一个方法，`输出`，是对`<<`运算符的重载，所以不是`MyString`类的成员方法。


## 总结：
- `string`类极大的方便了我们对字符串的操作，其中还有许多其他功能成员方法，可以自行查阅其他资料。
- 实现基础的`MyString`类主要是对，构造和析构函数的熟练运用，已经对运算符重载的熟练运用。
- 上述功能，写法各一，可以多多练习，再加上自己的理解进行改进。

本章[示例代码](./main.cc)