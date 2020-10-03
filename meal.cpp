#pragma once
#include "meal.h"



Meal::Meal()
{
    ;
}

Meal::~Meal()
{
    ;
}

int Meal::getNumofpeople(int order)
{
    return num_of_people[order];
}

// add vector Menu and num_of_people
void Meal::addMenu(Recipe _menu, const int& people_in)
{
    menus.push_back(_menu);
    num_of_people.push_back(people_in);
}

// delete menus and ingredients form selected menus
void Meal::deleteMenu(int order)
{
    auto itr1 = menus.begin() + order;
    auto itr2 = num_of_people.begin() + order;
    menus.erase(itr1);
    num_of_people.erase(itr2);
}


// show name of menus and ingredients scaled by num_of_people
void Meal::showMeal()
{
    int i = 0;

    for (auto each_menu : menus)
    {
        cout << " >> Recipe Name :" << each_menu.getMenu() << endl;

        cout << " >> Ingredients :" << endl;
        for (auto each_ingredient : each_menu.getIngredients())
        {
            cout << "  - " << each_ingredient << "  \tX" << num_of_people[i] << endl;
        }

        i += 1;

        cout << "---------------------\n" << endl;

    }
}

vector<Recipe> Meal::get_menus()
{
    return menus;
}

vector<int> Meal::get_num_of_people()
{
    return num_of_people;
}


//return one meal(menus, ingredients) for plan class...
// TODO : contain num_of_people
//auto Meal::get_menus()
//{
//    return tuple<std::vector<Recipe>, std::vector<int>>(menus, num_of_people);
//}
