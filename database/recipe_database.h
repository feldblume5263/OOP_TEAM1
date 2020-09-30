#ifndef RECIPE_DATABASE_H
#define RECIPE_DATABASE_H
#include <fstream>
#include <sstream>
#include <string>
#include"recipe.h"
using namespace std;

class RecipeDatabase {
private:
	string file_name;
	void parseRecipe(string line, Recipe& recipe);
	bool containsIngredients(vector<string> ingredients, Recipe recipe) const;
public:
	RecipeDatabase();
	RecipeDatabase(const char* _file_name);
	~RecipeDatabase();
	void updateDatabase();
	void insertRecipe(vector<string> ingredients, vector<int> weight);
	void deleteRecipe(Recipe recipe);
	vector<Recipe> getRecipes();
	vector<Recipe> getRecipes(vector<string> ingredients);
 
};



#endif
