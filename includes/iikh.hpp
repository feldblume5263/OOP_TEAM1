#pragma once

#ifndef IIKH_HPP
<<<<<<< HEAD
# define IIKH_HPP
# include "date.h"
# include "meal.h"
# include "plan.h"
# include "planManager.h"
# include "recipe_database.h"
# include "recipe.h"
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <tuple>
# include <fstream>
# include <sstream>
=======
#define IIKH_HPP
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <ctime>
>>>>>>> 1a639a1a122ddeb07ab5a7b3b8f89e49ad222644

using namespace std;

//typedef struct Ingredient {
	//string name;
	//int weight;
	//bool operator<(const Ingredient& a) {
		//return a.name == this->name ? this->name < a.name : this->weight < a.weight;
	//}
//} Ingredient;
class Ingredient {
private:
	string name;
	int weight;
public:
	Ingredient(string name, int weight): name(name), weight(weight) {}
	string getName() {
		return name;
	}
	int getWeight() {
		return weight;
	}
	void setName(string name) {
		this->name = name;
	}
	void setWeight(int weight) {
		this->weight = weight;
	}
};

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }

    return internal;
}

struct Serving {
	Recipe menus;
	int num_of_people;
};

#endif
