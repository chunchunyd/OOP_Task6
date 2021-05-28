//from沒有用模板函數實現
#pragma once


#include <list>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;


template<typename T>
class MyQueriable{
public:
    T m_data[1000000];
    // int idx_begin;
    // int idx_end;
    int m_num;
//构造析构
    MyQueriable():m_num(0){};
//成员函数
    void push(const T & input){
        m_data[m_num++]=input;
    }
    int size(){
        return m_num; 
    }
    T& operator[](int id){
        return m_data[id];
    }
    T sum(){
        int m_sum = 0;
        for(int i=0;i<m_num;i++){
            m_sum+=m_data[i];
        }
        return m_sum;
    }
    MyQueriable<T> where(function<bool(T)> func){
        MyQueriable<T> res;
        for(int i=0;i<m_num;i++){
            if(func(m_data[i])){
                res.push(m_data[i]);
            }
        }
        return res;
    }
    MyQueriable<T> apply(function<T(T)> func){
        MyQueriable<T> res;
        for(int i =0;i<m_num;i++){
            res.push(func(m_data[i]));
        }
        return res;
    }

};


// template<typename T>
MyQueriable<int> from(list<int> data){
    MyQueriable<int> res;
    for(auto &num:data){
        res.push(num);
    }
    return res;
}
MyQueriable<int> from(vector<int> data){
    MyQueriable<int> res;
    for(auto &num:data){
        res.push(num);
    }
    return res;
}MyQueriable<float> from(list<float> data){
    MyQueriable<float> res;
    for(auto &num:data){
        res.push(num);
    }
    return res;
}MyQueriable<float> from(vector<float> data){
    MyQueriable<float> res;
    for(auto &num:data){
        res.push(num);
    }
    return res;
}
//PCH警告:头停止点不在文件范围内。(一用模板函数就会出现)