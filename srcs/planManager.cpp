#include "../includes/planManager.h"

using namespace std;

PlanManager::PlanManager() { }

PlanManager::~PlanManager() { }

// ?�로???�랜??planData??추�?
void		PlanManager::addPlan(Plan planToAdd) {
	// ?�짜가 ??��?�워지??것을 방�?
	if ((searchPlan(planToAdd))) {
		cout << "plan already exists at that time." << endl;
		return ;
	}
	// ??��?�워지지 ?�는 경우 ?�로???�랜??vector??추�?
	planData.push_back(planToAdd);
}

// ?�정 plan??planData?�서 ??�� (?? ?? ?�사?�?�으�?검??????��)
	void	PlanManager::deletePlan(int _year, int _month, int _day, int _meal_type) {
	int		idx;

	idx = 0;
	// ?�치?�는 plan???�을 경우 ??��
	while (idx < planData.size()) {
		if (planData[idx].comparePlan(_year, _month, _day, _meal_type) == true) {
			planData.erase(planData.begin() + idx);
			return ;
		}
		idx++;
	}
	// ?�치?�는 plan???�을 경우
	cout << "No matching Plans" << endl;
	return ;
}

// plan Meal?�정
void		PlanManager::reviseMeal(int _year, int _month, int _day, int _meal_type) {
	Meal		newMeal;
	Plan* temp = searchPlan(_year, _month, _day, _meal_type);
	if (!temp)
	{
		cout << "No matching Plans" << endl;
		return ;
	}
	newMeal.get_meals(); // Greeter
	temp->setMenu(newMeal);

	return ;
}

void		PlanManager::reviseYear(int _year, int _month, int _day, int _meal_type) {

	int			newYear;

	newYear = 0;
	Plan* temp = searchPlan(_year, _month, _day, _meal_type);
	if (!temp)
	{
		cout << "No matching Plans" << endl;
		return ;
	}
	cout << "Please enter a new year" << endl;
	cin >> newYear;
	Temp->getDate()->setYear(newYear);

	return ;
}

void		PlanManager::reviseMonth(int _year, int _month, int _day, int _meal_type) {

	int			newMonth;

	newMonth = 0;
	Plan* temp = searchPlan(_year, _month, _day, _meal_type);
	if (!temp)
	{
		cout << "No matching Plans" << endl;
		return ;
	}
	cout << "Please enter a new Month" << endl;
	cin >> newMonth;
	temp->getDate()->setMonth(newMonth);
	
	return ;
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
		return ;
	}
	cout << "Please enter a new Meal" << endl;
	cin >> newMealType;
	temp->getDate()->setMonth(newMealType);

	return ;
}

// 모든 plan?�을 sort?�업??진행????보여주기.
void		PlanManager::showAllPlan() {
	int		idx;

	sort(planData.begin(), planData.end());
	idx = 0;
	while (idx < planData.size()) {
		planData[idx].showPlan();
		idx++;
	}
	return ;
}

// ?�정 plan??검?�하??보여주기
void		PlanManager::showSpecificPlan(int _year, int _month, int _day, int _meal_type) {
	int		idx;

	idx = 0;
	if (searchPlan(_year, _month, _day, _meal_type)) {
		searchPlan(_year, _month, _day, _meal_type)->showPlan();
	}
	else {
		cout << "No matching Plans" << endl;
		return ;
	}
}

Plan		*PlanManager::searchPlan(int _year, int _month, int _day, int _meal_type) {
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

Plan		*PlanManager::searchPlan(Plan plan) {
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
