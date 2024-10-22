# Lesson 04 构造和析构
> `构造函数`和`析构函数`，分别是在类`被创建`和`被销毁`的时候自动调用的函数。

## 一、构造函数

> `构造函数(方法)`的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。构造函数可用于`初始化`和`资源分配`。

### 1. 默认构造函数
> 默认构造函数是不带参数，与类名同名的函数。 即 `类名();` 

```cpp
class Person {
public:
    Person();//默认构造函数 ①
    void showPerson();

    int age;
    float height;
    float weight;
};
Person::Person() { // ②
    cout << "Person构造函数" << endl;
    age = 1;
    height = 1.50;
    weight = 5.0;
}
void Person::showPerson() {
    cout << age << endl << height << endl << weight << endl;
}

int main() {
    Person p;//会自动调用默认的构造函数
    p.showPerson();
    return 0;
}

```
上代码中的①为默认构造函数的声明，②为默认构造函数的实现。

**注意：** 如果类中没有显示的声明和定义任何构造函数，那默认构造函数也是存在的。显示声明和定义后，在创建对象时自然是会调用显示的构造函数。

上述例子终端输出：

```
Person构造函数
1
1.5
5
```

### 2. 带参构造函数
> 除了默认的构造函数外，我们还可以定义带参数的构造函数，扩展类的灵活性。

- 如，上述类中，我们可以这样定义一个构造函数：

```cpp
Person(int age, float height, float weight);//带参构造函数
```
```cpp
Person::Person(int age, float height, float weight) {
    cout << "Person带参构造函数" << endl;
    this->age = age;
    this->height = height;
    this->weight = weight;
}
```
当然也可以是不同的参数列表。

上述带参构造函数，可以如下创建一个对象：

```cpp
int main() {
    Person p;//会自动调用默认的构造函数
    Person per(18, 70, 170);//调用自定义带参构造函数 ③
    per.showPerson();
    return 0;
}
```
代码③处，创建per对象，将会调用对应的带参构造函数。

- 当然也可以定义其他版本的带参构造函数：

```cpp
Person(int age);//带参构造函数，可以定义多个版本，只要参数列表不同。
```

```cpp
Person::Person(int age) {
    cout << "Person 带参构造函数 2" << endl;
    if (age < 0 || age > 100) {
        cout << "请确保年龄在合理范围之类" <<endl;
        age = 1;
    } else {
        this->age = age; // ④
    }
    
    // 其他属性初始化
    height = 0; // 没有同名参数则，同价于this->height = 0;
    weight = 0;
}
```

构造函数的作用是初始化和资源分配，所以可以在中间做一些赋值操作，也可以检测一下合理性。

上述构造函数，可以如下调用：

```cpp
int main()
{
    Person pp1(20);
    pp1.showPerson();
    Person pp2(200); // 传入参数不在合理范围之内
    pp2.showPerson();
    
    return 0;
}
```

终端输出：

```
Person 带参构造函数 2
20
0
0
Person 带参构造函数 2
请确保年龄在合理范围之类
1
0
0

```

在创建pp2对象时，因为传入年龄不合理，所以会打印 `请确保年龄在合理范围之类`

- this指针


在上述的带参构造函数中，比如④处，遇到了类中属性和参数同名的情况，如果写成，age = age; 其实是对形参在进行操作，并不会影响到类中的age；

所以，在的成员函数（方法）中，都有个默认的`this指针`，表示的是`对象本事`，代码写成：

```cpp
this->age = age;
```

意思是把形参age的值赋值给对象中的age属性。

## 二、 析构函数

> 类的析构函数是类的一种特殊的成员函数，它会在每次`销毁（释放）`所创建的对象时执行

析构函数的名称与类的名称是完全相同的，只是在前面加了个`波浪号`（`~`）作为前缀，它`不会返回任何值`，也`不能带有任何参数`。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前`释放资源`。

**例：**

```cpp
~Person();//析构函数，只存在这个唯一版本
```

```cpp
Person::~Person()//析构函数实现
{
    cout << "Person析构函数" << endl;
}
```
在main函数中创建对象，运行即可：

```cpp
int main()
{
	Person p;//会自动调用默认的构造函数 ①
} // ②
```

终端输出：

```
Person默认构造函数
Person析构函数
```
在运行代码①时，创建对象，所以调用了构造函数，即打印：`Person默认构造函数`；在代码②处，main函数结束，也意味着p的生命周期结束，会被自动销毁，即调用了析构函数，所以打印：`Person析构函数`。

当然，如下代码也是同理：

```cpp
Person* p3 = new Person(18); // 创建对象,调用带参构造函数
delete p3; // 释放对象
```

- 分配资源和销毁资源

利用构造函数和析构函数，可以很好的管理对象的资源
比如，通过`构造函数`给对象的某些成员属性`分配内存空间`，在对象销毁时，通过`析构函数``释放`对应成员属性的`内存`。

**例：** 

```cpp
Person::Person()
{
    cout << "Person默认构造函数" << endl;
    age = 1;
    height = 1.50;
    weight = 5.0;
    
    // 分配name指针内存
    name = new char[32]; // ①
}
```

```cpp
Person::~Person()//析构函数实现
{
    cout << "Person析构函数" << endl;
    
    // 释放name的内存空间
    if (name != NULL) {
        delete[] name; // new[] 对应 delete[] ②
        name = NULL; // 置空，好习惯
    }
}
```

代码①中，在Person的构造函数中动态分配了内存空间，则对应的在析构函数中进行释放，代码②处。


## 总结：

- 构造函数在对象被创建的时候调用，析构函数在对象被释放的时候调用。
- 构造函数用来初始化和分配资源，析构函数用来释放资源。
- 构造函数可以有多个版本（参数列表不同），析构函数只能有一个。

本文[示例代码](./code_04.cpp)


