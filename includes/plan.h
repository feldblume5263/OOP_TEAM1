#pragma once
#ifndef PLAN_H
# define PLAN_H

#include "iikh.hpp"
#include "meal.h"
#include "date.h"

using namespace std;

class				Plan
{
private:

	Meal			meal;
	int				meal_type;
	Date			date;

public:
	// TODO : Make to vector
	



	int				year;
	int				month;
	int				day;
	Plan();
	Plan(Date date);
	Plan(int _year, int _month, int _day, string  _comments, Meal& _meal, int _meal_type);
	
	~Plan();

	Date getDate();
	void			setDate(Date& _date);
	void			setDate(int _year, int _month, int _day, string _comment);
	Meal			getMeal();
	void			setMeal(Meal _meal);
	int				getMealType();
	void			setMealType(int _meal_type);
	bool			comparePlan(int _year, int _month, int _day, int _meal_type);
	bool			comparePlan(Plan plan);
	void			showPlan();

	//for vector sorting
	bool			operator < (const Plan& plan) const {
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
