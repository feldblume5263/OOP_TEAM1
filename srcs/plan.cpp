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

// plan을 출력하기 위한 오브젝트
void			Plan::showPlan() {
	string		s_year = to_string(date.getYear());
	string		s_month = date.getMonth() < 10 ? "0" + to_string(date.getMonth()) : to_string(date.getMonth());
	string 		s_day = (date.getDay() < 10) ? "0" + to_string(date.getDay()) : to_string(date.getDay());
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
		meal_label == "Late Night Snack";
	else
		meal_label = "unknown";
	cout << s_month << " / " << s_day << " / " << meal_label << endl;
	menu.showMeal();
	cout << endl;
	return ;
}

// 특정 plan을 찾기 위한 오브젝트
bool			Plan::comparePlan(int _year, int _month, int _day, int _meal_type) {
	if (this->date.getYear() == _year, this->date.getMonth() == _month && this->date.getDay() == _day && meal_type == _meal_type)
		return (true);
	return (false);
}

// plan을 서로 비교하기 위한 오브젝트
bool			Plan::comparePlan(Plan plan) {
	if (plan.date.getMonth() == date.getMonth() && plan.date.getDay() == date.getDay() && plan.meal_type == meal_type)
		return (true);
	return (false);
}
