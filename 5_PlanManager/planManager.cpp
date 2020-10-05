#include "planManager.h"

using namespace std;

PlanManger::PlanManger()
{
}

PlanManger::~PlanManger()
{
}

// 새로운 플랜을 planData에 추가
void		PlanManger::addPlan(Plan planToAdd)
{
	int		idx;
	Plan	temp;

	idx = 0;
	// 날짜가 덮어씌워지는 것을 방지
	while (idx < planData.size())
	{
		temp = planData[idx];
		if (temp.comparePlan(planToAdd) == true)
		{
			cout << "You already have a plan at that time." << endl;
			return ;
		}
		idx++;
	}
	// 덮어씌워지지 않는 경우 새로운 플랜을 vector에 추가
	planData.push_back(planToAdd);
}

// 특정 plan을 planData에서 삭제 (월, 일, 식사타입으로 검색 후 삭제)
	void	PlanManger::deletePlan(int _month, int _day, int _meal_type)
	{
	int		idx;

	idx = 0;
	// 일치하는 plan이 있을 경우 삭제
	while (idx < planData.size())
	{
		if (planData[idx].findPlan(_month, _day, _meal_type) == true)
		{
			planData.erase(planData.begin() + idx);
			return ;
		}
		idx++;
	}
	// 일치하는 plan이 없을 경우
	cout << "No matching Plans" << endl;
	return ;
}

// plan 수정 (월, 일 , 식사 타입을 입력하면, 검색하여 삭제 후, 새로운 추가 작업 진행)
void		PlanManger::revisePlan(int _month, int _day, int _meal_type)
{
	Plan	planToRevise;

	deletePlan(_month, _day, _meal_type);
	planToRevise.makePlan(); //plan클래스에서 plan만드는 단계
	addPlan(planToRevise);
}

// 모든 plan들을 sort작업을 진행한 후 표시함.
void		PlanManger::showAllMeal()
{
	int		idx;

	sort(planData.begin(), planData.end());
	idx = 0;
	while (idx < planData.size())
	{
		planData[idx].printPlan();
		idx++;
	}
	return ;
}

// 특정 plan을 찾기 위한 오브젝트
bool			Plan::findPlan(int _month, int _day, int _meal_type)
{
	if (month == _month && day == _day && meal_type == _meal_type)
		return (true);
	return (false);
}

// plan을 출력하기 위한 오브젝트
void			Plan::printPlan()
{
	string	meal_label;
	if (meal_type == 1)
		meal_label = "Breakfast";
	else if (meal_type == 2)
		meal_label = "Lunch";
	else if (meal_type == 3)
		meal_label = "Dinner";
	else
		meal_label = "unknown";
	cout << month << "/" << day << "/" << meal_label << endl;
	cout << meal << endl;
	cout << endl;
	return ;
}

// plan을 서로 비교하기 위한 오브젝트
bool			Plan::comparePlan(Plan plan)
{
	if (plan.month == month && plan.day == day && plan.meal_type == meal_type)
		return (true);
	return (false);
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
