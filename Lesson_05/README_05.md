# Lesson 05 拷贝构造函数
> `拷贝构造函数`是一种特殊的构造函数，它在创建对象时，是使用同一类之前创建的对象来初始化新创建的对象。

## 一、 定义和使用

```cpp
类名(const 类名 &形参名);
```

如下**定义**：

```cpp
class Person
{
public:
    Person();//默认构造函数
    Person(int age, float height, float weight);//带参构造函数
    Person(const Person &p);//拷贝构造函数 ①
    ~Person();//析构函数，只存在这个唯一版本
    void showPerson();

    int age;
    float height;
    float weight;
};
```

代码①处，即为Person类的，拷贝构造函数。以下为其实现：

```cpp
Person::Person(const Person &p)//拷贝构造函数实现
{
	// 用p对象的属性，初始化本对象（this)的属性。
    age = p.age;
    height = p.height;
    weight = p.weight;
    cout << "Person拷贝构造函数" << endl;
}
```
**调用：**

- 通过使用另一个同类型的对象来初始化新创建的对象。

```cpp
int main()
{
    Person p(18, 75, 180);
    Person per = p;//用存在的对象创建新对象，调用拷贝构造函数。
    //Person per(p);//调用拷贝构造函数
    per.showPerson();
    return 0;
}
```
终端输出：

```
Person带参构造函数
Person拷贝构造函数
age:18 height:75 weight:180
Person析构函数
Person析构函数
```

- 复制对象把它作为参数传递给函数。
- 复制对象，并从函数返回这个对象。

```cpp
// 对参数p进行修改后，返回
Person growUp(Person p /*①*/)
{
    p.age += 20;
    p.height += 1;
    p.weight += 20; //  人到中年什么都不易，除了易胖
    
    return p; // ②
}
```

```cpp
int main()
{
    
    Person young(18, 70, 170);
    Person old = growUp(young);
    
    return 0;
}
```

上例代码中，①处当有实参传入时，会调用拷贝构造函数；同理②处代码，当返回有对象接受时，也会调用拷贝构造函数。

终端输出：

```
Person带参构造函数
Person拷贝构造函数
Person拷贝构造函数
Person析构函数
age:38 height:71 weight:190
Person析构函数
Person析构函数
```


## 二、浅拷贝与深拷贝

- 浅拷贝，如下代码示例：

```cpp
#include <iostream>

using namespace std;

class Person
{
public:
    Person();//默认构造函数
    Person(const char* name, int age, float height, float weight);//带参构造函数
    ~Person();//析构函数，只存在这个唯一版本
    void showPerson();
    
private:
    char * name;//姓名定义为指针类型  ①
    int age;
    float height;
    float weight;
};

Person::Person()
{
    cout << "Person默认构造函数" << endl;
    // ②.1
    name = new char[32];
    strcpy(name, "Lily");
    age = 1;
    height = 1.50;
    weight = 5.0;
}

Person::Person(const char* n, int a, float h, float w) :
age(a),//基础类型变量直接赋值
height(h),
weight(w)
{
    // ②.2
    name = new char[strlen(n)+1];
    strcpy(name, n);
    cout << "Person带参构造函数" << endl;
}
Person::~Person()//析构函数实现
{
    cout << "Person析构函数" << endl;
    delete[]name; // ③
}
void Person::showPerson()
{
    cout << "name" << name << " age:" << age << " height:" << height << " weight:" << weight << endl;
}
int main()
{
    Person p("张三疯", 88, 175, 70);
    Person per(p); // ④
    
    p.showPerson();
    per.showPerson();
    return 0;
}
```

上述示例中，

- ①处，为类的成员属性，类型是指针，如果要给其赋值，则需要分配内存空间。
- ②.1和②.2处，在构造函数中，先分配内存空间，在赋值。
- ③处，析构函数释放内存空间。
- ④处，使用已存在的对象创建新对象，调用拷贝构造函数。

**问题：** 运行上述代码，程序在④处奔溃。

原因：p对象调用构造函数申请内存空间（②.2处），而，per对象在创建时，调用的拷贝构造函数（虽然代码没有实现，但也存在）只是简单的进行赋值，如下：

```cpp
Person::Person(const Person &p)
{
    name = p.name; // ⑤
    age = p.age;
    height = p.age;
    weight = p.weight;
}
```
上述代码⑤处，为`浅拷贝`，简单的赋值，导致两个指针指向了同一个内存地址。

由此，两个对象的name都指向了同一个内存地址，而析构时（③处）同一内存地址，释放两次导致崩溃。

- 深拷贝

只需将拷贝构造函数中代码进行如下修改：

```cpp
Person::Person(const Person &p)
{
//    name = p.name; // ⑤
    
    // 深拷贝 ⑥
    name = new char[strlen(p.name)+1];
    strcpy(name, p.name);
    
    age = p.age;
    height = p.age;
    weight = p.weight;
}
```

代码⑥处，先对本对象（this）的name进行内存分配，再进行字符串拷贝（赋值）。如此析构时，就是释放自己申请的内存地址，而不会引起奔溃。

## 总结：

- 拷贝构造函数是在用已存在的对象创建新对象的时候被调用。
- 只包含类类型成员或内置类型（但不是指针类型）成员的类，无须显式地定义拷贝构造函数也可以拷贝。
- 有的类有一个数据成员是指针，或者是有成员表示在构造函数中分配的其他资源，这两种情况下都必须定义拷贝构造函数，且进行深拷贝。

拷贝构造函数[示例代码](./code_05_01.cpp)

深拷贝[示例代码](./code_05_02.cpp)









