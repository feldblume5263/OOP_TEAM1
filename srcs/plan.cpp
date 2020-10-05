#include "../includes/plan.h"

using namespace std;

/*
Plan Class

-Control Menu, Date, Meal Type

*/

Plan::Plan(int _year, int _month, int _day, Meal& _menu, int _meal_type) {

	//Handling exception from Date Class
	try {
		date = Date(_year, _month, _day, "");
	}
	catch (out_of_range e) {
		cout << "Error	: Can not construct date instance. Check parameter!";
	}
	menu = _menu;
	meal_type = _meal_type;
}

Plan::~Plan() { }

//Getter and Setter of Private Value;

Date			Plan::getDate() {
	return (date);
}

void			Plan::setDate(Date& _date) {
	date = _date;
}

void			Plan::setDate(int _year, int _month, int _day) {
	date = Date(_month, _year, _day, "");
}

Meal			Plan::getMenu() {
	return (menu);
}

void			Plan::setMenu(Meal& _menu) {
	menu = _menu;
}

int				Plan::getMealType() {
	return (meal_type);
}

void			Plan::setMealType(int _meal_type) {
	meal_type = _meal_type;
}
