#pragma once
#ifndef MEAL_H
#define MEAL_H
#include"recipe.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>


class Meal
{
protected:
    std::vector <int> num_of_people;
    std::vector <Recipe> menus;

public:
    int getNumofpeople(int order);

    void addMenu(Recipe _menu, const int& people_in = 1);

    void deleteMenu(int order);

    void showMeal();

    vector <Recipe> get_menus();

    vector <int> get_num_of_people();

};


#endif