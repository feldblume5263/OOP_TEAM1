#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "../includes/recipe.h"
#include "../includes/iikh.hpp"
using namespace std;

//재료 추가
void Recipe::addIngredient(Ingredient ingredient)
{
    int size = ingredients.size();
    for (int i=0;i<size;i++) {
        if(ingredients[i].getName()==ingredient.getName()) {
            ingredients[i].setWeight(ingredients[i].getWeight() + ingredient.getWeight());
            return;
        }
    }
	ingredients.push_back(ingredient);
}

//재료 삭제
bool Recipe::removeIngredient(string ingredient)
{
	int size = ingredients.size();
	for (int i = 0; i < size; i++) {
		if (ingredients[i].getName() == ingredient) {
			ingredients.erase(ingredients.begin() + i);
			return true;
		}
	}
	return false;
}
void Recipe::addOrder(string order)
{
    ingredient_order.push_back(order);
}
//출력
void Recipe::printRecipe()
{
    cout << "------------------"<< endl;
    cout << "| Selected Recipe |" << endl;
    cout << "-------------------"<< endl;
    cout << endl;

    cout << " Name: " << getName() << endl;
    cout << " Cooking Time: " << getDuration() << endl;
    if (getDescription().size())
    {
        cout << endl;
        cout << "Description: " << getDescription();
    }

    if (getIngredients().size())
    {
        cout << endl;
        cout << " <Ingredients List>" << endl;
        for (int i = 0; i < getIngredients().size(); i++)
        {
            cout << " " << i + 1 << ". " << getIngredients()[i].getName() << endl;
        }
    }

    if (getOrder().size())
    {
        cout << endl;
        cout << " Cooking Order ";
        for (int i = 0; i < getIngredients().size(); i++)
        {
            cout << " " << i + 1 << ". " << getOrder()[i] << endl;
        }

    }

    cout << endl << endl;
}


