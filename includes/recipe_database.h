#ifndef RECIPE_DATABASE_H
#define RECIPE_DATABASE_H
#include "../includes/iikh.hpp"

class RecipeDatabase {
private:
	FileManager *file_manager;
	vector<Recipe> recipe_list;
	unsigned int new_id;
public:
	RecipeDatabase();
	~RecipeDatabase();
	void updateDatabase(Recipe recipe);
	void insertRecipe(string name, vector<Ingredient> ingredients, vector<string> orders, int duration);
	void deleteRecipe(Recipe recipe);
	vector<Recipe> getRecipes();
	vector<Recipe> getRecipes(vector<string> keywords);

};

class FileManager {
private:
	string file_name;
	Parser *parser;
public:
	FileManager();
	~FileManager();
	void load(vector<Recipe>& recipes);
	void write(vector<Recipe> recipes);
};

class Parser {
private:
	enum STORING_RULE {
		CODE, NAME, PREPARATION_STEP, EXPECTED_TIME, INGREDIENT
	};
public:
	void parse(string line, Recipe& recipe);
};

#endif
