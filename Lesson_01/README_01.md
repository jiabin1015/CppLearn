# Lesson 01 C++基础语法
> 主要介绍区别于C语言的常用基础语法

## 一、C++标准输出
### 1. 引入头文件：iostream。
- 标准输入输出流头文件，i == in；o == out

```cpp
#include <iostream> 
```
### 2. std::cout  标准输出

- std::cout,将其后面的内容，输出至标准输出设备（终端）。
- std::endl 为换行在Linux下等价于"\r\n"。

**例** 输出字符串：

```cpp
std::cout << "hello, world" << std::endl; 
```
终端打印：`hello, world`

**例** 输出变量：

```cpp
int count  = 10;
std::cout << count << std::endl;
```
终端打印：`10`

**例** 输出变量+字符串组合

```cpp
int a = 10;
int b = 20;
std::cout << "a+b=" << a+b << std::endl;
```
终端打印：`a+b=30`

- **注意：** std::cout后面的双箭头(<<)方向，可译为，箭头后面的内容流向标准输出设备(std::cout)。


## 二、C++标准输入
### std::cin 标准输入

- 同样需要引入头文件 iostream
- std::cin 从标准输入设备读取用户输入的值，并将值赋值给 双箭头(>>) 后的变量。

```cpp
std::cin >> 变量名；
```

**例** 

```cpp
int age = 0;
float height = 0.0f;
char name[100] = {0};

std::cout << "请输入你的年龄:" << std::endl;
std::cin >> age; // 输入年龄
std::cout << "请输入你的身高:" << std::endl;
std::cin >> height; // 输入身高
std::cout << "请输入你的姓名:" << std::endl;
std::cin >> name; // 输入姓名
std::cout << "你的年龄为:" << age << std::endl;
std::cout << "你的身高为:" << height << std::endl;
std::cout << "你的姓名是:" << name << std::endl;
```
终端中交互输出为：

```
请输入你的年龄:
22
请输入你的身高:
175.0
请输入你的姓名:
binson
你的年龄为:22
你的身高为:175
你的姓名是:binson
```

**注意：** 

- std::cin 后面的双箭头(>>)方向，跟cout想反，可译为，从标准输入设备（std::cin）中读取内容流向其后的变量地址中。
- std::cin >> 后直接跟变量名，而不需要在变量前加&符号。


## 三、命名空间

> 命名空间实际上是用来解决“重名”的问题

如，大班有个张三，小班也有个张三，在某次全校大会上，校长要表扬大班的张三，则会称“大班的张三”。其中`张三`为`重名`，`大班`和`小班`为`命名空间`。

### 1. 命名空间定义：
命名空间的定义使用关键字 `namespace`，后跟命名空间的名称

```cpp
namespace namespace_name {
   // 代码声明
}
```

**例：** 

```cpp
// 第一个命名空间
namespace funSpace1{
   void func(){
      cout << "funSpace1" << endl;
   }
}
// 第二个命名空间
namespace funSpace2{
   void func(){
      cout << "funSpace2" << endl;
   }
}

```
### 2. 使用
```cpp
name::code;  // code 可以是变量或函数
```
接上述案例

```cpp
int main() {
  // 调用第一个命名空间中的函数
  funSpace1::func();
  // 调用第二个命名空间中的函数
  funSpace2::func(); 
}
```

### 3. using 指令
- 使用 `using namespace` 指令，告诉编译器，后续的代码将使用指定的命名空间中的名称。

```cpp
using namespace 空间名;
```

**例：** 接上述案例

```cpp
using namespace funSpace1; // 使用funSpace1命名空间
int main() {
  // 调用funSpace1命名空间中的func函数
  func();
}
```

- std 命名空间

```cpp
using namespace std;
```
使用如上代码后，所有`std::`都可以省略，如：

```cpp
cout << "whit out std::" << endl;
// 使用using namespace std;后，cout等价于std::cout，其他语法同理
std::cout << "whit std::" << std::endl;
```

### 4. 嵌套的命名空间
可以在一个命名空间中定义另一个命名空间：

```cpp
namespace space1 {
   // 代码声明
   namespace space2 {
      // 代码声明
   }
}
```

**例:**

```cpp
// 第一个命名空间
namespace space1{
   void funSpace(){
      cout << "Inside first_space" << endl;
   }
   // 第二个命名空间
   namespace space2{
      void funSpace(){
         cout << "Inside second_space" << endl;
      }
   }
}

using namespace space1::space2; // 使用嵌套命名空间space2
int main() {
  // 以下两语句同义
  space1::space2::funSpace();
  funSpace();
}
```

**注意：** 命名空间

## 总结：
本次主要记录，C++ iostream中的标准输入输出的使用、命名空间的定义和使用。

本文[示例代码](./code_01.cpp)
