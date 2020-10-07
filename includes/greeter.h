#pragma once
#include "iikh.hpp"	

class Greeter {
private:
	RecipeDatabase recipedatabese;
public:
	void addRecipe(); // add new recipe
	void deleteRecipeDB(); // delete recipe
	void editRecipe(); // edit recipe
	void searchRecipe(); // search recipe by ingredients or recipename
	void showRecipe(); // show all recipe


};












