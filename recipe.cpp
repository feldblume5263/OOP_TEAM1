#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "recipe.h"
using namespace std;

//재료 추가
void Recipe::addIngredient(string ingredient)
{
	ingredients.push_back(ingredient);
}

//재료 삭제
bool Recipe::removeIngredient(string ingredient)
{
	int size = ingredients.size();
	for (int i = 0; i < size; i++) {
		if (ingredients[i] == ingredient) {
			ingredients.erase(ingredients.begin() + i);
			return true;
		}
	}
	return false;
}
bool Recipe::searchIngredient(string ingredient)
{
    if(find(ingredients.begin(),ingredients.end(),ingredient) != ingredients.end() ) {
        return true;
    }
    return false;
}
//출력
void Recipe::printRecipe()
{
    cout << "------------------"<< endl;
    cout << "| Selected Recipe |" << endl;
    cout << "-------------------"<< endl;
    cout << endl;

    cout << " <Name> " << getName() << endl;
    if (getIngredients().size())
    {
        cout << endl;
        cout << " <Ingredients List>" << endl;
        for (int i = 0; i < getIngredients().size(); i++)
        {
            cout << " " << i + 1 << ". " << getIngredients()[i] << endl;
        }
    }

    if (getDescription().size())
    {
        cout << endl;
        cout << " <Description> " << getDescription();
    }

    cout << endl << endl;
}


