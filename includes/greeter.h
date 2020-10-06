#pragma once
#include "iikh.hpp"	

class Greeter {
private:
	RecipeDatabase recipedatabese; // 이 놈 위치
public:
	
};



void addRecipe(); // add new recipe
void deleteRecipe(); // delete recipe
void editRecipe(); // edit recipe
void searchRecipe(); // search recipe by ingredients or recipename
void showRecipe(); // show all recipe














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
	int duration;
	std::cin >> duration;
	recipe.setDuration(duration);

	// set ingredients
	std::cout << "---Ingredients---\n( If you want to stop adding  ingredients, enter \"stop\" )\n" << std::endl;
	std::vector<Ingredient> ingredients;
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
	recipedatabese.RecipeDatabase::insertRecipe(recipe);
}

void deleteRecipe() {
	std::cout << "Enter the recipe name you want to delete : " << std::flush;
	string del_recipe;
	std::getline(std::cin, del_recipe);

	// serarch
	// TODO : 일치 하지 않았다는 걸 어떻게 알려주지..
	if (1) {
		std::cout << "There is no search result for \"" << del_recipe << "\" in recipe list" << endl;
	}
	else {
		RecipeDatabase::deleteRecipe(del_recipe);
		std::cout << "Delete completely" << endl;
	}
}



void editRecipe() {
	cout << "Enter the recipe name you wnat to edit  : ";
	string search_recipe;
	std::getline(cin, search_recipe);
	
	Recipe search_result = RecipeDatabase::getRecipes_recipename(search_recipename);
	search_result.printRecipe();

	std::cout << "Which part wnat to edit?\n[1] : name\n[2] : duration\n[3] : ingredients\n[4] : order" << endl;
	cout << "Select : " << endl;
	int select;
	cin >> select;

	switch (select){
	case 1:	{
		// set name
		std::cout << "You select to edit Recipe nama" << endl;
		std::cout << "Name    :" << endl;
		string recipe_name;
		std::getline(std::cin, recipe_name);
		search_result.setName(recipe_name);
		break;
	}
	case 2: {
		// set duration
		std::cout << "Cooking Duration(min)    :" << std::endl;
		int duration;
		std::cin >> duration;
		search_result.setDuration(duration);
		break;
	}
	case 3: {
		// set ingredients
		std::cout << "---Ingredients---\n( If you want to stop adding  ingredients, enter \"stop\" )\n" << std::endl;
		std::vector<Ingredient> ingredients;
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
		search_result.setIngredients(ingredients);
		break;
	}
	case 4: {
		std::cout << "---Cookin Oreder---\n( If you want to stop adding  ingredients, enter \"stop\" )\n" << std::endl;
		vector<string> ingredient_order;
		while (true) {
			int i = 1;
			std::cout << "Order" << i << " : ";
			string order;
			std::getline(std::cin, order);
			if (order == "stop") { break; }
			else { search_result.addOrder(order); }
			i += 1;
			break;
		}
	}

	default : 
		cout << "select between 1~4" << endl;
	}

	RecipeDatabase::deleteRecipe(del_recipe);
	recipedatabese.RecipeDatabase::insertRecipe(search_recipe);
}


void searchRecipe() {
	std::cout << "Which do you search for, recipes or ingredients?\n[1] : recipe\n [2] : ingredient" << endl;
	int select; 
	cin >> select;
	if (select == 1) { // search for recipe name
		std::cout << "Enter the recipe name" << endl;
		std::cout << "Search : " << std::flush;
		string search_recipename;
		std::getline(std::cin, search_recipename);

		if (1) {
			RecipeDatabase::getRecipes_recipename(search_recipename).printRecipe();
		}
		else { 
			std::cout << "There is no search result for \"" << search_recipename << "\" in recipe list" << endl;
		}
	}
	else if (select == 2) { // search for ingredients
		std::cout << "Enter the ingredients" << endl;
		std::cout << " If you want to stop adding  ingredients, enter \"stop\"";
		std::cout << "Search : " << std::flush;
		vector<string> search_ingredients;

		while (1) {
			string ingredient;
			std::getline(cin, ingredient);
			if (ingredient == "stop") { break; }
			else {
				search_ingredients.push_back(ingredient);
			}
		}

		vector<Recipe> search_list;
		if (1) {
			search_list = RecipeDatabase::getRecipes_ingredients(search_ingredients);

			for (Recipe result_recipe : search_list) {
				result_recipe.printRecipe();
			}
		}
		else { 
			std::cout << "There is no search result in recipe list" << endl;
		}
	}
	else {
		// TODO : Do something;
	}
}

void showRecipe() {
	for (Recipe recipe : RecipeDatabase::getRecipes() {
		recipe.printRecipe();
	}
}