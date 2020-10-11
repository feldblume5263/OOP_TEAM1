#include "../includes/meal.h"

Meal::Meal()
{
    //std::vector <Serving> meals;
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
            ;
        }

        i += 1;

        cout << "---------------------\n" << endl;
    }
}

std::vector<Serving> Meal::getServings() {
    return servings;
}
