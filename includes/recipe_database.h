#ifndef RECIPE_DATABASE_H
#define RECIPE_DATABASE_H
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include"recipe.h"

using namespace std;
//typedef struct Ingredient {
//	string name;
//	int weight;
//	bool operator<(const Ingredient& a) {
//		return a.name == this->name ? this->name < a.name : this->weight < a.weight;
//	}
//} Ingredient;

class RecipeDatabase {
private:
	string file_name;
	unsigned int last_id;
	void parseRecipe(string line, Recipe& recipe);
	void writeRecipes(vector<Recipe> recipes);
	bool containsIngredients(vector<string> ingredients, Recipe recipe) const;
public:
	RecipeDatabase();
	~RecipeDatabase();
	void updateDatabase(Recipe recipe);
	void insertRecipe(vector<Ingredient> ingredients);
	void deleteRecipe(Recipe recipe);
	vector<Recipe> getRecipes();
	vector<Recipe> getRecipes(vector<string> ingredients);

};



#endif
