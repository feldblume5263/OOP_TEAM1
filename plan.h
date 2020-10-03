#ifndef PLAN_H
#define PLAN_H
#include<iostream>
#include"meal.h"
#include"date.h"
using namespace std;

class Plan {
private:
	Date date;
	Meal menu;
	int meal_type;
public:
	Plan();
	Plan(Date& _date, Meal& _menu, int _meal_type);
	~Plan();
	Date get_date();
	void set_date(Date& _date);
	Meal get_menu();
	void set_menu(Meal& _menu);
	int get_meal_type();
	void set_meal_type(int _meal_type);
	void ShowPlan();
};
#endif