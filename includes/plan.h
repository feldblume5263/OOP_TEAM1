#ifndef PLAN_H
# define PLAN_H
#include "plan.h"
#include "meal.h"
#include "date.h"
#include "iikh.hpp"

using namespace std;

class				Plan
{
protected:
	Meal			menu;
	int				meal_type;

public:
	Date			date;
	Plan(int _year, int _month, int _day, Meal& _menu, int _meal_type);
	Plan();
	~Plan();

	Date			getDate();
	void			setDate(Date& _date);
	void			setDate(int _year, int _month, int month);
	Meal			getMenu();
	void			setMenu(Meal& _menu);
	int				getMealType();
	void			setMealType(int _meal_type);
	bool			comparePlan(int _year, int _month, int _day, int _meal_type);
	bool			comparePlan(Plan plan);
	void			showPlan();

	void			makePlan() { }; // 플랜을 처음부터 만드는 오브젝트

	// 플랜을 비교할 때 우선순위를 제공하기 위한 연산자
	bool			operator < (Plan plan) {
		if (this-> date.getYear() == plan.date.getYear()) {
			if (this->date.getMonth() == plan.date.getMonth()) {
				if (this->date.getDay() == plan.date.getDay())
					return (this->meal_type < plan.meal_type);
				else
					return (this->date.getDay() < plan.date.getDay());
			}
			else
				return (this->date.getMonth() < plan.date.getMonth());
		}
		else
			return (this-> date.getYear() < plan.date.getYear());
	}
};

#endif
