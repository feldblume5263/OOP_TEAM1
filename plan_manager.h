#ifndef PLAN_MANAGER_H
#define PLAN_MANAGER_H
#include"plan.h"
using namespace std;

class PlanManager {
private:
	vector<Plan> plan_list;
public:
	PlanManager();
	~PlanManager();
	void AddPlan();
	void DeletePlan();
	void RevisePlan();
	void Show_All_Plan();
	Plan get_a_plan(int _month,int _day, int _meal_type);
};


#endif