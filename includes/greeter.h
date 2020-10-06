#pragma once
#include "iikh.hpp"	

class Greeter {
private:
	RecipeDatabase recipedatabese;
public:
	
};



void addRecipe();
void deleteRecipe();
void editRecipe();
void searchRecipe();





void addRecipe() {
	Recipe recipe;
	
	std::cout << "-------Recipe Infromation-------" << std::endl;
	// std::flush; std::cin.clear(); std::cin.ignore();
	
	// set name
	std::cout << "Name    :" << endl; //TODO : /t/t 등 구현하기.
	std::string recipe_name;
	std::getline(std::cin, recipe_name);
	recipe.setName(recipe_name);
	
	// set duration
	std::cout << "Cooking Duration(min)    :" << std::endl; //TODO : Name이랑 줄간격
	// std::flush; std::cin.clear();
	int duration;
	std::cin >> duration;
	recipe.setDuration(duration);

	// set ingredients
	std::cout << "---Ingredients---\n( If you want to stop adding  ingredients, enter \"stop\" )\n" << std::endl;
	// std::flush
	std::vector<Ingredient> ingredients;
	// std::cin.ignore();
	while (true) {
		// set ingredient name
		std::cout << "Ingredient name     : " << endl;
		string name;
		std::getline(std::cin, name);
		if (name == "stop") { break; }
		
		// set ingredient weight
		int weight;
		std::cout << "Ingredient weight(gram) : " << endl;
		std::cin >> weight;

		Ingredient _ingredient(name, weight);
		ingredients.push_back(_ingredient);
	}
	recipe.setIngredients(ingredients);

	// set order
	std::cout << "---Cookin Oreder---\n( If you want to stop adding  ingredients, enter \"stop\" )\n" << std::endl;
	vector<string> ingredient_order;
	while (true) {
		int i = 1;
		std::cout << "Order" << i << " : ";
		string order;
		std::getline(std::cin, order);
		if (order == "stop") { break; }
		else { recipe.addOrder(order); }
		i += 1;
	}
	

	// use try catch sentence??
	// TODO : modify error.
	// recipedatabese.insertRecipe(recipe);
}

void deleteRecipe() {



}

void editRecipe() {


}


void searchRecipe() {



}

// TODO : add, delete, edit, show recipe