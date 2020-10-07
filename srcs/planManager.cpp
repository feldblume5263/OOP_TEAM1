#include "../includes/planManager.h"

using namespace std;

PlanManager::PlanManager() { }

PlanManager::~PlanManager() { }


void		PlanManager::addPlan(Plan planToAdd) {
	//Prevention from Overwriting
	if ((searchPlan(planToAdd))) {
		cout << "plan already exists at that time." << endl;
		return;
	}

	planData.push_back(planToAdd);
}


void	PlanManager::deletePlan(int _year, int _month, int _day, int _meal_type) {
	int		idx;

	idx = 0;
	//Case:There is the plan
	while (idx < planData.size()) {
		if (planData[idx].comparePlan(_year, _month, _day, _meal_type) == true) {
			planData.erase(planData.begin() + idx);
			return;
		}
		idx++;
	}
	// Case:No plan
	cout << "No matching Plans" << endl;
	return;
}


void		PlanManager::reviseMeal(int _year, int _month, int _day, int _meal_type) {
	Meal		newMeal;
	Plan* temp = searchPlan(_year, _month, _day, _meal_type);
	if (!temp)
	{
		cout << "No matching Plans" << endl;
		return;
	}
	newMeal.get_meals(); // Greeter
	temp->setMenu(newMeal);

	return;
}

void		PlanManager::reviseYear(int _year, int _month, int _day, int _meal_type) {

	int			newYear;

	newYear = 0;
	Plan* temp = searchPlan(_year, _month, _day, _meal_type);
	if (!temp)
	{
		cout << "No matching Plans" << endl;
		return;
	}
	cout << "Please enter a new year" << endl;
	cin >> newYear;
	temp->getDate()->setYear(newYear);

	return;
}

void		PlanManager::reviseMonth(int _year, int _month, int _day, int _meal_type) {

	int			newMonth;

	newMonth = 0;
	Plan* temp = searchPlan(_year, _month, _day, _meal_type);
	if (!temp)
	{
		cout << "No matching Plans" << endl;
		return;
	}
	cout << "Please enter a new Month" << endl;
	cin >> newMonth;
	temp->getDate()->setMonth(newMonth);

	return;
}

void		PlanManager::reviseDay(int _year, int _month, int _day, int _meal_type) {

	int			newDay;

	newDay = 0;
	Plan* temp = searchPlan(_year, _month, _day, _meal_type);
	if (!temp)
	{
		cout << "No matching Plans" << endl;
		return;
	}
	cout << "Please enter a new Day" << endl;
	cin >> newDay;
	temp->getDate()->setDay(newDay);


	return;
}

void		PlanManager::reviseMealType(int _year, int _month, int _day, int _meal_type) {
	int			newMealType;

	newMealType = 0;
	Plan* temp = searchPlan(_year, _month, _day, _meal_type);
	if (!temp)
	{
		cout << "No matching Plans" << endl;
		return;
	}
	cout << "Please enter a new Meal" << endl;
	cin >> newMealType;
	temp->setMealType(newMealType);

	return;
}


void		PlanManager::showAllPlan() {
	int		idx;

	sort(planData.begin(), planData.end());
	idx = 0;
	while (idx < planData.size()) {
		planData[idx].showPlan();
		idx++;
	}
	return;
}


void		PlanManager::showSpecificPlan(int _year, int _month, int _day, int _meal_type) {
	int		idx;

	idx = 0;
	if (searchPlan(_year, _month, _day, _meal_type)) {
		searchPlan(_year, _month, _day, _meal_type)->showPlan();
	}
	else {
		cout << "No matching Plans" << endl;
		return;
	}
}

Plan* PlanManager::searchPlan(int _year, int _month, int _day, int _meal_type) {
	int		idx;

	idx = 0;
	while (idx < planData.size()) {
		if (planData[idx].comparePlan(_year, _month, _day, _meal_type) == true) {
			return (&(planData[idx]));
		}
		idx++;
		cout << "No matching Plans" << endl;
		return (NULL);
	}
}

Plan* PlanManager::searchPlan(Plan plan) {
	int		idx;

	idx = 0;
	while (idx < planData.size()) {
		if (planData[idx].comparePlan(plan) == true) {
			return (&(planData[idx]));
		}
		idx++;
		return (NULL);
	}
}
