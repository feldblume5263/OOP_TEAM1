#ifndef PLAN_H
# define PLAN_H

#include "iikh.hpp"
#include "meal.h"
#include "date.h"

using namespace std;

class				Plan
{
protected:
	Meal			menu;
	int				meal_type;
	Date			date;


public:
	int				year;
	int				month;
	int				day;
	Plan();
	Plan(int _year, int _month, int _day, string  _comments, Meal& _menu, int _meal_type);
	
	~Plan();

	Date* getDate();
	void			setDate(Date& _date);
	void			setDate(int _year, int _month, int _day, string _comment);
	Meal			getMenu();
	void			setMenu(Meal& _menu);
	int				getMealType();
	void			setMealType(int _meal_type);
	bool			comparePlan(int _year, int _month, int _day, int _meal_type);
	bool			comparePlan(Plan plan);
	void			showPlan();

	void			makePlan() { }; // make new plan

	//for vector sorting
	bool			operator < (Plan plan) const {
		if (this->year == plan.year) {
			if (this->month == plan.month) {
				if (this->day == plan.day)
					return (this->meal_type < plan.meal_type);
				else
					return (this->day < plan.day);
			}
			else
				return (this->month < plan.month);
		}
		else
			return (this->year < plan.year);
	}
};

#endif
