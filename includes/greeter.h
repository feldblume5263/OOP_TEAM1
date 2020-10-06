#pragma once
#include "iikh.hpp"	

class Greeter {
private:

public:
	
};



void addRecipe();
void deleteRecipe();
void editRecipe();
void searchRecipe();





void addRecipe() {
	std::cout << "Enter recipe name" << std::endl;
	std::cout << "Name    :" << endl;
	


	//std::cout << "Enter recipe information in [[ NAME -> DESCRIPTION -> TIME -> INGREDIENTS ]] order" << std::endl;
	//std::cout << "Name			: " << std::flush;	std::cin.clear();	std::cin.ignore();	std::string name;			std::getline(std::cin, name);
	//std::cout << "Direction	: " << std::flush;	std::cin.clear();						std::string description;	std::getline(std::cin, description);
	//std::cout << "Cooking Time(min)	: " << std::flush;	std::cin.clear();						int time;					std::cin >> time;
	//std::cout << "Ingredients (If you want to stop enter \"stop\" ) : " << std::flush;
	//std::vector<std::string> ingredients;
	//std::cin.ignore();

	//while (true)
	//{
	//	std::string ingredient; std::getline(std::cin, ingredient);
	//	if (ingredient == "stop")break;
	//	ingredients.push_back(ingredient);
	//}

	//try
	//{
	//	Recipe* recipe = new Recipe(name, description, time, ingredients);
	//	recipeDB._insert(name, *recipe);
	//}
	//catch (DBException& e) {
	//	e.resolve();
	//}

}

void deleteRecipe() {



}

void editRecipe() {


}


void searchRecipe() {



}

// TODO : add, delete, edit, show recipe