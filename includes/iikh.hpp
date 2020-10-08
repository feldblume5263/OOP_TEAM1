#pragma once

#ifndef IIKH_HPP
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
#include <memory>
#include <windows.h>
#include <conio.h>

# include "recipe.h"
# include "recipe_database.h"
# include "meal.h"
# include "plan.h"
# include "planManager.h"

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
	Ingredient(string name, int weight) : name(name), weight(weight) {}
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
void enterDate(int* _year, int* _month, int* _day) {
	string s_year;
	string s_month;
	string s_day;
	cout << "Enter year:";
	getline(cin, s_year);
	*_year = atoi(s_year.c_str());
	cout << "Enter month:";
	getline(cin, s_month);
	*_month = atoi(s_month.c_str());
	cout << "Enter day:";
	getline(cin, s_month);
	*_day = atoi(s_month.c_str());
}
bool checkDate(int _year, int _month, int _day) {
	if (_year <= 0) {
		cout << "Invalid Year" << endl;
		return false;
	}
	else {
		if (_month > 12 || _month < 0) {
			cout << "Invalid Month" << endl;
			return false;
		}
		else {
			switch (_month) {
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				if (_day > 31 || _day <= 0) {
					cout << "Invalid Day" << endl;

					return false;
				}
				break;
			case 4: case 6: case 9: case 11:
				if (_day > 30 || _day <= 0) {
					cout << "Invalid Day" << endl;

					return false;
				}
				break;
			case 2:
				if (_day > 28 || _day <= 0) {
					cout << "Invalid Day" << endl;

					return false;
				}
				break;
			}
		}
	}
	return true;
}
#endif
