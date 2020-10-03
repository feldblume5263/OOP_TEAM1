#ifndef RECIPE_H
#define RECIPE_H
#include<vector>
#include<string>
using namespace std;

class Recipe {
private:
    int id;
    string name;
    string description;
    vector<string> ingredients;
public:
    Recipe(int id) { this->id = id; }
    ~Recipe(){};
   
    //Functions
    void addIngredient(string ingredient);
    bool removeIngredient(string ingredient);
    bool searchIngredient(string ingredient);
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
    vector<string>& getIngredients() {
        return ingredients;
    } 
    //Set
    void setName(string name) {
        this->name = name;
    }
    void setDescription(string description) {
        this->description = description;
    }
	
};






#endif
