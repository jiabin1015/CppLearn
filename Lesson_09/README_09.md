# Lesson 09 继承
在现实生活中，`继承`也是一个比较普遍的概念，比如说`猫科类`动物，其下又可细分为`猫类`、`豹类`、`老虎类`等等；当然`猫类`下面又可以细分更多类，其他亦然。

> 一个新类从已有的类那里获得已有的成员，这种现象称为类的`继承`。
> 新定义的类称为`派生类`或`子类`，已有类称为`基类`或`父类`。

## 一、单继承
> 继承关系中，只有一个`基类`和`派生类`的情况。

### 1. 定义语法

```cpp
class derived-class: access-specifier base-class
```

derived-class：派生类；access-specifier：继承权限；base-class：基类。

如：

```cpp
#include <iostream>
using namespace std;

// 基类 ①
class Shape
{
public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }
protected:
    int width;
    int height;
};

// 派生类 ②
class Rectangle: public Shape
{
public:
    int getArea()
    {
        return (width * height); // ③
    }
};

int main(void)
{
    Rectangle Rect;
    
    Rect.setWidth(10);
    Rect.setHeight(13);
    
    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;
    
    // 类占用内存大小 ④
    cout << "size Shape:" << sizeof(Shape) << endl;
    cout << "size Rectangle:" << sizeof(Rectangle) << endl;
    return 0;
}

```

- ①处，为`Shape`类的定义。
- ②处，`Rectangle`类以`public`权限继承`Shape`类。
- ③在派生类`Rectangle`中，可以正常访问`width`和`height`属性。
- ④处，终端都是输出两个类的大小`8`（内存只存储数据部分，方法存放在代码区），间接可以得出，Rectangle类中包含了`width`、`height`两个属性。

## 二、 继承权限

> 首先回忆一下类的访问权限，即`public`、`protected`、`private`。

这里不赘述，可以[翻回去](../Lesson_06/README_06.md)看看。

统一继承也有权限：`public`、`protected`、`private`

- 公有继承（`public`）：当一个类派生自`公有基类`时，基类的`公有成员`也是派生类的`公有成员`，基类的`保护成员`也是派生类的`保护成员`，基类的`私有成员``不能`直接被派生类`访问`。

- 保护继承（`protected`）： 当一个类派生自`保护基类`时，基类的`公有`和`保护成员`将成为派生类的`保护成员`。

- 私有继承（private）：当一个类派生自`私有基类`时，基类的`公有`和`保护成员`将成为派生类的`私有成员`。

如下表：

|继承方式/基类成员|public成员|protected成员|private成员|
|--|--|--|--|
|public继承|public|protected|不可见|
|protected继承|protected|protected|不可见|
|private继承|private|private|不可见|
  

**例子：** 

```cpp
class A       //父类
{
private:
    int privateDataA;
protected:
    int protectedDateA;
public:
    int publicDateA;
};

class B :public A      //基类A的派生类B（公有继承）
{
public:
    void funct()
    {
        int b;
        b = privateDataA;   //错误：基类中私有成员在派生类中是不可见的
        b = protectedDateA; //基类的保护成员在派生类中为保护成员
        b = publicDateA;    //基类的公共成员在派生类中为公共成员
    }
};

class C :private A  //基类A的派生类C（私有继承）
{
public:
    void funct()
    {
        int c;
        c = privateDataA;    //错误：基类中私有成员在派生类中是不可见的
        c = protectedDateA;  //基类的保护成员在派生类中为私有成员
        c = publicDateA;     //基类的公共成员在派生类中为私有成员
    }
};

class D :protected A   //基类A的派生类D（保护继承）
{
public:
    void funct()
    {
        int d;
        d = privateDataA;   //错误：基类中私有成员在派生类中是不可见的
        d = protectedDateA; //基类的保护成员在派生类中为保护成员
        d = publicDateA;    //基类的公共成员在派生类中为保护成员
    }
};

int main()
{
    int a;
    
    B objB;
    a = objB.privateDataA;   //错误：基类中私有成员在派生类中是不可见的,对对象不可见
    a = objB.protectedDateA; //错误：基类的保护成员在派生类中为保护成员，对对象不可见
    a = objB.publicDateA;    //基类的公共成员在派生类中为公共成员，对对象可见
    
    C objC;
    a = objC.privateDataA;   //错误：基类中私有成员在派生类中是不可见的,对对象不可见
    a = objC.protectedDateA; //错误：基类的保护成员在派生类中为私有成员，对对象不可见
    a = objC.publicDateA;    //错误：基类的公共成员在派生类中为私有成员，对对象不可见
    
    D objD;
    a = objD.privateDataA;   //错误：基类中私有成员在派生类中是不可见的,对对象不可见
    a = objD.protectedDateA; //错误：基类的保护成员在派生类中为保护成员，对对象不可见
    a = objD.publicDateA;    //错误：基类的公共成员在派生类中为保护成员，对对象不可见
    
    return 0;
}
```


## 三、 隐藏

> `隐藏`是指派生类的成员屏蔽了与其同名的基类成员。

> 如果派生类中的`成员`（包括成员变量和成员函数）和基类中的`成员重名`，那么就会`隐藏`从基类继承过来的成员。

如下，基类定义：

```cpp
class People{
public:
    void showDetail(); // ①.1
protected:
    string name;
    int age;
};
void People::showDetail(){
    cout<<"我叫"<<name<<"，今年"<<age<<"岁"<<endl;
}
```

派生类定义：

```cpp
class Student: public People{
public:
    Student(string name, int age, float score);
public:
    void showDetail();  // ①.2
private:
    float m_score;
};
```
上述定义中，基类`People`类中`showDetail()`方法和派生类`Student`类中有同名的方法，即 ①.1和①.2处。

此时派生类`Student `中就会产生`覆盖`行为，如下调用：

```cpp
int main(){
    Student stu("小明", 18, 88.8);
    //使用的是Student类里面的成员函数
    stu.showDetail(); // ②
    //使用的是从Perple类继承来的成员函数
    stu.People::showDetail(); // ③
    return 0;
}
```

派生类`Student`的对象`stu`，在调用`showDetail()`方法时，就会调用派生类中的成员函数。即代码②处。

当然基类`People`类中的`showDetail()`方法也同样被继承了下来，只是被`隐藏`了，如果要调用，则需`显示`调用，即代码③处。

- 基类成员函数和派生类成员函数不构成重载

**例：** 

```cpp
//基类People
class People{
public:
    void showDetail();
    void doSomething(string things);
protected:
    string name;
    int age;
};

// ①
void People::doSomething(string things) {
    cout << "do " << things << endl;
}


//派生类Student
class Student: public People{
public:
    Student(string name, int age, float score);
    void showDetail();  //覆盖基类的showDetail()方法
    void doSomething();
private:
    float m_score;
};

// ②
void Student::doSomething() {
    cout << "just do it" << endl;
}
```
上述代码中，①为基类中的成员函数，②为派生类中的成员函数

```cpp
int main(){
    Student stu("小明", 18, 88.8);
        
    stu.doSomething();
    stu.doSomething("home work"); // ① 编译错误
    
    stu.People::doSomething("home work"); // ②
    return 0;
}
```
①处调用会报编译错误，而正确调用是使用②处代码。这正验证了： 
> 继承关系中，对于基类和派生类的同名函数，不管函数的参数如何，只要名字一样就会造成隐藏而不是重载。


## 总结：
- 继承是面向对象开发语言中最基础的特性之一
- 继承分为单继承和多继承（后续章节学习）。
- 继承权限同样分为公有、私有和受保护的，同时受成员访问权限影响，决定了基类成员在派生类中的权限。
- 隐藏是继承中的一个重要特点，派生类中成员会屏蔽基类中同名的成员，而不会构成重载。

本节[示例代码1](./main1.cc)

本节[示例代码2](./main2.cc)





