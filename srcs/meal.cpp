#include "../includes/meal.h"

Meal::Meal()
{
    servings = vector<Serving>();
}

Meal::~Meal()
{
    ;
}

void Meal::addMenu(Recipe &_menu, const int& people_in)
{
    Serving _serving;
    _serving.menus = _menu;
    _serving.num_of_people = people_in;

    servings.push_back(_serving);
}

void Meal::deleteMenu(int order)
{
    auto itr = servings.begin() + order;
    servings.erase(itr);
}

void Meal::showMeal()
{
    int i = 1;

    for (auto each_menu : servings)
    {
        cout << "---------------------" << endl;
        cout << "| Serving " << i << " " << each_menu.menus.getName() << " |" << endl;

        cout << " >> Ingredients" << endl;
        for (auto each_ingredient : each_menu.menus.getIngredients())
        {
            cout << "|" << each_ingredient.getName() << ", " << each_ingredient.getWeight() << "|" << "g" << endl;
        }

        i += 1;

        cout << "---------------------\n" << endl;
    }
    
}

void Meal::showTotalIngredients() {
    vector<string> ingredients;
    unordered_map<string, int> required_ingredients;

    for (auto each_menu : servings)
    {
        for (auto each_ingredient : each_menu.menus.getIngredients())
        {
            string ingredient_name = each_ingredient.getName();
            int ingredient_weight = stoi(each_ingredient.getWeight()) * each_menu.num_of_people;
            if(!required_ingredients.count(ingredient_name)) {
                ingredients.push_back(ingredient_name);
                required_ingredients[ingredient_name] = ingredient_weight;
            }
            else {
                required_ingredients[ingredient_name] += ingredient_weight;
            }
        }
    }

    cout << "---------------------" << endl;
    cout << "| Required Ingredients |" << endl;

    for(string ingredient_name: ingredients) {
        cout << "| " <<  ingredient_name << ", " << required_ingredients[ingredient_name] << " |" << endl;
    }

    cout << "---------------------\n" << endl;
}

std::vector<Serving> Meal::getServings() {
    return servings;
}
