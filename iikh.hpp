#pragma once
#ifndef MEAL_H
#define MEAL_H
#include "date.h"
#include "meal.h"
#include "plan.h"
#include "5_PlanManager/planManager.h"
#include "database/recipe_database.h"
#include "recipe.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
#include <fstream>
#include <sstream>
using namespace std;

typedef struct Ingredient {
	string name;
	int weight;
	bool operator<(const Ingredient& a) {
		return a.name == this->name ? this->name < a.name : this->weight < a.weight;
	}
} Ingredient;

//typedef struct Serving {
//	std::vector <int> num_of_people;
//	std::vector <Recipe> menus;
//} Serving;

#endif