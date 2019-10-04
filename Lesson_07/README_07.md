# Lesson 07 重载
> C++ 允许在同一作用域中的某个函数和运算符指定多个定义，分别称为`函数重载`和`运算符重载`。

## 一、函数重载

> 在同一个作用域内，可以声明几个`同名函数`，但是这些同名函数的`形式参数`（指参数的个数、类型或者顺序）必须`不同`。

其实在上章节中学习的`构造函数`，可以定义多个版本，就属于函数重载。

**例：** 定义函数，实现两个数交换

```cpp
void numSwap(int &a, int &b);   //  两个整数交换
void numSwap(float &a, float &b);//  两个浮点数交换
void numSwap(char &a, char &b);//  两个字符交换
```

定义和调用

```cpp
int main() {
    int a = 10;
    int b = 20;
    numSwap(a, b); // 调用整数交换版本
    
    float f1 = 10.2;
    float f2 = 3.14;
    numSwap(f1, f2); // 调用浮点数交换版本
    
    char c1 = 'a';
    char c2 = 'A';
    numSwap(c1, c2); // 调用字符交换版本
}

void numSwap(int &a, int &b) {
    cout << "调用：_numSwap_int_int" << endl;
    int tmp = a;
    a = b;
    b = tmp;
}
void numSwap(float &a, float &b){
    cout << "调用：_numSwap_floar_float" << endl;
    float tmp = a;
    a = b;
    b = tmp;
}

void numSwap(char &a, char &b){
    cout << "调用：_numSwap_char_char" << endl;
    char tmp = a;
    a = b;
    b = tmp;
}
```

终端输出：

```
调用：_numSwap_int_int
调用：_numSwap_floar_float
调用：_numSwap_char_char
```

- 可以定义多个同名函数如，`numSwap`。
- 但是参数列表必须不同（顺序、个数或类型）。
- 会根据实参自动调用最合适的重载版本。
- 重载与返回值无关，如下：

```cpp
int addSomething(int a, int b);
int addSomething(int a, int b, int c);
float addSomething(float a, float b);
float addSomething(float a, int b, int c);

double addSomething(float a, float b); // error
```

以上声明，前4个构成重载，但是第5个与第3个只是在返回值上不同，所以不构成重载，编译会报`Functions that differ only in their return type cannot be overloaded` 错。

## 二、运算符重载

```cpp
int a=10; 
int b=20; 
int c = a+b;
```

上述代码是最基础的 `+`法运算，对于基础类型的变量进行运算，这算是常识。但如何对自定义类的对象进行运算呢？

**例：** 求两个箱子对象体积之和。

```cpp
// 箱子类
class Box
{
   public:
 		// 体积
      double getVolume(void) 
      {
         return length * breadth * height;
      }
      void setLength( double len )
      {
          length = len;
      }
      void setBreadth( double bre )
      {
          breadth = bre;
      }
 	   // 高度
      void setHeight( double hei )
      {
          height = hei;
      }
   private:
      double length;      // 长度
      double breadth;     // 宽度
      double height;      // 高度
};
```
在main 中调用：

```cpp
int main( )
{
    Box Box1(3.0, 5.0, 6.0);                // 声明 Box1，类型为 Box
    Box Box2(11.0, 9.0, 10.0);                // 声明 Box2，类型为 Box
    Box Box3;                // 声明 Box3，类型为 Box
    double volume = 0.0;     // 把体积存储在该变量中
    
    // Box1 的体积
    volume = Box1.getVolume();
    cout << "Volume of Box1 : " << volume <<endl;
    
    // Box2 的体积
    volume = Box2.getVolume();
    cout << "Volume of Box2 : " << volume <<endl;
    
    // 把两个对象相加，得到 Box3
    Box3 = Box1 + Box2; // ①
    
    // Box3 的体积
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume <<endl;
    
    return 0;
}
```

代码①处，为两个Box类的对象进行`+`法运算，如果Box类没有对`+`运算符进行重载，则会报错：`Invalid operands to binary expression ('Box' and 'Box')`。

- 重载运算符：

> 重载的运算符是带有特殊名称的函数，函数名是由关键字 `operator` 和其后要重载的`运算符符号`构成的。

**例：** Box类`+`运算符重载

```
// 类的成员函数定义方式。
Box operator+(const Box&);

//普通非成员函数定义方式。
Box operator+(const Box&, const Box&);
```

成员方法定义：

```cpp
// 重载 + 运算符，用于把两个 Box 对象相加
Box operator+(const Box& b) // ②
{
	Box box;
	// ③
	box.length = this->length + b.length;
	box.breadth = this->breadth + b.breadth;
	box.height = this->height + b.height;
	return box; // ④
}
```
调用：

```cpp
// 把两个对象相加，得到 Box3
Box3 = Box1 + Box2; // ①
    
// Box3 的体积
volume = Box3.getVolume();
cout << "Volume of Box3 : " << volume <<endl;
```

- ①处代码，调用类的 `+`运算符重载方法。
- ②处`this`为`+`左侧参数，即Box1；`b`为`+`右侧参数，即Box2。
- ③处，是运算符的实际意义，这里是对各边长相加，组成一个新的对象。
- ④处，为返回的新对象，即`=`号左边的接受对象。

终端输出：

```
Volume of Box1 : 90
Volume of Box2 : 990
Volume of Box3 : 3136
```

## 三、(不）可重载运算符

### 1.可重载运算符

|运算符分类|运算符|
|--|--|
| 双目算术运算符 | + (加)，-(减)，*(乘)，/(除)，% (取模) |
|关系运算符|	==(等于)，!= (不等于)，< (小于)，> (大于>，<=(小于等于)，>=(大于等于)|
|逻辑运算符|	\|\|(逻辑或)，&&(逻辑与)，!(逻辑非)|
|单目运算符|	+ (正)，-(负)，*(指针)，&(取地址)|
|自增自减运算符|	++(自增)，--(自减)|
|位运算符|	\| (按位或)，& (按位与)，~(按位取反)，^(按位异或),，<< (左移)，>>(右移)|
|赋值运算符|	=, +=, -=, *=, /= , % = , &=, |=, ^=, <<=, >>=|
|空间申请与释放|	new, delete, new[ ] , delete[]|
|其他运算符|	()(函数调用)，->(成员访问)，,(逗号)，[](下标)

### 2.不可重载运算符

`.`：成员访问运算符

`.`, `->`：成员指针访问运算符

`::`：域运算符

`sizeof`：长度运算符

`?:`：条件运算符

`#`： 预处理符号

## 总结：

- 函数重载为同一作用域中`名称相同`、`参数列表`不相同的一组函数。
- 函数重载与返回值无关，即，只有返回值不同，不构成重载。
- 运算符重载是让自定义类的对象，也具备一系列运算操作。

本章函数重载[代码示例](./code_07_01.cpp)
本章运算符重载[代码示例](./code_07_02.cpp)

