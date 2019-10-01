#include <iostream>

using namespace std;



class Box { // 类名
public: // 成员访问权限
    // 成员
    float length;  // 盒子的长度
    float width;   // 盒子的宽度
    float height;  // 盒子的高度
    
    //    float theVolume() { // 盒子的体积方法
    //        return length * width * height;
    //    }
    
    float theVolume();
};

float Box::theVolume() {
    return length * width * height;
}

int main() {
    
    Box box1;
    Box* box2;
    
    box1.length = 10;
    box1.width = 10;
    box1.height = 20;
    
    cout << "box1的体积为：" << box1.length * box1.width * box1.height << endl;
    cout << "box1的体积为：" << box1.theVolume() << endl;
    
    //先给box2分配内存
    box2 = new Box; // 相当于,box2 = (Box*)malloc(sizeof(Box));
    box2->length = 15;
    box2->width = 21.5;
    box2->height = 18.6;
    
    cout << "box2的体积为：" << box2->length * box2->width * box2->height << endl;
    cout << "box2的体积为：" << box2->theVolume() << endl;
    delete box2; // 相当于，free（box2)
    return 0;
}
