#include <iostream>

using namespace std;
class Person
{
public:
    Person();//默认构造函数
    Person(int age, float height, float weight);//带参构造函数
    Person(const Person &p);//拷贝构造函数
    ~Person();//析构函数，只存在这个唯一版本
    void showPerson();
    
    int age;
    float height;
    float weight;
};

Person::Person()
{
    cout << "Person默认构造函数" << endl;
    age = 1;
    height = 1.50;
    weight = 5.0;
}

Person::Person(int a, float h, float w) :
age(a),//基础类型变量直接赋值
height(h),
weight(w)
{
    cout << "Person带参构造函数" << endl;
}

Person::Person(const Person & p)//拷贝构造函数实现
{
    // 用p对象的属性，初始化本对象（this)的属性。
    age = p.age;
    height = p.height;
    weight = p.weight;
    cout << "Person拷贝构造函数" << endl;
}

Person::~Person()//析构函数实现
{
    cout << "Person析构函数" << endl;
}

void Person::showPerson()
{
    cout << "age:" << age << " height:" << height << " weight:" << weight << endl;
}

// 对参数p进行修改后，返回
Person growUp(Person p /*①*/)
{
    p.age += 20;
    p.height += 1;
    p.weight += 20; //  人到中年什么都不易，除了易胖
    
    return p; // ②
}

int main()
{
    //    Person p(18, 75, 180);
    //    Person per = p;//用存在的对象创建新对象，调用拷贝构造函数。
    //    //Person per(p);//调用拷贝构造函数
    //    per.showPerson();
    
    Person young(18, 70, 170);
    Person old = growUp(young);
    old.showPerson();
    
    return 0;
}


