#include <iostream>

using namespace std;


#include <iostream>
using namespace std;

class Box
{
public:
    Box(){}
    Box(double l, double b, double h):
    length(l),breadth(b),height(h) {
    }
    
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
    
    void setHeight( double hei )
    {
        height = hei;
    }
    // 重载 + 运算符，用于把两个 Box 对象相加
    Box operator+(const Box& b)
    {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }
private:
    double length;      // 长度
    double breadth;     // 宽度
    double height;      // 高度
};
// 程序的主函数
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
    Box3 = Box1 + Box2;
    
    // Box3 的体积
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume <<endl;
    
    return 0;
}
