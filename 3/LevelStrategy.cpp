#include "LevelStrategy.h"

int LevelStrategy::get_base_salary(){
    return base_salary;
}

void P1LStrategy::calc_base_salary(){
    base_salary = 2000;
}

void P2LStrategy::calc_base_salary(){
    base_salary = 5000;
}

void P3LStrategy::calc_base_salary(){
    base_salary = 10000;
}