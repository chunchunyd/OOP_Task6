/*
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

//A 函数对象不能定义析构函数

class Person{
public:
    int *m_age;

    Person(int age):m_age(new int(age)){};
    class XIGOU{
    public:
        void operator()(){
            cout<<"析构函数调用"<<endl;
        }    
    };
    // XIGOU ~Person;
    XIGOU func;
    ~Person(){
        func();                     //是说这样吗？？？？
    }
};


int main(){
    Person p(19);
    p.func();
    system("pause");
    return 0;
}