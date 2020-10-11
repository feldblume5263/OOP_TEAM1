#pragma once
#include "iikh.hpp"
#include "recipe_database.h"
#include "planManager.h"


class Greeter {
private:
	unique_ptr<RecipeDatabase> recipedatabase;
	PlanManager planmanager;
	string temp_string_name;
	int temp_num;
public:
	Greeter();
	void showTitle();
	void showMenu();
	void addRecipe(); // add new recipe
	void deleteRecipeDB(); // delete recipe
	void editRecipe(); // edit recipe
	void searchRecipe(); // search recipe by ingredients or recipename
	void showRecipe(); // show all recipe
	void addPlan(Plan plan_to_add);
	void addPlan(int year, int month, int day, int meal_type, Plan plan_to_add); // function overloading
	void deletePlan();
	void revisePlan();
	void searchPlan();
	void showPlan();



};












