#pragma once
#include "../includes/meal.h"
//#include <vector>

Meal::Meal()
{
    ;
}

Meal::~Meal()
{
    ;
}

void Meal::addMenu(Recipe _menu, const int& people_in)
{
    Serving _serving;
    _serving.menus = _menu;
    _serving.num_of_people = people_in;
    meals.push_back(_serving);
}

void Meal::deleteMenu(int order)
{
    auto itr = meals.begin() + order;
    meals.erase(itr);
}

void Meal::showMeal()
{
    int i = 1;

    for (auto each_menu : meals)
    {
        cout << "---------------------" << endl;
        cout << "| Serving " << i << " " << each_menu.menus.getName() << " |" << endl;

        cout << " >> Ingredients" << endl;
        for (auto each_ingredient : each_menu.menus.getIngredients())
        {
            /*cout << "  - " << each_ingredient << "  \tX" << each_menu.num_of_people << endl;*/
            // TODO :  get_weight * num_of_people (( After checking recipe class ))
        }

        i += 1;

        cout << "---------------------\n" << endl;
    }
}

std::vector<Serving> Meal::get_meals() {

    return meals;
}
