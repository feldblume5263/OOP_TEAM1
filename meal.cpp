#pragma once
#include "meal.h"



Meal::Meal()
    : num_of_people(1)
{}

void Meal::setNumofpeople(const int& people_in)
{
    num_of_people = people_in;
}

int Meal::getNumofpeople()
{
    return num_of_people;
}

// add vector ingredientes
void Meal::addMenu(Recipe _menu)
{
    menus.push_back(_menu);
}

// delete menus and ingredients form selected menus
void Meal::deleteMenu(int order)
{
    auto itr = menus.begin() + order - 1;
    //delete *itr;
    menus.erase(itr);
}

// show name of menus and ingredients scaled by num_of_people
void Meal::showMeal()
{
    for (auto each_menu : menus)
    {
        cout << " >> Recipe Name :" << each_menu.getMenu() << endl;

        cout << " >> Ingredients :" << endl;
        for (auto each_ingredient : each_menu.getIngredients())
        {
            cout << "  - " << each_ingredient << "  \tX" << num_of_people << endl;
        }

        cout << "---------------------\n" << endl;

    }
}



//return one meal(menus, ingredients) for plan class...
vector<Recipe>& Meal::get_menus()
{
    return menus;
}
