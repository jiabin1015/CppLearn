# Lesson 03 类和对象
> C++是`面向对象`的编程，`类和对象`是面向对象编程中两个最基础也是最重要的概念。

## 一、 类的定义

> 类用来描述一个对象（具体的事物）的组成，类包含`属性`和`方法`。

实际上C++中的类和C语言中的结构体有很多相似之处。

### 1. 定义类

```cpp
class 类名 {
访问权限：
	成员
};
```

**例子：** 定义一个盒子类

```cpp
class Box { // 类名
public: // 成员访问权限
    // 成员
    float length;  // 盒子的长度
    float Width;   // 盒子的宽度
    float height;  // 盒子的高度
};
```

### 2. 定义对象

有了上述的Box类，则可以用其定义对象，如;

```cpp
Box box1;
Box* box2;
```

box1、box2都称为对象或实例。实际上对比C语言，Box就是一个类型，box1就是一个变量。只是，Box是我们自定义的类型。

## 二、 访问成员

- 访问对象的成员，运算符` . `（点）。

```cpp
int main() {
    
    Box box1;
    
    box1.length = 10; // 访问 length 成员
    box1.width = 10;
    box1.height = 20;
    
    cout << "box1的体积为：" << box1.length * box1.width * box1.height << endl;
    
    return 0;
}
```

- 访问对象的成员，运算符` -> `。

```cpp
int main() {
    
    Box* box2;
        
    //先给box2分配内存
    box2 = new Box; // 相当于,box2 = (Box*)malloc(sizeof(Box));
    box2->length = 15; // 指针访问成员
    box2->width = 21.5;
    box2->height = 18.6;
    
    cout << "box2的体积为：" << box2->length * box2->width * box2->height << endl;
    delete box2; // 相当于，free(box2)
    
    return 0;
}
```

## 三、 成员方法
成员，包括`属性`和`方法`；属性可以理解为类中的`变量`或`对象`、成员可以理解为`函数`。

**例子：** 定义一个体积方法

```cpp
class Box { // 类名
public: // 成员访问权限
    // 成员
    float length;  // 盒子的长度
    float width;   // 盒子的宽度
    float height;  // 盒子的高度
    
    float theVolume() { // 盒子的体积方法
        return length * width * height;
    }
};
```
以上定义方式为，在类中直接定义方法。

以下方式是，在勒种声明方法，在类外定义方法：

```cpp
class Box { // 类名
public: // 成员访问权限
    // 成员
    float length;  // 盒子的长度
    float width;   // 盒子的宽度
    float height;  // 盒子的高度
    
    // 体积方法的声明
    float theVolume();
};

// 体积方法的定义 注意加上Box::
float Box::theVolume() {
    return length * width * height;
}
```

调用：

```cpp
cout << "box1的体积为：" << box1.theVolume() << endl;
cout << "box2的体积为：" << box2->theVolume() << endl;
```


## 总结

- 类的定义使用`class`关键字，跟C语言中的`struct`类似。
- 类被定义后，可以理解为定义了一个新类型，可以使用其定义变量(实例化对象）。
- 类的成员分为`属性`(变量、对象)和`方法`(函数)。
- 类的对象(或叫实例)，通过运算符`.`访问成员，指针对象通过`->`访问。

本文[示例代码](./code_03.cpp)
