#pragma once
#include "iikh.hpp"	


class Greeter {
private:
	unique_ptr<RecipeDatabase> recipedatabase;
	PlanManager planmanager;
public:
	void showTitle();
	void showMenu();
	void addRecipe(); // add new recipe
	void deleteRecipeDB(); // delete recipe
	void editRecipe(); // edit recipe
	void searchRecipe(); // search recipe by ingredients or recipename
	void showRecipe(); // show all recipe
	void addPlan();
	void deletePlan();
	void revisePlan();
	void searchPlan();
	void showPlan();



};












