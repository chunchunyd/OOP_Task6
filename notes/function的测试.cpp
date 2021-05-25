/*
*/
#include <functional>
#include <iostream>
#include <stdlib.h>
using namespace std;

int func1(const int &x, int &b)
{
    return 0;
};
// function<int(int, int)> pf1 = func1;
function<int(int, int &)> pf2 = func1;
function<int(int &, int &)> pf3 = func1;
function<int(const int &, int &)> pf4 = func1;
function<int(const int, int &)> pf5 = func1;
// function<int&(int, int&)> pf6 = func1;

class Func2
{
public:
    int &operator()(int &&b) const
    {
    }
};
Func2 func2;
function<int &(int &&)> pfa = func2;
function<int(int &&)> pfb = func2;
// function<int&(int&)> pfc = func2;
// function<int(int&)> pfd = func2;
function<int &(int)> pfe = func2;
function<int(int)> pff = func2;

//参数：可接受的就行（const int &: 传入实参可以是int, const int, int&, const int&
//                  int &&: 传入实参是int&&(std::move()，或 1，2，3，4 这样的具体数字)，int 是特例，实现方式是拷贝了一份参数，然后将该参数的右值传给Func2())
//返回值：实际的返回值是int, 模板只能用 int （可以想,int& x = 函数的返回值(一个临时的int变量)，引用到了临时变量）
//        实际的返回值是int&，模板可以 int& 也可以 int  （int x = 函数的返回值（一个引用），拷贝过来）

void funcA(int && x){}

int main()
{
    funcA(1);
    int m_a = 10;
    // funcA(m_a);             
    system("pause");
    return 0;
}