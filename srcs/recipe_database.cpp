#include "../includes/recipe_database.h"

RecipeDatabase::RecipeDatabase() {
    this->file_name = "../database/recipe.txt";
    ifstream dbfile(file_name);

    if(dbfile.is_open()) {
        dbfile.seekg(0, std::ios::end);
        int size = dbfile.tellg();
        if(size == 0) last_id = 10000;
        else {
            dbfile.seekg(0, std::ios::beg);
            string line;
            while(dbfile) {
                getline(dbfile, line);
            }
            istringstream ss(line);
            string id;
            getline(ss, id, '/');
            last_id = stoul(id);
        }
        dbfile.close();
    }
    else {
        ofstream file_creation(file_name);
        if(file_creation.is_open()) {
            file_creation.close();
        }
        else {
            // throw noRecipesExeception();
        }
        last_id = 10000;
    }

}

RecipeDatabase::~RecipeDatabase(){}
void RecipeDatabase::updateDatabase(Recipe recipe) {
    vector<Recipe> recipes = getRecipes();
    for(auto& rec: recipes) {
        if(rec.getid() == recipe.getid()) {
            rec.setName(recipe.getName());
            rec.setIngredients(recipe.getIngredients());
            rec.setWeights(recipe.getWeights());
        }
    }
    writeRecipes(recipes);
}

void RecipeDatabase::insertRecipe(vector<Ingredient> ingredients) {
    int ingredients_num = ingredients.size();
    ofstream dbout(file_name, std::ios::app);
    if(dbout.is_open()) {
        dbout << last_id << "/";
        last_id += 1;
        sort(ingredients.begin(), ingredients.end());

        for(int i=0; i<ingredients_num; i++) {
            dbout << ingredients[i].name << "," << ingredients[i].weight;
            dbout << (i == ingredients_num-1) ? "\n" : "/";
        }
        dbout.close();
    }
    else {
        // throw noRecipesExeception();
    }
}
void RecipeDatabase::deleteRecipe(Recipe recipe) {
    vector<Recipe> recipes = getRecipes();
    for(int i=0; i<recipes.size(); i++) {
        if(recipes[i].getid() == recipe.getid()) {
            recipes.erase(recipes.begin() + i);
        }
    }
    writeRecipes(recipes);
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

void RecipeDatabase::writeRecipes(vector<Recipe> recipes) {
    ofstream dbout(file_name);
    int recipes_num = recipes.size();
    if(dbout.is_open()) {
        for(int i=0; i<recipes_num; i++) {
            int ingredients_num = recipes[i].getIngredients().size();
            for(int j=0; j<ingredients_num; j++) {
                dbout << recipes[i].getid() << "/";
                dbout << recipes[i].getIngredients()[j] << "," << recipes[i].getWeights()[j];
                dbout << (j == ingredients_num-1) ? "\n" : "/";
            }
        }
        dbout.close();
    }
    else {
        // throw noRecipesExeception();
    }
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
        while(dbfile) {
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

int main() {
    RecipeDatabase* recipedb = new RecipeDatabase();
    vector<Recipe> recipes = recipedb -> getRecipes();
    for(auto recipe: recipes) {
        cout << recipe.getid() << " " << recipe.getName();
    }
    return 0;
}
