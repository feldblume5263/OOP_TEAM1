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
	Date			date;
	int				year;
	int				month;
	int				day;

public:
	Plan(int _year, int _month, int _day, Meal& _menu, int _meal_type);
	Plan();
	~Plan();

	Date*			getDate();
	void			setDate(Date& _date);
	void			setDate(int _year, int _month, int _day,string _comment);
	Meal			getMenu();
	void			setMenu(Meal& _menu);
	int				getMealType();
	void			setMealType(int _meal_type);
	bool			comparePlan(int _year, int _month, int _day, int _meal_type);
	bool			comparePlan(Plan plan);
	void			showPlan();

	void			makePlan() { }; // ?Œëœ??ì²˜ìŒë¶€??ë§Œë“œ???¤ë¸Œ?íŠ¸

	// ?Œëœ??ë¹„êµ?????°ì„ ?œìœ„ë¥??œê³µ?˜ê¸° ?„í•œ ?°ì‚°??
	bool			operator < (Plan plan) const {
		if (this->getDate().getYear() == plan.getDate().getYear()) {
			if (this->getDate().getMonth() == plan.getDate().getMonth()) {
				if (this->getDate().getDay() == plan.getDate().getDay())
					return (this->meal_type < plan.meal_type);
				else
					return (this->getDate().getDay() < plan.getDate().getDay());
			}
			else
				return (this->getDate().getMonth() < plan.getDate().getMonth());
		}
		else
			return (this->getDate().getYear() < plan.getDate().getYear());
	}
};

#endif
