#ifndef PLANMANAGER_H
# define PLANMANAGER_H

# include <iostream>
# include <vector>

using namespace std;

class               Plan
{
private:
    int             date;
    string          meal;
    int             meal_type;

};

class               PlanManger
{
private:
    vector<Plan>    plan_array;
    
public:
    PlanManger();
    ~PlanManger();

    void            add_plan();
    void            delete_plan();
    void            revise_plan();
    void            show_all_meal();
    void            find_by_date();
};

#endif