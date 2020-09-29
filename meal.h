#pragma once
#ifndef MEAL_H
#define MEAL_H
#include"recipe.h"


class Meal
{
protected:
    int num_of_people;
    std::vector <Recipe> menus;
public:
    Meal();

    void setNumofpeople(const int& people_in);

    int getNumofpeople();

    void addMenu(Recipe _menu);

    void deleteMenu(int order);

    void showMeal();

    vector<Recipe>& get_menus();
};


#endif