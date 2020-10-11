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
#include <stdlib.h>
#include <cstdio>
#include <unordered_map>


using namespace std;


class Ingredient {
private:
	string name;
	string weight;
public:
	Ingredient(string name, string weight) : name(name), weight(weight) {}
	string getName() {
		return name;
	}
	string getWeight() {
		return weight;
	}
	void setName(string name) {
		this->name = name;
	}
	void setWeight(string weight) {
		this->weight = weight;
	}
};

vector<string> split(string str, char delimiter);
void enterDate(int* _year, int* _month, int* _day);
bool checkDate(int _year, int _month, int _day);


#endif
