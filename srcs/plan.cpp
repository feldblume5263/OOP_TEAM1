#include "../includes/plan.h"

using namespace std;

/*
Plan Class

-Control Menu, Date, Meal Type

*/

Plan::Plan() {
	date = Date();
	menu = Meal();

	year = 0;
	month = 0;
	day = 0;
};

Plan::Plan(int _year, int _month, int _day, string _comments, Meal& _menu, int _meal_type) {

	//Handling exception from Date Class
	try {
		date = Date(_year, _month, _day, _comments);
	}
	catch (out_of_range e) {
		cout << "Error	: Can not construct date instance. Check parameter!";
	}
	menu = _menu;
	meal_type = _meal_type;
	year = getDate()->getYear();
	month = getDate()->getMonth();
	day = getDate()->getDay();
}

Plan::~Plan() { }

//Getter and Setter of Private Value;

Date* Plan::getDate() {
	return &date;
}

void			Plan::setDate(Date& _date) {
	date = _date;
}

void			Plan::setDate(int _year, int _month, int _day, string _comment) {
	date = Date(_year, _month, _day, _comment);
}

Meal*			Plan::getMenu() {
	return &menu;
}

void			Plan::setMenu(Meal _menu) {
	menu = _menu;
}

int				Plan::getMealType() {
	return (meal_type);
}

void			Plan::setMealType(int _meal_type) {
	meal_type = _meal_type;
}


void			Plan::showPlan() {

	string		s_year = to_string(getDate()->getYear());
	string		s_month = getDate()->getMonth() < 10 ? "0" + to_string(getDate()->getMonth()) : to_string(getDate()->getMonth());
	string 		s_day = (getDate()->getDay() < 10) ? "0" + to_string(getDate()->getDay()) : to_string(getDate()->getDay());
	string		meal_label;

	if (meal_type == 1)
		meal_label = "Breakfast";
	else if (meal_type == 2)
		meal_label = "Lunch";
	else if (meal_type == 3)
		meal_label = "Dinner";
	else if (meal_type == 4)
		meal_label = "Snack";
	else if (meal_type == 5)
		meal_label = "Late Night Snack";
	else
		meal_label = "unknown";
	cout << s_year << " / " << s_month << " / " << s_day << " / " << meal_label << endl;
	

	//std::cout << "in plan name : " << *menu_name << "people : " << *numOfPeople << endl;

	std::cout << "in plan people : " << endl;
	std::cout << *(&numOfPeople) << endl;

	// cout << "name : " << menu. << " people : " << numOfPeople << endl;
	//std::cout << "in showplan :  "<<  menu.meals[0].num_of_people << endl;

	//menu.showMeal();
	cout << endl;
	return;
}

bool			Plan::comparePlan(int _year, int _month, int _day, int _meal_type) {
	if (this->date.getYear() == _year && this->date.getMonth() == _month && this->date.getDay() == _day && meal_type == _meal_type)
		return (true);
	return (false);
}


bool			Plan::comparePlan(Plan plan) {
	if (plan.date.getMonth() == date.getMonth() && plan.date.getDay() == date.getDay() && plan.meal_type == meal_type)
		return (true);
	return (false);
}
