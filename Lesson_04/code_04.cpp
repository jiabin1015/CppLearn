#include <iostream>

using namespace std;
class Person
{
public:
    Person();//默认构造函数
    Person(int age, float height, float weight);//带参构造函数
    Person(int age);//带参构造函数，可以定义多个版本，只要参数列表不同。
    
    ~Person();//析构函数，只存在这个唯一版本
    void showPerson();
    
    int age;
    float height;
    float weight;
    
    char *name;
};
Person::Person()
{
    cout << "Person默认构造函数" << endl;
    age = 1;
    height = 1.50;
    weight = 5.0;
    
    // 分配name指针内存
    name = new char[32];
}
Person::Person(int age)
{
    cout << "Person 带参构造函数 2" << endl;
    if (age < 0 || age > 100) {
        cout << "请确保年龄在合理范围之类" <<endl;
        this->age = 1;
    } else {
        this->age = age;
    }
    
    // 其他属性初始化
    height = 0;
    weight = 0;
    
    // 分配name指针内存
    name = new char[32];
}

Person::Person(int age, float height, float weight)
{
    cout << "Person带参构造函数" << endl;
    this->age = age;
    this->height = height;
    this->weight = weight;
    
    // 分配name指针内存
    name = new char[32];
}
void Person::showPerson()
{
    cout << age << endl << height << endl << weight << endl;
}

Person::~Person()//析构函数实现
{
    cout << "Person析构函数" << endl;
    
    // 释放name的内存空间
    if (name != NULL) {
        delete[] name; // new[] 对应 delete[]
        name = NULL; // 置空，好习惯
    }
}


int main()
{
    Person p;//会自动调用默认的构造函数
    //    Person per(18, 70, 170);//调用自定义带参构造函数
    //    per.showPerson();
    
    
    //    Person pp1(20);
    //    pp1.showPerson();
    //    Person pp2(200);// 传入参数不在合理范围之内
    //    pp2.showPerson();
    
    Person* p3 = new Person(18); // 创建对象
    delete p3; // 释放对象
    
    return 0;
}

