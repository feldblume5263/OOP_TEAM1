#include "../includes/greeter.h"

Greeter::Greeter() {
	recipedatabase = make_unique<RecipeDatabase>();
	planmanager = PlanManager();
	string temp_string;
	int temp_num;
	add_count = 0;

}
void Greeter::showTitle() {



	cout << "000000000000  000000000000  00        00  00        00" << endl;
	cout << "     00            00       00      00    00        00" << endl;
	cout << "     00            00       00    00      00        00" << endl;
	cout << "     00            00       00  00        00        00" << endl;
	cout << "     00            00       0000          00        00" << endl;
	cout << "     00            00       00            000000000000" << endl;
	cout << "     00            00       0000          00        00" << endl;
	cout << "     00            00       00  00        00        00" << endl;
	cout << "     00            00       00    00      00        00" << endl;
	cout << "     00            00       00      00    00        00" << endl;
	cout << "000000000000  000000000000  00        00  00        00" << endl;

}


void Greeter::showMenu() {

	int input_number;
	while (true) {
		system("cls");
		showTitle();
		cout << "----" << endl;
		cout << "Menu" << endl;
		cout << "----" << endl;
		cout << "[1] Recipe Manager" << endl;
		cout << "[2] Plan Manager" << endl;
		cout << "[0] Exit" << endl;

		std::cout << "\nSelect : " << std::flush;
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

				std::cout << "\nSelect : " << std::flush;
				int input_num_in_recipe;
				cin >> input_num_in_recipe;
				// clear buffer
				cin.ignore(); 	cin.clear();
				if (input_num_in_recipe == 0) {

					break;
				}
				else if (input_num_in_recipe == 1) {
					system("cls");
					addRecipe();
					cin.ignore();
					continue;
				}
				else if (input_num_in_recipe == 2) {
					system("cls");
					deleteRecipeDB();
					cin.ignore();
					continue;
				}
				else if (input_num_in_recipe == 3) {
					system("cls");
					editRecipe();
					cin.ignore();
					continue;
				}
				else if (input_num_in_recipe == 4) {
					system("cls");
					searchRecipe();
					cin.ignore();
					continue;
				}
				else if (input_num_in_recipe == 5) {
					system("cls");
					showRecipe();
					cin.ignore();
					continue;
				}
				else {
					cout << "-----------------------------------------------" << endl;
					cout << "Error: Invalid Input. Press Any Key to Go Back." << endl;
					cout << "-----------------------------------------------" << endl;

					cin.ignore();
					if (getchar())continue;

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
				//cout << "[3] Revise Plan" << endl;
				cout << "[3] Search Plan" << endl;
				cout << "[4] Show All Plan" << endl;
				cout << "[0] Back To Menu" << endl;
				int input_num_in_plan;
				cin >> input_num_in_plan;
				// clear buffer
				cin.ignore(); 	cin.clear();
				if (input_num_in_plan == 0) {
					break;
				}
				else if (input_num_in_plan == 1) {
					system("cls");
					addPlan(Plan());
					cout << endl << "Complete.Enter any key to go back" << endl;

					cin.ignore(); 	cin.clear();
					if (getchar())continue;
				}
				else if (input_num_in_plan == 2) {
					system("cls");
					deletePlan();
					cout << endl << "Complete.Enter any key to go back" << endl;
					cin.ignore(); 	cin.clear();
					if (getchar())continue;
				}
				/*else if (input_num_in_plan == 3) {
					system("cls");
					revisePlan();

					continue;
				}*/
				else if (input_num_in_plan == 3) {
					system("cls");
					searchPlan();
					cout <<endl<< "Enter any key to go back" << endl;
					cin.ignore(); 	cin.clear();
					if (getchar())continue;
				}
				else if (input_num_in_plan == 4) {
					system("cls");
					showPlan();
					cout << endl << "Enter any key to go back" << endl;
					cin.ignore(); 	cin.clear();
					if (getchar())continue;
				}
				else {
					cout << "-----------------------------------------------" << endl;
					cout << "Error: Invalid Input. Press Any Key to Go Back." << endl;
					cout << "-----------------------------------------------" << endl;
					cin.ignore(); 	cin.clear();
					if (getchar())continue;

				}

			}
			continue;
		}
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "Error: Invalid Input. Press Any Key to Go Back." << endl;
			cout << "-----------------------------------------------" << endl;
			cin.ignore(); 	cin.clear();
			if (getchar())continue;
		}


	}
}


void Greeter::addRecipe() {
	Recipe recipe;
	std::cout << "-------Recipe Infromation-------\n" << std::flush;
	// set ID
	unsigned int	id = 10000;
	ifstream ifs("./database/recipe.txt");
	if(ifs.fail()) {
		throw runtime_error("Unable to open the file");
	}
	else {
		while(ifs) {
			string line;
			Recipe recipe;
			getline(ifs, line);
			id++;
		}
	}
	ifs.close();
	recipe.setID(id + add_count);
	add_count++;
	// set name
	std::cout << "     Name             :  " <<std::flush;
	std::cin.clear();
	std::string recipe_name;
	std::getline(std::cin, recipe_name);
	recipe.setName(recipe_name);

	// set duration
	while (1) {
		std::cout << "Cooking Duration(min) :  " << std::flush;
		int duration;
		cin >> duration;
		std::cin.clear();
		recipe.setDuration(duration);
		break;
	}
	cin.ignore(); // delete EOF

	// set ingredients
	std::cout << "\n-----Ingredients-----\n(If you want to stop adding  ingredients, enter \"stop\")\n" << std::flush;
	std::vector<Ingredient> ingredients; int i = 1;
	while (1) {
		// set ingredient name
		std::cout << "Ingredient" << i << " name      :  " << std::flush;
		string name;
		std::getline(std::cin, name);

		if (name == "stop") { break; }
		else {
			// set ingredient weight
			std::cout << "Ingredient" << i << " weight    :  " << std::flush;
			string weight;
			std::getline(cin, weight);
			std::cout << endl;

			i += 1;
			Ingredient _ingredient(name, weight);
			ingredients.push_back(_ingredient);
		}
	}
	recipe.setIngredients(ingredients);

	// set order
	std::cout << "\n---Cookin Oreder---\n( If you want to stop adding  Orders, enter \"stop\" )\n" << std::flush;;
	vector<string> ingredient_order;
	{
		int i = 1;
		while (true) {
			std::cout << "Order" << i << " : " << std::flush;
			std::cin.clear();
			string order;
			std::getline(std::cin, order);
			if (order == "stop") {
				cout << "\nyou selected \"stop\"!" << endl;
				break; }
			else { recipe.addOrder(order); }
			i += 1;
		}
	}
	recipedatabase->insertRecipe(recipe);
	std::cout << "Recipe " << recipe.getName() << "save in DB!\nPress Enter to continue.." << endl;
}


// TODO :  && ID 10000??
// delete recipe
void Greeter::deleteRecipeDB() {
	std::cout << "Enter the recipe name you want to delete : " << std::flush;
	string del_recipe_name;
	std::getline(std::cin, del_recipe_name);

	// serarch
	Recipe del_recipe = recipedatabase->searchRecipes_recipename(del_recipe_name);
	if (del_recipe.getID() >= 10000 && del_recipe.getID() <= 11000) {
		recipedatabase->deleteRecipe(del_recipe);
		std::cout << del_recipe.getName() << " Completely Deleteed" << endl;
	}
	else { std::cout << "There is no search result for \"" << del_recipe_name << "\" in recipe list" << endl; }
	std::cout << "\nPress Enter to continue.." << endl;
}

// edit recipe
inline void Greeter::editRecipe() {
	cout << "Enter the recipe name you wnat to edit  : ";
	string search_recipe;
	std::getline(cin, search_recipe);
	Recipe search_result = recipedatabase->searchRecipes_recipename(search_recipe);

	if (search_result.getID() >= 10000 && search_result.getID() <= 11000) {
		search_result.printRecipe();
	}
	else {
		std::cout << "There is no search result for \"" << search_recipe << "\" in recipe list" << endl;
		std::cout << "\nPress Enter to continue.." << endl;
		return;
	}

	std::cout << "---------------------------------------------------------" << endl;
	std::cout << "Which part wnat to edit?\n[1] : name\n[2] : duration\n[3] : ingredients\n[4] : order" << endl;
	cout << "Select : " << std::flush;
	int select;
	cin >> select;

	switch (select) {
	case 1: {
		// set name
		system("cls");
		std::cout << "You select to edit Recipe name" << endl;
		std::cout << "Name to replace   :  " << std::flush;
		string recipe_name;
		cin.ignore();
		std::getline(std::cin, recipe_name);
		search_result.setName(recipe_name);
		std::cout << "completly change " << search_recipe << " to " << recipe_name << endl;
		break;
	}
	case 2: {
		// set duration
		system("cls");
		std::cout << "You select to edit Recipe Duration" << endl;
		std::cout << "Duration to replace   :  " << std::flush;
		int duration;
		std::cin >> duration;
		search_result.setDuration(duration);

		std::cin.ignore();
		std::cout << "completly change to " << duration << endl;

		break;
	}
	case 3: {
		// set ingredients
		system("cls");
		std::cout << "-----Ingredients-----\n(If you want to stop adding  ingredients, enter \"stop\")\n" << std::flush;
		std::vector<Ingredient> ingredients; int i = 1;
		cin.ignore();
		while (1) {
			// set ingredient name
			std::cout << "Ingredient" << i << " name      :  " << std::flush;
			string name;
			std::getline(std::cin, name);

			if (name == "stop") { break; }
			else {
				// set ingredient weight
				std::cout << "Ingredient" << i << " weight    :  " << std::flush;
				string weight;
				std::getline(cin, weight);
				std::cout << endl;

				i += 1;
				Ingredient _ingredient(name, weight);
				ingredients.push_back(_ingredient);
			}
		}
		search_result.setIngredients(ingredients);
		std::cout << "completly changed the ingredients" << endl;
		break;
	}
	case 4: {
		system("cls");
		std::cout << "-----Cookin Oreder-----\n( If you want to stop adding  Oreder, enter \"stop\" )\n" << std::endl;
		vector<string> ingredient_order;
		search_result.deleteOrder();
		int i = 1;
		cin.ignore();
		while (true) {
			std::cout << "Order" << i << " : ";
			string order;
			std::getline(std::cin, order);

			if (order == "stop") { break; }
			else { search_result.addOrder(order); }
			i += 1;
		}
		break;
	}
	default: { cout << "select between 1~4" << endl; }
	}
	recipedatabase->updateDatabase(search_result);
	std::cout << "\n\nPress Enter to continue.." << endl;
}

// search recipe by ingredients or recipename
void Greeter::searchRecipe() {
	std::cout << "Which do you search for, recipe name or ingredients?\n[1] : Recipe name\n[2] : Ingredients" << endl;
	std::cout << "Select : " << std::flush;
	int select;
	cin >> select;
	if (select == 1) { // search for recipe name
		std::cout << "---------------------------\nEnter the recipe name" << endl;
		std::cout << "Name : " << std::flush;
		string search_recipename;
		cin.ignore();
		std::getline(std::cin, search_recipename);

		Recipe search_recipe;
		search_recipe = recipedatabase->searchRecipes_recipename(search_recipename);

		if (search_recipe.getID() >= 10000 && search_recipe.getID() <= 11000) {
			std::cout << endl;
			recipedatabase->searchRecipes_recipename(search_recipename).printRecipe();
			std::cout << "Press Enter to continue.." << endl;
		}
		else {
			std::cout << "There is no search result for \"" << search_recipename << "\" in recipe list" << endl;
			std::cout << "\nPress Enter to continue.." << endl;
		}
	}
	else if (select == 2) { // search for ingredients
		std::cout << "\n---------------------------\nEnter the ingredients" << endl;
		std::cout << "(If you want to stop adding  ingredients, enter \"stop\")\n";
		vector<string> search_ingredients;
		cin.ignore();

		while (1) {
			string ingredient;
			std::cout << "Ingredients : " << std::flush;
			std::getline(cin, ingredient);

			if (ingredient == "stop") { std::cout << "\nSelected stop\n\n\n" << endl;  break; }
			else {
				search_ingredients.push_back(ingredient);
			}
		}

		vector<Recipe> search_list;
		search_list = recipedatabase->searchRecipes_ingredients(search_ingredients);
		if (!search_list.empty()) {  // If search_list is not empty, then..
			system("cls");
			for (Recipe result_recipe : search_list) {
				result_recipe.printRecipe();
				std::cout << "*********************************************" << endl;
			}
			std::cout << "\n\nPress Enter to continue.." << endl;

		}
		else {
			std::cout << "There is no search result in recipe list" << endl;
			std::cout << "\n\nPress Enter to continue.." << endl;

		}
	}
}

// show all recipe
inline void Greeter::showRecipe() {
	vector<Recipe> recipe_list;
	recipe_list = recipedatabase->getRecipes();
	for (Recipe recipe : recipe_list)
	{
		recipe.printRecipe();
	}
	std::cout << "Press Enter to continue.." << endl;
}






void Greeter::addPlan(Plan plan_to_add) {

	while (true) {
		system("cls");



			int year;
			int month;
			int day;
			string s_comments;
			int meal_type;
			system("cls");
			cout << "-Date Select-" << endl << endl;

				enterDate(&year, &month, &day);
				if (checkDate(year, month, day)) {
					cout << "Enter comment : ";
					getline(cin, s_comments);
					cout << "-Meal Type Select-" << endl;
					cout <<endl<< "1:Breakfast" << endl << "2:Lunch:" << endl << "3:Dinner" << endl << "4:Snack" << endl << "5:Late-Night Snack" << endl;
					cout <<endl<< "Enter mealType : ";
					cin >> meal_type;

					plan_to_add.getDate()->setDay(day);
					plan_to_add.getDate()->setMonth(month);
					plan_to_add.getDate()->setYear(year);
					plan_to_add.getDate()->setComment(s_comments);
					plan_to_add.year = year;
					plan_to_add.month = month;
					plan_to_add.day = day;
					plan_to_add.setMealType(meal_type);

				}

			Recipe menu_to_add;
			string recipe_name;
			int num_of_people;
			cout << endl << "-Menu Select-" << endl;
			while (true) {
				cout << "Enter name of menu you want : ";

				cin.clear(); cin.ignore();
				getline(cin, recipe_name);

				menu_to_add = recipedatabase->searchRecipes_recipename(recipe_name);
				while (true) {
					cout << "Enter number of people : ";
					cin >> num_of_people;
					if (num_of_people > 0) break;
					else {
						cout << "Error: Invalid Number. Enter Again." << endl;
					}
				}
				plan_to_add.getMenu()->addMenu(menu_to_add, num_of_people);
				temp_string_name = recipe_name;
				temp_num = num_of_people;
				plan_to_add.getMenuName()->push_back(temp_string_name);
				plan_to_add.getNumOfPeople()->push_back(temp_num);
				cin.clear(); cin.ignore();

				int input_num;
				while (true) {

					cout << endl << "[1]:Add More Menu" << endl;
					cout << "[2]:Finish" << endl;

					cin >> input_num;
					if (input_num == 1) {
						break;
					}
					else if (input_num == 2) {
						break;
					}
					else {
						cout << "Invalid Input" << endl;
						continue;
					}

				}
				if (input_num == 1) {
					continue;
				}
				else {
					break;
				}

			}
			planmanager.addPlan(plan_to_add);
			return;
			//continue;
		}




	return;



}
/*void Greeter::addPlan(Plan plan_to_add) {
	//Plan plan_to_add = Plan();
	//Meal meal_to_add = Meal();

	while (true) {
		system("cls");
		cout << "[1]: Select Date" << endl;
		cout << "[2]: Next Stage" << endl;
		cout << "[3]:"; // TODO: EXIT menu
		int input_num;
		cin >> input_num;
		std::cin.clear();	std::cin.ignore();
		if (input_num == 2) {
			system("cls");
			Recipe menu_to_add;
			string recipe_name;
			int num_of_people;
			system("cls");
			cout << "Enter name of menu you want:";
			getline(cin, recipe_name);
			menu_to_add = recipedatabase->searchRecipes_recipename(recipe_name);
			while (true) {
				cout << "Enter number of people:";
				cin >> num_of_people;
				if (num_of_people > 0) break;
				else {
					cout << "Error: Invalid Number. Enter Again." << endl;
				}
			}
			plan_to_add.getMenu()->addMenu(menu_to_add, num_of_people);
			temp_string = plan_to_add.getMenu()->get_meals()[0].menus.getName();
			temp_num = num_of_people;
			//std::cout << plan_to_add.getMenu()->get_meals()[0].menus.getName() << endl;

			//plan_to_add.menu_name = &(plan_to_add.getMenu()->get_meals()[0].menus.getName());

			//plan_to_add.numOfPeople = &num_of_people;

			//std::cout << "in greeter name : " << *(plan_to_add.menu_name) << "People : " << *(plan_to_add.numOfPeople) << endl;



			//meal_to_add.addMenu(menu_to_add, num_of_people);
			// plan_to_add.setMenu(meal_to_add);
			plan_to_add.menu_name = temp_string;
			plan_to_add.numOfPeople = temp_num;

			cin.clear(); cin.ignore();
			int i;
			cin >> i;
			cin.clear(); cin.ignore();
			planmanager.addPlan(plan_to_add);
			return;
			//continue;
		}
		else if (input_num == 1) {

			int year;
			int month;
			int day;
			string s_comments;
			int meal_type;
			system("cls");
			cout << "-Date Select-" << endl << endl;
			while (true) {
				enterDate(&year, &month, &day);
				if (checkDate(year, month, day)) {
					cout << "Enter comment:";
					getline(cin, s_comments);
					cout << "1:Breakfast" << endl << "2:Lunch:" << endl << "3:Dinner" << endl << "4:Snack" << endl << "5:Late-Night Snack" << endl;
					cout << "Enter mealType:";
					cin >> meal_type;

					plan_to_add.getDate()->setDay(day);
					plan_to_add.getDate()->setMonth(month);
					plan_to_add.getDate()->setYear(year);
					plan_to_add.setMealType(meal_type);

					// plan_to_add = Plan(year, month, day, s_comments, meal_to_add, meal_type);
					break;
				}
				else {
					continue;
				}
			}





		}
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "Error: Invalid Input. Press Any Key to Go Back." << endl;
			cout << "-----------------------------------------------" << endl;

			if (getchar())continue;
		}
	}

	return;



}*/


/*void Greeter::addPlan(int year, int month, int day, int meal_type, Plan plan_to_add) {
	Recipe menu_to_add;
	string recipe_name;
	int num_of_people;

	cout << "Enter name of menu you want:";
	getline(cin, recipe_name);
	menu_to_add = recipedatabase->searchRecipes_recipename(recipe_name);
	while (true) {
		cout << "Enter number of people:";
		cin >> num_of_people;
		if (num_of_people > 0) break;
		else {
			cout << "Error: Invalid Number. Enter Again." << endl;
		}
	}

	plan_to_add.getMenu()->addMenu(menu_to_add, num_of_people);
	temp_string = plan_to_add.getMenu()->get_meals()[0].menus.getName();
	temp_num = num_of_people;

	plan_to_add.menu_name.push_back(temp_string);
	plan_to_add.numOfPeople.push_back(temp_num);

	cin.clear(); cin.ignore();
	int i;
	cin >> i;
	cin.clear(); cin.ignore();
	planmanager.addPlan(plan_to_add);

	return;
}*/

void Greeter::deletePlan() {

	int year;
	int month;
	int day;
	int meal_type;
	system("cls");
	cout << "Enter date you want to delete!" << endl << endl;
	while (true) {
		enterDate(&year, &month, &day);
		if (checkDate(year, month, day)) {
			cout << "1:Breakfast" << endl << "2:Lunch:" << endl << "3:Dinner" << endl << "4:Snack" << endl << "5:Late-Night Snack" << endl;
			cout << "Enter mealType you want to delete : ";
			cin >> meal_type;

			break;
		}
		else {
			continue;
		}
	}
	planmanager.deletePlan(year, month, day, meal_type);
	return;


}

/*void Greeter::revisePlan() {

	int year;
	int month;
	int day;
	int meal_type;
	int input_num;
	system("cls");
	cout << "Enter date you want to revise!" << endl << endl;
	while (true) {
		enterDate(&year, &month, &day);
		if (checkDate(year, month, day)) {
			cout << "1:Breakfast" << endl << "2:Lunch:" << endl << "3:Dinner" << endl << "4:Snack" << endl << "5:Late-Night Snack" << endl;
			cout << "Enter mealType you want to revise:";
			cin >> meal_type;

			break;
		}
		else {
			continue;
		}
	}
	system("cls");
	planmanager.searchPlan(year, month, day, meal_type)->showPlan();
	cout << "[1]Revise Date" << endl;
	cout << "[2]Revise Meal Type" << endl;
	cout << "[3]Revise Meal" << endl;
	cout << "[4]Back" << endl;
	cin >> input_num;
	cin.clear();
	if (input_num == 1) {
		system("cls");
		planmanager.reviseDate(year, month, day, meal_type);
	}
	else if (input_num == 3) {
		system("cls");
		Meal menu = Meal();
		while (true) {
			system("cls");
			Recipe menu_to_add;
			string recipe_name;
			int num_of_people;
			system("cls");
			cin.clear(); cin.ignore();
			cout << "Enter name of menu you want:";
			cin.clear(); cin.ignore();
			getline(cin, recipe_name);
			menu_to_add = recipedatabase->searchRecipes_recipename(recipe_name);
			while (true) {
				cout << "Enter number of people:";
				cin >> num_of_people;
				if (num_of_people > 0) { cin.clear(); cin.ignore(); break; }
				else {
					cout << "Error: Invalid Number. Enter Again." << endl;
				}
			}

			int input_n;
			while (true) {
				cout << "[1]Add More Menu" << endl;
				cout << "[2]Finish Revising" << endl;
				cin.clear(); cin.ignore();
				cin >> input_n;
				if (input_n == 1) {
					break;;
				}
				else if (input_n == 2) {
					break;
				}
				else {
					cout << "Error: Invalid Number. Enter Again." << endl;
					continue;
				}
			}
			if (input_n == 1) {
				continue;
			}
			else {
				break;
			}
			return;
		}
		//planmanager.reviseMeal(year, month, day, meal_type,menu);
		planmanager.deletePlan(year, month, day, meal_type);
		addPlan(year, month, day, meal_type, Plan());
	}
	else if (input_num == 2) {
		system("cls");
		planmanager.reviseMealType(year, month, day, meal_type);
	}
	return;




}*/
void Greeter::searchPlan() {
	int year;
	int month;
	int day;
	int meal_type;
	enterDate(&year, &month, &day);
	cout << "Enter Meal Type : ";
	cin >> meal_type;


	planmanager.showSpecificPlan(year, month, day, meal_type);
	int i;
	cin >> i;
	return;

}
void Greeter::showPlan() {
	planmanager.showAllPlan();

	return;
}
