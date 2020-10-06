#include "../includes/planManager.h"

using namespace std;

PlanManager::PlanManager() { }

PlanManager::~PlanManager() { }

// 새로운 플랜을 planData에 추가
void		PlanManager::addPlan(Plan planToAdd) {
	int		idx;
	Plan	temp;

	idx = 0;
	// 날짜가 덮어씌워지는 것을 방지
	while (idx < planData.size()) {
		temp = planData[idx];
		if (temp.comparePlan(planToAdd) == true) {
			cout << "You already have a plan at that time." << endl;
			return ;
		}
		idx++;
	}
	// 덮어씌워지지 않는 경우 새로운 플랜을 vector에 추가
	planData.push_back(planToAdd);
}

// 특정 plan을 planData에서 삭제 (월, 일, 식사타입으로 검색 후 삭제)
	void	PlanManager::deletePlan(int _year, int _month, int _day, int _meal_type) {
	int		idx;

	idx = 0;
	// 일치하는 plan이 있을 경우 삭제
	while (idx < planData.size()) {
		if (planData[idx].comparePlan(_year, _month, _day, _meal_type) == true) {
			planData.erase(planData.begin() + idx);
			return ;
		}
		idx++;
	}
	// 일치하는 plan이 없을 경우
	cout << "No matching Plans" << endl;
	return ;
}

// plan Meal 수정 (플랜 전체를 삭제하고 새로 수정)
void		PlanManager::reviseMeal(int _year, int _month, int _day, int _meal_type) {
	Plan	planToRevise;

	deletePlan(_year, _month, _day, _meal_type);
	planToRevise.renewMeal(_year, _month, _day, _meal_type); //plan클래스
	addPlan(planToRevise);
	return ;
}

void		PlanManager::reviseYear(int _year, int _month, int _day, int _meal_type) {
	Plan	planToRevise;

	deletePlan(_year, _month, _day, _meal_type);
	planToRevise.renewYear(_year, _month, _day, _meal_type); //plan클래스
	addPlan(planToRevise);
	return ;
}

void		PlanManager::reviseMonth(int _year, int _month, int _day, int _meal_type) {
	Plan	planToRevise;

	deletePlan(_year, _month, _day, _meal_type);
	planToRevise.renewMonth(_year, _month, _day, _meal_type); //plan클래스
	addPlan(planToRevise);
	return ;
}

void		PlanManager::reviseDay(int _year, int _month, int _day, int _meal_type) {
	Plan	planToRevise;

	deletePlan(_year, _month, _day, _meal_type);
	planToRevise.renewDay(_year, _month, _day, _meal_type); //plan클래스
	addPlan(planToRevise);
	return ;
}

void		PlanManager::reviseMealType(int _year, int _month, int _day, int _meal_type) {
	Plan	planToRevise;

	deletePlan(_year, _month, _day, _meal_type);
	planToRevise.renewMealType(_year, _month, _day, _meal_type); //plan클래스
	addPlan(planToRevise);
	return ;
}

// 모든 plan들을 sort작업을 진행한 후 보여주기.
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

// 특정 plan을 검색하여 보여주기
void		PlanManager::showSpecificPlan(int _year, int _month, int _day, int _meal_type) {
	int		idx;

	idx = 0;
	while (idx < planData.size()) {
		if (planData[idx].comparePlan(_year, _month, _day, _meal_type) == true) {
			planData[idx].showPlan();
			return ;
		}
		idx++;
		cout << "No matching Plans" << endl;
		return ;
	}
}
