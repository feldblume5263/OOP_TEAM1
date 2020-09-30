#include "recipe_database.h"

RecipeDatabase::RecipeDatabase() {
    this->file_name = "recipe.txt";
}

RecipeDatabase::RecipeDatabase(const char* file_name) {
    this->file_name = file_name;
}

RecipeDatabase::~RecipeDatabase(){}
void RecipeDatabase::updateDatabase() {

}

void RecipeDatabase::insertRecipe(vector<string> ingredients, vector<int> weights) {
    
}
void RecipeDatabase::deleteRecipe(Recipe recipe) {

}

void RecipeDatabase::parseRecipe(string line, Recipe& recipe) {
    enum RECIPE_ORDER { CODE, NAME };
    istringstream iss(line);
    string string_buffer;
    vector<string> ingredients;
    vector<int> weights;

    for(int parsed = 0; getline(iss, string_buffer, '/'); parsed++) {
        if(parsed == RECIPE_ORDER::CODE) {
            recipe.setId(stoul(string_buffer));
        }
        else if(parsed == RECIPE_ORDER::NAME) {
            recipe.setName(string_buffer);
        }
        else {
            istringstream ssb(string_buffer);
            string ingredient, weight;
            getline(ssb, ingredient, ',');
            getline(ssb, weight, ',');
            ingredients.push_back(ingredient);
            weights.push_back(stoi(weight));
        }
    }

    recipe.setIngredients(ingredients);
    recipe.setWeights(weights);
}

bool RecipeDatabase::containsIngredients(vector<string> ingredients, Recipe recipe) const {
    // 입력될 때 파일에 ingredients가 정렬된 상태로 저장된다고 가정
    vector<string> selected_ingredients = recipe.getIngredients();
    int idx = 0, same_num = 0;

    if(ingredients.size() > selected_ingredients.size()) return false;
    for(string ingredient: ingredients) {
        for(; idx<selected_ingredients.size(); idx++) {
            if(ingredient > selected_ingredients[idx]) return false;
            else if(ingredient == selected_ingredients[idx]) {
                same_num += 1;
                idx += 1;
                break;
            }
        }
    }
    
    if(same_num < ingredients.size()) return false;
    return true;
}

vector<Recipe> RecipeDatabase::getRecipes() {
    vector<Recipe> ret;
    ifstream dbfile(file_name);

    if(dbfile.is_open()) {
        while(!dbfile.eof()) {
            string line;
            Recipe recipe;
            getline(dbfile, line);
            parseRecipe(line, recipe);
            ret.push_back(recipe);
        }
        dbfile.close();
    }
    else {
        // throw noRecipesExeception();
    }

    return ret;
}

vector<Recipe> RecipeDatabase::getRecipes(vector<string> ingredients) {
    vector<Recipe> ret;
    ifstream dbfile(file_name);

    if(dbfile.is_open()) {
        while(!dbfile.eof()) {
            string line;
            Recipe recipe;
            getline(dbfile, line);
            parseRecipe(line, recipe);
            if(containsIngredients(ingredients, recipe)) {
                ret.push_back(recipe);
            }
        }
        dbfile.close();
    }
    else {
        // throw noRecipesExeception();
    }

    if(ret.size() == 0) { 
        //throw noRecipesException();
     }
     return ret;
}