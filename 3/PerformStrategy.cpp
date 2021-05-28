#include "PerformStrategy.h"
#include<iostream>

//基类
PerformStrategy::PerformStrategy(int perform) : p_perform(perform)
{
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
}

//lPerformStrategy
void lPerformStrategy::calc_bonus_salary(int bs){
    bonus_salary = 2 * p_perform * bs;
    std::cout<<"bonus:"<<bonus_salary<<std::endl;
}
