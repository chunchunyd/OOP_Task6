#pragma once
#include <string>

class LevelStrategy
{
protected:
    int base_salary;
public:
    int get_base_salary();
    virtual void calc_base_salary() = 0;
};

class P1LStrategy : public LevelStrategy
{
public:
    void calc_base_salary() override;
};

class P2LStrategy : public LevelStrategy
{
public:
    void calc_base_salary() override;
};

class P3LStrategy : public LevelStrategy
{
public:
    void calc_base_salary() override;
};