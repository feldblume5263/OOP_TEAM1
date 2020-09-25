#ifndef RECIPE_H
#define RECIPE_H
#include<vector>
#include<string>
using namespace std;
class Recipe {
private:
	vector<string> ingredients;
	vector<string> order;
	string name;
public:
	Recipe();
	Recipe(string _name);
	~Recipe();
	void Revise();
	void Add();
	void Remove();
	void ShowRecipe();
	string get_name();
	string set_name();


};






#endif