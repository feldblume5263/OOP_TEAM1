#pragma once
#ifndef MEAL_H
#define MEAL_H
#include "iikh.hpp"
#include "meal.h"
#include "recipe.h"

class Meal
{
protected:
    std::vector <Serving> meals;

public:
    Meal();

    ~Meal();

    // add menus
    void addMenu(Recipe _menu, const int& people_in = 1);

    // delete menus and ingredients form selected menus
    void deleteMenu(int order);

    // show name of menus and ingredients scaled by num_of_people
    void showMeal();

    vector <Serving> get_meals();
};


#endif
