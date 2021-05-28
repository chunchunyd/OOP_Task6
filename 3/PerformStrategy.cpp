#include "PerformStrategy.h"
#include<iostream>

//基类
PerformStrategy::PerformStrategy(double perform) : p_perform(perform)
{
    // std::cout<<"构造函数：p_perform="<<p_perform<<std::endl;
}

int PerformStrategy::get_bonus_salary()
{
    return bonus_salary;
}

//sPerformStrategy
void sPerformStrategy::calc_bonus_salary(int bs){
    bonus_salary = 1000;
}

//mPerformStrategy
void mPerformStrategy::calc_bonus_salary(int bs){
    bonus_salary = p_perform * bs;
    
    // std::cout<<"p_perform:"<<p_perform<<std::endl;
    // std::cout<<"bs:"<<bs<<std::endl;
    // std::cout<<"bonus:"<<bonus_salary<<std::endl;
}

//lPerformStrategy
void lPerformStrategy::calc_bonus_salary(int bs){
    bonus_salary = 2 * p_perform * bs;

    // std::cout<<"p_perform:"<<p_perform<<std::endl;
    // std::cout<<"bs:"<<bs<<std::endl;
    // std::cout<<"bonus:"<<bonus_salary<<std::endl;
}
