#ifndef MEAL_H
#define MEAL_H
#include"recipe.h"
using namespace std;

class Meal {
private:
	vector<Recipe> menus;
	int num_of_people;
public:
	Meal();
	~Meal();
	void AddMenu(Recipe _menu);
	void DeleteMenu(Recipe _menu);
	vector<Recipe> get_menus();
	int get_num_of_people();
	void set_num_of_people();
	void ShowMeal();
};
#endif