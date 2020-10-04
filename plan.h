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
	Plan(int _month, int _day, Meal& _menu, int _meal_type);
	~Plan();
	Date getDate();
	void setDate(Date& _date);
	void setDate(int _year, int _month);
	Meal getMenu();
	void setMenu(Meal& _menu);
	int getMealType();
	void setMealType(int _meal_type);
	void showPlan();
};
#endif