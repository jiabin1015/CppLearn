# Lesson 02 引用类型
> 引用是C++相对于C扩展的一种类型，其作用是为某个变量定义一个`别名`。

则，通过`原变量`和`别名`都能操作该对应的内存数据。

## 一、定义和使用
- 语法

```
datatype &ref_name = origin_name;
```
`datatype`是数据类型，与origin_name变量的类型一致；`ref_name`是引用的变量名（`别名`），`origin_name`是被引用的变量名（`原名称`）；

如：

```
int a = 10;
int &a1 = a; // 引用，a1为a的别名
```
以上定义后，a1为a的别名，意味着，对a1的操作等同于对a的操作，反之亦然。如：

```
cout << "a:" << a << endl;
cout << "a1:" << a1 << endl;
    
a1 = 20;
cout << "a:" << a << endl;
cout << "a1:" << a1 << endl;
```
终端输出为：

```
a:10
a1:10
a:20
a1:20
```

- 注意：引用在定义的时就必须初始化，否则会编译报错。如：

```
int &a1; // error:Declaration of reference variable 'a1' requires an initializer
```

## 二、引用的本质

先看引用变量的内存地址。

```
int a = 10;
int &a1 = a; // 引用，a1为a的别名
// 输出 a和a1的内存地址
cout << &a << ", " << &a1 << endl;
```
终端打印：`0x7ffeefbff5ec, 0x7ffeefbff5ec`

可以看出，`a和a1`两个变量都是“指向”`同一个地址`的；这样就能解释为什么对a或a1进行操作，能影响另一个。

> 引用的本质实际上是`指针的封装`。

是一个指向原变量内存地址的指针，封装了内部实现，使用起来相较指针而言更为简单。


### 三、 引用作为函数参数
> 因为引用是别名的这一特质，在参数传递过程中，可以`提高速度`和`减少内存开销`；同时函数内部也可以`修改实参`。

- 语法：

> datatype functionName(`datatype &param`, ...)

- 函数内部修改实参

 **例：** 定义swap函数，实现两个值的交换

```
void swap(int &a, int &b) {
    // 形参为引用变量，相当于  int &a = a; (=号左边为形参a，=号右边为实参a)
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    
    int a = 10;
    int b = 20;
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    
    swap(a, b); // 调用交换函数
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
}
```
终端输出：
```
a:10
b:20
a:20
b:10
```

交换实参的值，是对引用传递比较经典的例子，那如果在函数内部不需要修改实参的值，那形参定义为引用或普通变量的区别又是什么呢？

- 提高传递速度、减少内存开销

	**例：** 显示一个学生信息
	
形参为普通变量：
	
```
void funShowStudent1(Student s) {
    cout << "姓名：" << s.name << endl;
    cout << "年龄：" << s.age << endl;
    cout << "身高：" << s.height << endl;
    cout << "体重：" << s.weight << endl;
    // 打印其他信息。
}
```

形参为引用变量：

```
void funShowStudent2(Student &s) {
    cout << "姓名：" << s.name << endl;
    cout << "年龄：" << s.age << endl;
    cout << "身高：" << s.height << endl;
    cout << "体重：" << s.weight << endl;
    // 打印其他信息。
}

```

main函数中调用：

```
int main() {

    Student stu;
    strcpy(stu.name, "binson");
    stu.age = 24;
    stu.height = 172.5;
    stu.weight = 68.8;
    
    funShowStudent1(stu);
    funShowStudent2(stu);
}
```

终端输出：

```
main_stu的内存地址：0x7ffeefbff5b8
show1_stu的内存地址：0x7ffeefbff510
姓名：binson
年龄：24
身高：172.5
体重：68.8
show2_stu的内存地址：0x7ffeefbff5b8
姓名：binson
年龄：24
身高：172.5
体重：68.8
```

观察可得知，普通类型形参的地址`不同于`实参变量的地址；所以funShowStudent1函数在调用过程中，形参需`开辟新的内存`存放数据。而引用变量使用实参同一个内存。

如果涉及到`深拷贝`情况更复杂，在后续章节记录。


因为在函数内部不需要对实参进行修改，所以形参使用`常引用`进行传递，提高安全性。

如下：`const Student &s`

```
void funShowStudent(const Student &s) {
    cout << "姓名：" << s.name << endl;
    cout << "年龄：" << s.age << endl;
    cout << "身高：" << s.height << endl;
    cout << "体重：" << s.weight << endl;
    // 打印其他信息。
    
    // 不能对常引用变量进行修改
    //s.height = 180.0; // error：Cannot assign to variable 's' with const-qualified type 'const Student &' (aka 'const _student &')
}
```

### 四、 引用作为函数返回值

- 语法

> `datatype&` functionName(...)

**例：**

```
int& funExample2() {
    int a = 10;
    a += 10;
    return a; // warning：Reference to stack memory associated with local variable 'a' returned
}
```
**大写的错误:** 不能返回`局部变量`的引用。这个错误编译时只会报警告，在运行时会程序奔溃。

不能返回局部变量的引用，但可以返回，静态变量，全局变量的引用。如：

```
int& funExample3() {
    static int a = 10; // 静态变量
    a += 10;
    return a; 
}

```

在main函数中调用：

```
int &res = funExample3();
cout << res << endl;
```


### 总结：
- 引用变量的数据类型必须与原数据类型一致。
- 引用声明的时候就必须初始化，且不能更改引用对象
- 可对引用再次引用。多次引用的结果，是某一个变量具有多个别名。
- 引用可作为函数的参数或返回值，返回值不能返回局部变量的引用。









