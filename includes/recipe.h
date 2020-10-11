#ifndef RECIPE_H
#define RECIPE_H
#include "iikh.hpp"

using namespace std;

class Recipe {
private:
    unsigned int id;
    int duration;
    string name;
    vector<Ingredient> ingredients;
    vector<string> ingredient_order;
public:
    Recipe() {}
    Recipe(unsigned int id) : id(id) {}
    Recipe(unsigned int id, int duration, string name, vector<Ingredient> ingredients, vector<string> orders)
        : id(id), duration(duration), name(name), ingredients(ingredients), ingredient_order(orders) {}
    ~Recipe(){};

    //Functions
    void addIngredient(Ingredient ingredient);
    bool removeIngredient(string ingredient);
    void addOrder(string order);
    void deleteOrder();
    void printRecipe();
    //Get
    unsigned int getID() {
        return id;
    }
    string getName() {
        return name;
    }
    vector<Ingredient> getIngredients() {
        return ingredients;
    }
    vector<string> getOrder() {
        return ingredient_order;
    }
    int getDuration() {
        return duration;
    }

    //Set
    void setID(unsigned int id) {
        this->id = id;
    }
    void setName(string name) {
        this->name = name;
    }
    void setDuration(int duration) {
        this->duration = duration;
    }
    void setIngredients(vector<Ingredient> ingredients) {
        this->ingredients = ingredients;
    }
    void setOrder(vector<string> order) {
        this->ingredient_order = order;
    }

};


#endif
