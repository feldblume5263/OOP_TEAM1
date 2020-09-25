#ifndef PLAN_H
#define PLAN_H
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
	Plan(Date _date, Meal _menu, int _meal_type);
	~Plan();
	Date get_date(Date _date);
	void set_date();
	Meal get_menu(Meal _menu);
	void set_menu();
	int get_meal_type();
	void set_meal_type();
	void ShowPlan();
};
#endif