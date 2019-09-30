#include <iostream> // 引入标准输入输出头文件

using namespace std; // 使用std命名空间

typedef struct _student{
    char name[32];
    int age;
    float height;
    float weight;
    // 其他信息，比如职业、住址、家庭成员等等
}Student;

void funExample1() {
    int a = 10;
    // int &a1; // error:Declaration of reference variable 'a1' requires an initializer
    int &a1 = a; // 引用，a1为a的别名
    
    cout << "a:" << a << endl;
    cout << "a1:" << a1 << endl;
    
    a = 20;
    
    cout << "a:" << a << endl;
    cout << "a1:" << a1 << endl;
    
    
    cout << &a << ", " << &a1 << endl;
}

void funShowStudent1(Student s) {
    
    cout << "show1_stu的内存地址：" << &s << endl;
    
    cout << "姓名：" << s.name << endl;
    cout << "年龄：" << s.age << endl;
    cout << "身高：" << s.height << endl;
    cout << "体重：" << s.weight << endl;
    // 打印其他信息。
}

void funShowStudent2(Student &s) {
    
    cout << "show2_stu的内存地址：" << &s << endl;
    
    cout << "姓名：" << s.name << endl;
    cout << "年龄：" << s.age << endl;
    cout << "身高：" << s.height << endl;
    cout << "体重：" << s.weight << endl;
    // 打印其他信息。
}

void funShowStudent(const Student &s) {
    cout << "姓名：" << s.name << endl;
    cout << "年龄：" << s.age << endl;
    cout << "身高：" << s.height << endl;
    cout << "体重：" << s.weight << endl;
    // 打印其他信息。
    
    //s.height = 180.0; // Cannot assign to variable 's' with const-qualified type 'const Student &' (aka 'const _student &')
}

void swap(int &a, int &b) {
    // 形参为引用变量，相当于  int &a = a; (=号左边为形参a，=号右边为实参a)
    int tmp = a;
    a = b;
    b = tmp;
}


int& funExample2() {
    int a = 10;
    a += 10;
    return a; // warning：Reference to stack memory associated with local variable 'a' returned
}

int& funExample3() {
    static int a = 10; // 静态变量
    a += 10;
    return a;
}

int main() {
    
    //    funExample1();
    
    int a = 10;
    int b = 20;
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    
    swap(a, b); // 调用交换函数
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    
    
    Student stu;
    strcpy(stu.name, "binson");
    stu.age = 24;
    stu.height = 172.5;
    stu.weight = 68.8;
    
    cout << "main_stu的内存地址：" << &stu << endl;
    
    funShowStudent1(stu);
    funShowStudent2(stu);
    
    int &res = funExample3();
    cout << res << endl;
    
    // 指针类型的引用
    int *p = &a;
    int* &pp = p;
    cout << *pp << endl;
    
}
