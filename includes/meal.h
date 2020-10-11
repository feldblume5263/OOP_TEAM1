#pragma once
#ifndef MEAL_H
#define MEAL_H
#include "iikh.hpp"
#include "recipe.h"

class Meal
{
private:
    string name;
    vector <Serving> servings;

public:
    Meal();

    ~Meal();

    string getName() { return this->name; }
    void setName(string name) { this->name = name; }
    // add menus
    void addMenu(Recipe &_menu, const int& people_in = 1);

    // delete menus and ingredients form selected menus
    void deleteMenu(int order);

    // show name of menus and ingredients scaled by num_of_people
    void showMeal();

    vector <Serving> getServings();
};


#endif
