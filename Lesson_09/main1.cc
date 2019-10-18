#include <iostream>
using namespace std;

// 基类  形状类
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

// 派生类   矩形类继承了形状类的width和height
class Rectangle: public Shape
{
public:
    int getArea()
    {
        return (width * height);
    }
};

int main1(void)
{
    Rectangle Rect;
    
    Rect.setWidth(10);
    Rect.setHeight(13);
    
    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;
    
    // 类占用内存大小 ④
    //    cout << "size Shape:" << sizeof(Shape) << endl;
    //    cout << "size Rectangle:" << sizeof(Rectangle) << endl;
    
    
    return 0;
}





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
