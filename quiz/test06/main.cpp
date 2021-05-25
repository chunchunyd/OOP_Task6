/*
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    std::vector<char> a1;
    string a2;

    // std::cin >> a1;
    std::cin >> a2;

    // a1.append("abc");
    a2.append("abc");



    std::sort(a1.begin(), a1.end());
    std::sort(a2.begin(), a2.end());

    // a1.length();
    a2.length();

    system("pause");
    return 0;
}