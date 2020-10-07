#include "../OOP_TEAM1/includes/greeter.h"

void Greeter::showTitle() {
	cout << "¦£";
	for (int i = 0; i < 54; i++) 	cout << "¦¡";
	cout << "¦¤" << endl;
	cout << "¦¢000000000000  000000000000  00        00  00        00¦¢" << endl;
	cout << "¦¢     00            00       00      00    00        00¦¢" << endl;
	cout << "¦¢     00            00       00    00      00        00¦¢" << endl;
	cout << "¦¢     00            00       00  00        00        00¦¢" << endl;
	cout << "¦¢     00            00       0000          00        00¦¢" << endl;
	cout << "¦¢     00            00       00            000000000000¦¢" << endl;
	cout << "¦¢     00            00       0000          00        00¦¢" << endl;
	cout << "¦¢     00            00       00  00        00        00¦¢" << endl;
	cout << "¦¢     00            00       00    00      00        00¦¢" << endl;
	cout << "¦¢     00            00       00      00    00        00¦¢" << endl;
	cout << "¦¢000000000000  000000000000  00        00  00        00¦¢" << endl;
	cout << "¦¦";
	for (int i = 0; i < 54; i++) 	cout << "¦¡";
	cout << "¦¥" << endl << endl;
}


void Greeter::showMenu() {

	int input_number;
	while (true) {
		system("cls");
		showTitle();
		cout << "----" << endl;
		cout << "Menu" << endl;
		cout << "----" << endl;
		cout << "[1] Edit Recipe" << endl;
		cout << "[2] Edit Plan" << endl;
		cout << "[0] Exit" << endl;
		int input_number;
		cin >> input_number;

		if (input_number == 0) {
			cout << "Exit Program...." << endl;
			return;
		}
		else if (input_number == 1) {

			while (true) {
				system("cls");
				cout << "-----------" << endl;
				cout << "Edit Recipe" << endl;
				cout << "-----------" << endl;
				cout << "[1] Add Recipe" << endl;
				cout << "[2] Delete Recipe" << endl;
				cout << "[3] Revise Recipe" << endl;
				cout << "[4] Search Recipe" << endl;
				cout << "[5] Show All Recipe" << endl;
				cout << "[0] Back To Menu" << endl;
				int input_num_in_recipe;
				cin >> input_num_in_recipe;
				if (input_num_in_recipe == 0) {

					break;
				}
				else if (input_num_in_recipe == 1) {
					system("cls");
					addRecipe();
					continue;
				}
				else if (input_num_in_recipe == 2) {
					system("cls");
					deleteRecipeDB();
					continue;
				}
				else if (input_num_in_recipe == 3) {
					system("cls");
					editRecipe();
					continue;
				}
				else if (input_num_in_recipe == 4) {
					system("cls");
					searchRecipe();
					continue;
				}
				else if (input_num_in_recipe == 5) {
					system("cls");
					showRecipe();
					continue;
				}
				else {
					cout << "-----------------------------------------------" << endl;
					cout << "Error: Invalid Input. Press Any Key to Go Back." << endl;
					cout << "-----------------------------------------------" << endl;

					if (_getch())continue;

				}





			}
			continue;
		}
		else if (input_number == 2) {
			while (true) {
				system("cls");
				cout << "---------" << endl;
				cout << "Edit Plan" << endl;
				cout << "---------" << endl;
				cout << "[1] Add Plan" << endl;
				cout << "[2] Delete Plan" << endl;
				cout << "[3] Revise Plan" << endl;
				cout << "[4] Search Plan" << endl;
				cout << "[5] Show All Plan" << endl;
				cout << "[0] Back To Menu" << endl;
				int input_num_in_plan;
				cin >> input_num_in_plan;
				if (input_num_in_plan == 0) {

					break;
				}
				else if (input_num_in_plan == 1) {
					system("cls");
					//addPlan();
					continue;
				}
				else if (input_num_in_plan == 2) {
					system("cls");
					//deletePlan();
					continue;
				}
				else if (input_num_in_plan == 3) {
					system("cls");
					//revisePlan();
					continue;
				}
				else if (input_num_in_plan == 4) {
					system("cls");
					//searchPlan();
					continue;
				}
				else if (input_num_in_plan == 5) {
					system("cls");
					//showPlan();
					continue;
				}
				else {
					cout << "-----------------------------------------------" << endl;
					cout << "Error: Invalid Input. Press Any Key to Go Back." << endl;
					cout << "-----------------------------------------------" << endl;
					if (_getch())continue;

				}

			}
			continue;
		}
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "Error: Invalid Input. Press Any Key to Go Back." << endl;
			cout << "-----------------------------------------------" << endl;
			if (_getch())continue;
		}


	}
}
void Greeter::addRecipe() {
	Recipe recipe;

	std::cout << "-------Recipe Infromation-------" << std::endl;
	// std::flush; std::cin.clear(); std::cin.ignore();

	// set name
	std::cout << "Name    :" << endl;
	std::string recipe_name;
	std::getline(std::cin, recipe_name);
	recipe.setName(recipe_name);

	// set duration
	std::cout << "Cooking Duration(min)    :" << std::endl;
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
	recipedatabese.insertRecipe(recipe);
}

// delete recipe
void Greeter::deleteRecipeDB() {
	std::cout << "Enter the recipe name you want to delete : " << std::flush;
	string del_recipe_name;
	std::getline(std::cin, del_recipe_name);

	// serarch
	Recipe del_recipe = recipedatabese.searchRecipes_recipename(del_recipe_name);
	if (del_recipe.getID()) {
		recipedatabese.deleteRecipe(del_recipe);
		std::cout << "Completely Delete" << endl;
	}
	else { std::cout << "There is no search result for \"" << del_recipe_name << "\" in recipe list" << endl; }
}

// edit recipe

inline void Greeter::editRecipe() {
	cout << "Enter the recipe name you wnat to edit  : ";
	string search_recipe;
	std::getline(cin, search_recipe);

	Recipe search_result = recipedatabese.searchRecipes_recipename(search_recipe);
	search_result.printRecipe();

	std::cout << "Which part wnat to edit?\n[1] : name\n[2] : duration\n[3] : ingredients\n[4] : order" << endl;
	cout << "Select : " << endl;
	int select;
	cin >> select;

	switch (select) {
	case 1: {
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
	default:
		cout << "select between 1~4" << endl;
	}

	recipedatabese.updateDatabase(search_result);
}

// search recipe by ingredients or recipename
void Greeter::searchRecipe() {
	std::cout << "Which do you search for, recipes or ingredients?\n[1] : recipe\n [2] : ingredient" << endl;
	int select;
	cin >> select;
	if (select == 1) { // search for recipe name
		std::cout << "Enter the recipe name" << endl;
		std::cout << "Search : " << std::flush;
		string search_recipename;
		std::getline(std::cin, search_recipename);

		Recipe search_recipe;
		search_recipe = recipedatabese.searchRecipes_recipename(search_recipename);
		if (search_recipe.getID()) {
			recipedatabese.searchRecipes_recipename(search_recipename).printRecipe();
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
		search_list = recipedatabese.searchRecipes_ingredients(search_ingredients);
		if (!search_list.empty()) {  // If search_list is not empty, then..
			for (Recipe result_recipe : search_list) {
				result_recipe.printRecipe();
			}
		}
		else {
			std::cout << "There is no search result in recipe list" << endl;
		}
	}
}

// show all recipe
inline void Greeter::showRecipe() {
	vector<Recipe> recipe_list;
	recipe_list = recipedatabese.getRecipes();
	for (Recipe recipe : recipe_list )
	{
		recipe.printRecipe();
	}
}
