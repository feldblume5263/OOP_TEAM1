#include "../includes/recipe_database.h"

RecipeDatabase::RecipeDatabase(){
    file_manager = new FileManager();
    file_manager->load(recipe_list);
    new_id = recipe_list.size()==0 ? 10000 : recipe_list.back().getID() + 1;

}

RecipeDatabase::~RecipeDatabase(){
    file_manager -> write(recipe_list);
    delete file_manager;
}
void RecipeDatabase::updateDatabase(Recipe recipe) {
    for(auto& rec: recipe_list) {
        if(rec.getID() == recipe.getID()) {
            rec.setDuration(recipe.getDuration());
            rec.setIngredients(recipe.getIngredients());
            rec.setName(recipe.getName());
            rec.setOrder(recipe.getOrder());
        }
    }
}


void RecipeDatabase::insertRecipe(string name, vector<Ingredient> ingredients, vector<string> orders, int duration) {
   Recipe new_recipe = Recipe(new_id, duration, name, ingredients, orders);
   recipe_list.push_back(new_recipe);
   new_id += 1;
}
void RecipeDatabase::deleteRecipe(Recipe& recipe) {
    for(int i=0; i<recipe_list.size(); i++) {
        if(recipe_list[i].getID() == recipe.getID()) {
            recipe_list.erase(recipe_list.begin() + i);
        }
    }
}
vector<Recipe> RecipeDatabase::getRecipes() {
    return recipe_list;
}
vector<Recipe> RecipeDatabase::searchRecipes_ingredients(vector<string> ingredients) {
    vector<Recipe> ret;
    for(Recipe recipe: recipe_list) {
        int matched_num = 0;
        for(string keyword: ingredients) {
            for(Ingredient ingredient: recipe.getIngredients()) {
                if(keyword == ingredient.getName()) {
                    matched_num += 1;
                    break;
                }
            }
        }

        if(ingredients.size() == matched_num) {
            ret.push_back(recipe);
        }
    }

    return ret;
}

Recipe RecipeDatabase::searchRecipes_recipename(string recipename) {
    Recipe ret;
    for (Recipe recipe : recipe_list) {
        if (recipename == recipe.getName()) {
            ret = recipe;
            break;
        }
    }
    return ret;
}



// File Manager Class
FileManager::FileManager(): file_name("./database/recipe.txt") {
    parser = new Parser();
}
FileManager::~FileManager() {
    delete parser;
}

void FileManager::load(vector<Recipe>& recipes) {
    ifstream ifs(file_name);
    if(ifs.fail()) {
        ofstream file_creation(file_name);
        if(file_creation.fail()) {
            throw runtime_error("Unable to open the file");
        }
        else {
            file_creation.close();
        }
    }
    else {
        while(ifs) {
            string line;
            Recipe recipe;
            getline(ifs, line);
            if(line.length() > 1) {
                parser -> parse(line, recipe);
                recipes.push_back(recipe);
            }
        }
        ifs.close();
    }
}

void FileManager::write(vector<Recipe> recipes) {
    ofstream ofs(file_name);
    if(ofs.is_open()) {
        for(Recipe recipe: recipes) {
            ofs << recipe.getID() << "/";
            ofs << recipe.getName() << "/";

            int order_num = recipe.getOrder().size();
            for(int i=0; i<order_num; i++) {
                ofs << recipe.getOrder()[i];
                ofs << ((i == order_num-1) ? "/" : "|");
            }
            ofs << recipe.getDuration() << "/";

            int ingredients_num = recipe.getIngredients().size();
            for(int i=0; i<ingredients_num; i++) {
                ofs << recipe.getIngredients()[i].getName() << "," << recipe.getIngredients()[i].getWeight();
                ofs << ((i == ingredients_num-1) ? "\n" : "/");
            }
        }

        ofs.close();
    }
    else {
        throw runtime_error("Unable to open the file");
    }
}

// Parser Class
void Parser::parse(string line, Recipe& recipe) {
    istringstream iss(line);
    string string_buffer;
    vector<Ingredient> ingredients;
    vector<string> orders;

    for(int parsed = 0; getline(iss, string_buffer, '/'); parsed++) {
        switch(parsed) {
        case STORING_RULE::CODE:
            recipe.setID(stoul(string_buffer));
            break;
        case STORING_RULE::NAME:
            recipe.setName(string_buffer);
            break;
        case STORING_RULE::PREPARATION_STEP:
            orders = split(string_buffer, '|');
            recipe.setOrder(orders);
            break;
        case STORING_RULE::EXPECTED_TIME:
            recipe.setDuration(stoi(string_buffer));
            break;
        default:
            istringstream ssb(string_buffer);
            string name, weight;
            getline(ssb, name, ',');
            getline(ssb, weight, ',');
            Ingredient ingredient(name, weight);
            ingredients.push_back(ingredient);
        }
    }

    recipe.setIngredients(ingredients);
}

/*int main() {
    try {
        Database* db = new Database();
        RecipeDatabase recipedb = *db -> getDatabase();
        vector<Ingredient> ingredients;
        ingredients.push_back(Ingredient("�κ�", 400));
        ingredients.push_back(Ingredient("��ġ", 600));
        recipedb.insertRecipe("�κα�ġ", ingredients, {"��ġ�� ���.", "�κθ� ���.", "���ÿ� ��´�."}, 5);

        ingredients.clear();
        ingredients.push_back(Ingredient("��ġ", 400));
        ingredients.push_back(Ingredient("��", 600));
        ingredients.push_back(Ingredient("���� ����", 10));
        recipedb.insertRecipe("��ġ�", ingredients, {"��ġ�� ���.", "���� ������ ���´�.", "���� �װ� ���δ�.", "��ġ�� �ְ� ���δ�."}, 20);

        recipedb.deleteRecipe(Recipe(10000));
        recipedb.deleteRecipe(Recipe(10001));

        ingredients.clear();
        ingredients.push_back(Ingredient("����", 50));
        ingredients.push_back(Ingredient("��", 600));
        ingredients.push_back(Ingredient("���� ����", 10));
        recipedb.updateDatabase(Recipe(10003, 60, "�����", ingredients, {"������ �ִ´�.", "���� ���δ�."}));

        vector<Recipe> recipes = recipedb.getRecipes();
        for(auto recipe: recipes) {
            recipe.printRecipe();
        }

        delete db;
    } catch(const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}*/