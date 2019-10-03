# Lesson 06 封装
> 封装是面向对象编程中一个重要的概念，是把`数据`和操作数据的`函数`绑定在一起的一种机制。 这样能避免受到外界的干扰和误用，从而确保了`安全`。

封装可以`隐藏`数据和实现细节，达到数据的`安全`和`独立性`，也使得代码`模块化`。

## 一、数据隐藏
访问权限：

- public：公有访问权限，在类中内外均可访问。
- protected：受保护的，只能在类和派生类中访问，类外不能访问。（派生类的知识在后续章节）
- private：私有的，只能在本类中访问。


**例：** private、protected访问权限

```cpp
#include <iostream>

using namespace std;
class Person
{
    const char* name; // ①.1
    
private: // ①
    int age;
    
protected: // ②
    char sex;
    void showMe();
};

void Person::showMe()
{
    cout << "My name is " << name <<endl;
    cout << "I'm " << age << " now" << endl;
}

int main()
{
    Person p;//用类实例化一个对象。
    p.age = 19;// ③
    p.sex = 'f';// ④
    return 0;
}
```

上例代码中：

- ①处声明其下代码为`private`访问权限。即，`age`为私有。
- 如没有任何声明，则默认为`private`访问权限，如①.1处。即，`name`为私有。
- ②处声明其下代码为`protected`访问权限。即，`sex`和`showMe()`为受保护的。
- ③处在`main`函数中（类外）访问`age`私有属性，则会编译报错：`'age' is a private member of 'Person'`。
- ③处在`main`函数中（类外）访问`sex`受保护的属性，则会编译报错：`'sex' is a protected member of 'Person'`。


> `数据隐藏`是作为封装的基本组成，其能为类带来安全性，限制非法访问和误用。


## 二、数据封装
> 封装是把`数据`和操作数据的`函数`绑定在一起的一种机制。

上述中已经将数据隐藏，那接下来只需将隐藏的数据，通过`函数`（方法）暴露给外部使用。

**例：** 定义一个日期类：

```cpp
class MyDate//日期类
{
	int year;
	int month;
	int day;
};
```

MyDate类，将year、month、day私有化，因为年月日，在外部可能会存在非法操作的因素，比如，`month = 13;` `day = -1;` 之类。月份应该限制在`1~12`，而天数应该限制在`1~31`。

接下来，通过`函数`（方法）暴露给外部，使其能间接访问。

```cpp
class MyDate//日期类
{
    int year;
    int month;
    int day;
public:
    void setYear(int year); // 设置年份
    void setMonth(int month); // 设置月份
    void setDay(int day); // 设置日
    
    void showDate(); // 显示日期
};


void MyDate::setYear(int year)
{
    if (year < 1970) {
        cout << "年份设置不合法" << endl;
        return;
    }
    this->year = year;
}

void MyDate::setMonth(int month)
{
    if (month <= 0 || month >= 13)
    {
        cout << "月份设置不合法" << endl;
        return;
    }
    this->month = month;
    this->day = 1; // 重置日
}

void MyDate::setDay(int day)
{
    if (month <= 0 || month >= 13)
    {
        cout << "请先设置合法月份" << endl;
        return;
    }
    if (day <= 0 || day > 31)
    {
        cout << "请设置合法的日期" << endl;
        return;
    }
    if (month == 4 || month == 6 ||
        month == 9 || month == 11)
    {
        if (day > 30)
        {
            cout << month << "月没有" << day << "日" << endl;
            return;
        }
    }
    if (2 == month)
    {
        if ((year % 4 == 0 && year % 100 == 0) ||
            year % 400 == 0)//闰年
        {
            if (day > 29)
            {
                cout << year << "的2月没有" << day << "日" << endl;
                return;
            }
        }
        else
        {
            if (day > 28)
            {
                cout << year << "的2月没有" << day << "日" << endl;
                return;
            }
        }
    }
    this->day = day;
}

void MyDate::showDate()
{
    cout << year << "-" << month << "-" << day << endl;
}

int main()
{
    MyDate d;
    d.setYear(2000);
    d.setMonth(12);
    d.setDay(28);
    d.showDate();
    return 0;
}

```

上述代码，通过`public`的方法`setYear`、`setMonth`、`setDay`方法（`接口`）实现了，对`private`属性`year`、`month`、`day`的访问；在方法内部也做了限制，杜绝非法操作。

终端输出：
```
2000-12-28
```

按如下方式访问：

```cpp
MyDate d;
d.setYear(2001);
d.setMonth(2);
d.setDay(29);
```

则终端输出：
```
2001的2月没有29日
```



## 总结：
- `private`、`protected`、`public`的访问权限。
- `数据封装`是一种把数据和操作数据的函数捆绑在一起的机制。
- `数据抽象`是一种仅向用户暴露`接口`(方法)而把具体的实现细节隐藏起来的机制。
- 尽量设置类`成员`状态为`private`，除非真的需要将其暴露，这样才能保证良好的`封装性`。

本章[示例代码](./code_06.cpp)












