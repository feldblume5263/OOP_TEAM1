#include<iostream>
#include"plan.h"


using namespace std;

Plan::Plan() {
}

Plan::Plan(Date& _date, Meal& _menu, int _meal_type) {
	date = _date;
	menu = _menu;
	meal_type = _meal_type;
}
Plan::~Plan() {

}
Date Plan::get_date() {
	return date;
}
void Plan::set_date(Date&_date) {
	date = _date;
}
Meal Plan::get_menu() {
	return menu;
}
void Plan::set_menu(Meal& _menu) {
	menu = _menu;
}
int Plan::get_meal_type() {
	return meal_type;
}
void Plan::set_meal_type(int _meal_type) {
	meal_type = _meal_type;
}
void Plan::ShowPlan() {
	
	string month = (date.get_month() < 10) ? "0" + to_string(date.get_month()) : to_string(date.get_month());
	string day=(date.get_day() < 10) ? "0" + to_string(date.get_day()) : to_string(date.get_day());

	cout << "Date:" + month + "-" + day + "\n";
	switch (meal_type) {
	case 1:
		cout << "Meal Type: Breakfast\n";
		break;
	case 2:
		cout << "Meal Type: Lunch\n";
		break;
	case 3:
		cout << "Meal Type: Dinner\n";
		break;
	case 4:
		cout << "Meal Type: Snack\n";
		break;
	case 5:
		cout << "Meal Type: Late-Night Snack\n";
		break;
	}
	menu.ShowMeal();
	}
	
