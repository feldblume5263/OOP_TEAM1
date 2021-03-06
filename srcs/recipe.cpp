#include "../includes/recipe.h"


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

void Recipe::deleteOrder()
{
    ingredient_order.clear();
}


void Recipe::printRecipe()
{
    {
        cout << "------------------"<< endl;
        cout << "| Selected Recipe |" << endl;
        cout << "-------------------"<< endl;

        cout << " Name: " << getName() << endl;
        cout << " Cooking Time: " << getDuration() << endl;

        if (getIngredients().size())
        {
            cout << endl;
            cout << " <Ingredients List>" << endl;
            for (int i = 0; i < getIngredients().size(); i++)
            {
                cout << " " << i + 1 << ". " << getIngredients()[i].getName() << "  " 
                    << getIngredients()[i].getWeight() << endl;
            }
        }

        if (getOrder().size())
        {
            cout << endl;
            cout << " Cooking Order " << endl;
            for (int i = 0; i < getOrder().size(); i++)
            {
                cout << " " << i + 1 << ". " << getOrder()[i] << endl;
            }

        }

        cout << endl << endl;
    }
}


