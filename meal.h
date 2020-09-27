#pragma once
#ifndef MEAL_H
#define MEAL_H
//#include"recipe.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


/*
Meal Class
Vector<Recipe> menus
Int people
add_menu(Recipe)
delete_menu(Recipe)
Vector Recipe get_menus()
Int get_people()
Int set_people()
*/

/*
The Meal Component
holds information about a single meal
Allows user to interact with the recipe database tp select individual recipes for meals
User sets number of people to be present at meal, recipes are automatically scaled
Can produce grocery lists for entire meal, by combining grocery lists from individual scaled recipes
*/


// Make temporaly recipe class 
// for check the meal class. 
class Recipe
{
protected:
    string menu;
    vector <string> ingredients;
    
public:
    Recipe()
        : menu("salmon")  // , ingredients("lemon", "weed")
    {}

    void setMenu(string _menu)
    {
        menu = _menu;
    }

    string getMenu()
    {
        return menu;
    }

    void setIngredients(string ingredient)
    {
        ingredients.push_back(ingredient);
    }

    vector <string> getIngredients()
    {
        return ingredients;
    }
};






class Meal
{
protected:
    int num_of_people;
    std::vector <Recipe> menus;

public:
    Meal()
        : num_of_people(1)
    {}

    void setNumofpeople(const int& people_in)
    {
        num_of_people = people_in;
    }

    int getNumofpeople()
    {
        return num_of_people;
    }

    // add vector ingredientes
    void addMenu(Recipe _menu)
    {
        menus.push_back(_menu); 
    }

    // delete menus and ingredients form selected menus
    void deleteMenu(int order)  // parameter was (Recipe _menu)
        // I can do that Take (Recipe _menu) as parameter, and use for ( ~~ ) if ( menus[i].getMenu == _menu.getMenu ) { erase...;}
        // But I think it`s ineffieient. 
    {
        //menus.pop_back(); // automatically pull one by one.
        //menus.erase(order); // error! no instance of overloaded function "std:;vector< ...... " matches the argument list

        auto itr = menus.begin() + order -1;  
        //delete *itr;
        menus.erase(itr);
    }

    // show name of menus and ingredients scaled by num_of_people
    void showMeal()
    {
        for (auto each_menu : menus)
        {
            cout << " >> Recipe Name :" << each_menu.getMenu() << endl; 
            
            cout << " >> Ingredients :" << endl;
            for (auto each_ingredient : each_menu.getIngredients())
            {
                cout << "  - "  << each_ingredient << "  \tX" << num_of_people << endl;
            }

            cout << "---------------------\n" << endl;

        }
    }



    // ROLE : return one meal(menus, ingredients) for plan class... um.. I think it`s useless
    vector<Recipe>& get_menus()
    {
        return menus;
    }


};


#endif