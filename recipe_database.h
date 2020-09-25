#ifndef RECIPE_DATABASE_H
#define RECIPE_DATABASE_H
#include <fstream>
#include"recipe.h"
using namespace std;

class RecipeDatabase {
private:
	ifstream read_file;
	ofstream write_file;
	vector<Recipe> recipe_list;
public:
	RecipeDatabase();
	RecipeDatabase(const char* _file_name);
	~RecipeDatabase();
	void UpdateDatabase();
	void ReviseRecipe();
	void InsertRecipe();
	void DeleteRecipe();
	Recipe get_recipe();

	 
};



#endif
