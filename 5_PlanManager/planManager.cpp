#include "planManager.h"

using namespace std;

PlanManger::PlanManger()
{
}

PlanManger::~PlanManger()
{
}

void	PlanManger::addPlan(Plan planToAdd)
{
	plan_array.push_back(planToAdd);
}

void	PlanManger::deletePlan(int _month, int _day, int _meal_type)
{
	int		idx;

	idx = 0;
	while (idx < plan_array.size())
	{
		if (plan_array[idx].findPlan(_month, _day, _meal_type) == true)
		{
			plan_array.erase(plan_array.begin() + idx);
			return ;
		}
		idx++;
	}
	cout << "No matching Plans" << endl;
	return ;
}

void	PlanManger::revisePlan(int _month, int _day, int _meal_type)
{
	Plan	planToRevise;

	deletePlan(_month, _day, _meal_type);
	planToRevise.makePlan(); //plan클래스에서 plan만드는 단계
	addPlan(planToRevise);
}

void	PlanManger::showAllMeal()
{
	int		idx;

	sort(plan_array.begin(), plan_array.end());
	idx = 0;
	while (idx < plan_array.size())
	{
		plan_array[idx].printPlan();
		idx++;
	}
	return ;
}

int		main(void)
{
	Plan	plan1(7, 21, "hamburger", 2);
	Plan	plan2(1, 7, "chicken", 1);
	Plan	plan3(4, 12, "cake", 3);
	Plan	plan4(4, 12, "rice", 1);
	Plan	plan5(4, 12, "chicken", 2);

	PlanManger plan_data;
	plan_data.addPlan(plan1);
	plan_data.addPlan(plan2);
	plan_data.addPlan(plan3);
	plan_data.addPlan(plan4);
	plan_data.addPlan(plan5);
	cout << "<before delete>" << endl;
	plan_data.showAllMeal();
	plan_data.deletePlan(7, 21, 2);
	cout << "<after delete>" << endl;
	plan_data.showAllMeal();
	return (0);
}
