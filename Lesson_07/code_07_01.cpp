#include <iostream>

using namespace std;


void numSwap(int &a, int &b);   //  两个整数交换
void numSwap(float &a, float &b);//  两个浮点数交换
void numSwap(char &a, char &b);//  两个字符交换

int addSomething(int a, int b);
int addSomething(int a, int b, int c);
float addSomething(float a, float b);
float addSomething(float a, int b, int c);

//double addSomething(float a, float b);

int main() {
    int a = 10;
    int b = 20;
    numSwap(a, b);
    
    float f1 = 10.2;
    float f2 = 3.14;
    numSwap(f1, f2);
    
    char c1 = 'a';
    char c2 = 'A';
    numSwap(c1, c2);
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



