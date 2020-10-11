#pragma once

#ifndef PLANMANAGER_H
# define PLANMANAGER_H
# include "iikh.hpp"
#include "plan.h"

using namespace std;

class				PlanManager 
{
private:
	vector<Plan>	planData;

public:
	PlanManager();
	~PlanManager();


	void			addPlan(Plan planToAdd);


	void			deletePlan(int _year, int _month, int _day, int _meal_type);


	void			reviseMeal(int _year, int _month, int _day, int _meal_type, Meal& meal);

	void			reviseDate(int _year, int _month, int _day, int _meal_type);
	void			reviseMealType(int _year, int _month, int _day, int _meal_type);

	Plan* 			searchPlan(int _year, int _month, int _day, int _meal_type);
	Plan* 			searchPlan(Plan plan);
	vector<Plan> 	searchPlan(const Date& start, const Date& end);
	
	void			showIngredientsForPeriods(vector<Plan> plans);
	void			showSpecificPlan(int _year, int _month, int _day, int _meal_type);
	void			showAllPlan();



};

#endif
