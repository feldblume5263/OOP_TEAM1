#ifndef RECIPE_DATABASE_H
#define RECIPE_DATABASE_H
#include "iikh.hpp"
#include "recipe.h"

/**
 * @class Parser
 * Responsible for parsing text files in existing databases according to established rules.
 * Take STORING_RULE as a member variable to have the rules for storing text files in order.
 */
class Parser {
private:
	enum STORING_RULE {
		CODE, NAME, PREPARATION_STEP, EXPECTED_TIME, INGREDIENT
	};
public:
	/**
	 * @param line Pass a line of text file to string type
	 * @param recipe Recipe object reference to contain parsed results
	 */
	void parse(string line, Recipe& recipe);
};

/**
 * @class FileManager
 * Responsible for opening, closing, reading, and writing files.
 * Load the contents of the file when RecipeDatabase is created, 
 * and overwrite the contents of the memory with the file when it is destroyed.
 */
class FileManager {
private:
	string file_name;
	Parser *parser;
public:
	FileManager();
	~FileManager();
	/**
	 * @param recipes 
	 * [load]  Recipe array of RecipeDatabase to load the contents of text files
	 * [write] Recipe array of RecipeDatabase to overwrite in text file
	 */
	void load(vector<Recipe>& recipes);
	void write(vector<Recipe> recipes);
};

/**
 * @class FileManager
 * Responsible for performing operations in general databases.
 * It has a recipe array as a member variable, so when it was created, the contents of the file were read and cached in memory.
 * Update what is added, deleted, or modified while the program is running
 * Save the contents of the array to a file when the instance is destroyed.
 * 
 */
class RecipeDatabase {
private:
	FileManager *file_manager;
	vector<Recipe> recipe_list;
	unsigned int new_id;
public:
	RecipeDatabase();
	~RecipeDatabase();
	void updateDatabase(Recipe recipe);
	/**
	 * @param name recipe name to insert
	 * @param ingredients array of ingredient name and weight to insert
	 * @param orders preparation steps to insert
	 * @param duration expected preparation time to insert
	 */
	void insertRecipe(string name, vector<Ingredient> ingredients, vector<string> orders, int duration);
	void deleteRecipe(Recipe recipe);
	vector<Recipe> getRecipes();
	/**
	 * @param keywords User-entered ingredient list
	 */
	vector<Recipe> getRecipes();
	void insertRecipe(Recipe recipe);
	//void insertRecipe(string name, vector<Ingredient> ingredients, vector<string> orders, int duration);
	void deleteRecipe(Recipe recipe);
	vector<Recipe> getRecipes();
	vector<Recipe> searchRecipes_ingredients(vector<string> ingredients);
	Recipe searchRecipes_recipename(string recipename);

};

#endif
