#include"plan.h"

using namespace std;

/*
Plan Class

-Control Menu, Date, Meal Type

*/

Plan::Plan() {
}



Plan::Plan(int _year, int _month, int _day, Meal& _menu, int _meal_type) {

	//Handling exception from Date Class
	try {
		date = Date(_year, _month, _day, "");
	}
	catch (out_of_range e)
	{
		cout << "Error	: Can not construct date instance. Check parameter!";
	}

	menu = _menu;
	meal_type = _meal_type;
}
Plan::~Plan() {

}

//Getter and Setter of Private Value;

Date Plan::getDate() {
	return date;
}

void Plan::setDate(Date& _date) {
	date = _date;
}

void Plan::setDate(int _year, int _month, int _day) {
	date = Date(_year, _month, _day, "");
}

Meal Plan::getMenu() {
	return menu;
}

void Plan::setMenu(Meal& _menu) {
	menu = _menu;
}

int Plan::getMealType() {
	return meal_type;
}

void Plan::setMealType(int _meal_type) {
	meal_type = _meal_type;
}


//Show plan

void Plan::showPlan() {
	string year = to_string(date.getYear());
	string month = (date.getMonth() < 10) ? "0" + to_string(date.getMonth()) : to_string(date.getMonth());
	string day = (date.getDay() < 10) ? "0" + to_string(date.getDay()) : to_string(date.getDay());

	cout << "Date	:" + year + "/" + month + "/" + day + "\n";
	switch (meal_type) {
	case 1:
		cout << "Meal Type	: Breakfast\n";
		break;
	case 2:
		cout << "Meal Type	: Lunch\n";
		break;
	case 3:
		cout << "Meal Type	: Dinner\n";
		break;
	case 4:
		cout << "Meal Type	: Snack\n";
		break;
	case 5:
		cout << "Meal Type	: Late-Night Snack\n";
		break;
	defalut:
		cout << "Meal Type	: Unknown\n";
		break;
	}
	menu.showMeal();
}

