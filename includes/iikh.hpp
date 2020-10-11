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

typedef struct Serving {
    Recipe menus;
    int num_of_people;
} Serving;

vector<string> split(string str, char delimiter);
void enterDate(int* _year, int* _month, int* _day);
bool checkDate(int _year, int _month, int _day);


#endif
