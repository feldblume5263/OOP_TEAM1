#include "../includes/plan.h"

using namespace std;

/*
Plan Class

-Control Menu, Date, Meal Type

*/

Plan::Plan() {
	date = new Date();
	meal = new Meal();

	year = 0;
	month = 0;
	day = 0;
};

Plan::Plan(Date date) {
	year = date.getYear();
	month = date.getMonth();
	day = date.getDay();

	meal = new Meal();
}

Plan::Plan(int _year, int _month, int _day, string _comments, Meal& _meal, int _meal_type) {

	//Handling exception from Date Class
	try {
		date = new Date(_year, _month, _day, _comments);
	}
	catch (out_of_range e) {
		cout << "Error	: Can not construct date instance. Check parameter!";
	}
	meal = &_meal;
	meal_type = _meal_type;
	year = date->getYear();
	month = date->getMonth();
	day = date->getDay();
}

Plan::~Plan() { }

//Getter and Setter of Private Value;


Date* Plan::getDate() {
	return date;
}

void			Plan::setDate(Date* _date) {
	date = _date;
}

void			Plan::setDate(int _year, int _month, int _day, string _comment) {
	date = new Date(_year, _month, _day, _comment);
}

Meal*			Plan::getMeal() {
	return meal;
}

void			Plan::setMeal(Meal* _meal) {
	meal = _meal;
}

int				Plan::getMealType() {
	return (meal_type);
}

void			Plan::setMealType(int _meal_type) {
	meal_type = _meal_type;
}


void			Plan::showPlan() {

	string		s_year = to_string(date->getYear());
	string		s_month = date->getMonth() < 10 ? "0" + to_string(date->getMonth()) : to_string(date->getMonth());
	string 		s_day = (date->getDay() < 10) ? "0" + to_string(date->getDay()) : to_string(date->getDay());
	string		meal_label;
	string		s_comment = date->getComment();

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
	cout << "------------------------------------------------"<< endl;
	cout << s_year << " / " << s_month << " / " << s_day << " / " << meal_label << endl;
	cout << "Comment : " << s_comment << endl;	

	cout << endl << "-menu-" <<  endl;
	vector<Serving> servings = meal->getServings();
	for (int i = 0; i < servings.size(); i++) {
		std::cout << "Menu Name:	" << servings[i].menus.getName() << endl;
		std::cout << "Num of People:	" << servings[i].num_of_people << endl;
	}
	cout << endl;
	return;
}

bool			Plan::comparePlan(int _year, int _month, int _day, int _meal_type) {
	if (this->date->getYear() == _year && this->date->getMonth() == _month && this->date->getDay() == _day && meal_type == _meal_type)
		return (true);
	return (false);
}


bool			Plan::comparePlan(Plan plan) {
	if (plan.date->getMonth() == date->getMonth() && plan.date->getDay() == date->getDay() && plan.meal_type == meal_type)
		return (true);
	return (false);
}
