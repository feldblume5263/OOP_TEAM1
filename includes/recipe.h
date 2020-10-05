#ifndef RECIPE_H
#define RECIPE_H
#include<vector>
#include<string>
#include "iikh.hpp"

using namespace std;

class Recipe {
private:
    int id;
    int duration;
    string name;
    string description;
    vector<Ingredient> ingredients;
    vector<string> ingredient_order;
public:
    Recipe(int id) { this->id = id; }
    ~Recipe(){};

    //Functions
    void addIngredient(Ingredient ingredient);
    bool removeIngredient(string ingredient);
    bool searchIngredient(Ingredient ingredient);
    void addOrder(string order);
    void printRecipe();
    //Get
    int getID() {
        return id;
    }
    string getName() {
        return name;
    }
    string getDescription() {
        return description;
    }
    vector<Ingredient>& getIngredients() {
        return ingredients;
    }
    vector<string>& getOrder() {
        return ingredient_order;
    }
    int getDuration() {
        return duration;
    }

    //Set
    void setName(string name) {
        this->name = name;
    }
    void setDescription(string description) {
        this->description = description;
    }
    void setDuration(int duration) {
        this->duration = duration;
    }


};






#endif
