#ifndef PLANMANAGER_H
# define PLANMANAGER_H

//# include "plan.h"
# include <iostream>
# include <vector>
# include <algorithm>
# include <cstring>

using namespace std;

class               Plan
{
private:
    int             month = 0;
    int             day = 0;
    string          meal = "";
    int             meal_type = 0;

public:
    Plan(int _month, int _day, string _meal, int _meal_type)
    {
        month = _month;
        day = _day;
        meal = _meal;
        meal_type = _meal_type;
    }
    Plan() {}

    void    make_plan() {}

    bool    find_plan(int _month, int _day, int _meal_type)
    {
        if (month == _month && day == _day && meal_type == _meal_type)
            return (true);
        return (false);
    }

    void    print_plan()
    {
        string      meal_type_string;

        if (meal_type == 1)
            meal_type_string = "Breakfast";
        else if (meal_type == 2)
            meal_type_string = "Lunch";
        else if (meal_type == 3)
            meal_type_string = "Dinner";
        else
            meal_type_string = "unknown";
        cout << month << "/" << day << "/" << meal_type_string << endl;
        cout << meal << endl;
        cout << endl;
    }
};

class               PlanManger
{
private:
    vector<Plan>    plan_array;

public:
    PlanManger();
    ~PlanManger();

    void            add_plan(Plan planToAdd);
    void            delete_plan(int _month, int _day, int _meal_type);
    void            revise_plan(int _month, int _day, int _meal_type);
    void            show_all_meal();
    bool            find_plan(Plan planToFind, int _month, int _day, int _meal_type);
};

#endif
