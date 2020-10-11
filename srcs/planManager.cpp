#include "../includes/planManager.h"

using namespace std;

PlanManager::PlanManager() { }

PlanManager::~PlanManager() { 
	/*for(auto& plan: planData) {
		delete plan.getMeal();
		delete plan.getDate();
	}*/
}

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
	//No Pplan
	cout << "No matching Plans" << endl;
	return;
}


void		PlanManager::reviseMeal(int _year, int _month, int _day, int _meal_type, Meal& meal) {
	Meal		newMeal = meal;
	Plan* temp = searchPlan(_year, _month, _day, _meal_type);
	if (!temp)
	{
		cout << "No matching Plans" << endl;
		return;
	}
	system("clear");
	// Greeter
	temp->setMeal(&newMeal);

	return;
}

/*void		PlanManager::reviseYear(int _year, int _month, int _day, int _meal_type) {

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
	temp->getDate()->setYear(newYear);
	temp->year = newYear;
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
	temp->month = newMonth;

	return ;
}*/

void		PlanManager::reviseDate(int _year, int _month, int _day, int _meal_type) {
	int			newYear;
	int			newMonth;
	int			newDay;

	newDay = 0;
	Plan* temp = searchPlan(_year, _month, _day, _meal_type);
	if (!temp)
	{
		cout << "No matching Plans" << endl;
		return;
	}
	while (true) {
		enterDate(&newYear, &newMonth, &newDay);
		if (checkDate(newYear, newMonth, newDay)) {
			break;
		}
	}


	temp->getDate()->setYear(newYear);
	temp->year = newYear;
	temp->getDate()->setMonth(newMonth);
	temp->month = newMonth;
	temp->getDate()->setDay(newDay);
	temp->day = newDay;


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
		}
	//cout << "No matching Plans" << endl;
	return (NULL);
}



Plan* PlanManager::searchPlan(Plan plan) {
	int		idx;

	idx = 0;
	while (idx < planData.size()) {
		if (planData[idx].comparePlan(plan) == true) {
			return (&(planData[idx]));
		}
		idx++;
	}
	return (NULL);
}

vector<Plan> PlanManager::searchPlan(const Date& begin, const Date& end) {
	vector<Plan> ret;
	vector<Plan> sorted_plans = planData;
	// sort by date and meal_type
	sort(sorted_plans.begin(), sorted_plans.end());
	
	// for lower_bound searching, setting the meal type as 0, which is the lowest number of it
	Plan begin_keyword = Plan(begin); 	begin_keyword.setMealType(0);
	// for lower_bound searching, setting the meal type as 10, which is greater than the highest meal type arrangment.
	// then, lower_bound function will return the Plan iterator that is next to the end Date
	Plan end_keyword = Plan(end);		end_keyword.setMealType(10);
	int begin_idx = lower_bound(sorted_plans.begin(), sorted_plans.end(), begin_keyword) - sorted_plans.begin();
	int end_idx = lower_bound(sorted_plans.begin(), sorted_plans.end(), end_keyword) - sorted_plans.begin() - 1;	// we will not contain the iterator of next day 

	ret.assign( sorted_plans.begin() + begin_idx, sorted_plans.end() + end_idx );
	return ret;
}


void PlanManager::showIngredientsForPeriods(vector<Plan> plans) {
	vector<string> ingredients;
    unordered_map<string, int> required_ingredients;

    for (Plan plan: plans)
    {
		vector<Serving> servings = plan.getMeal()->getServings();
        for (Serving serving : servings)
        {
			Recipe recipe = serving.menus;
            for(Ingredient ingredient: recipe.getIngredients()) 
			{
				string ingredient_name = ingredient.getName();
				int ingredient_weight = stoi(ingredient.getWeight()) * serving.num_of_people;

				if(!required_ingredients.count(ingredient_name))
				{
					required_ingredients[ingredient_name] = ingredient_weight;
					ingredients.push_back(ingredient_name);
				}
				else
				{
					required_ingredients[ingredient_name] += ingredient_weight;
				}
			}
        }
    }

    cout << "---------------------" << endl;
    cout << "| Required Ingredients for periods |" << endl;

    for(string ingredient_name: ingredients) {
        cout << "| " <<  ingredient_name << ", " << required_ingredients[ingredient_name] << " |" << endl;
    }

    cout << "---------------------\n" << endl;
}
