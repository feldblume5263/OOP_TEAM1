#ifndef PLANMANAGER_H
# define PLANMANAGER_H

# include "plan.h"
# include <iostream>
# include <vector>
# include <algorithm>
# include <cstring>
# include <ctime>

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
	void			revisePlan(int _year, int _month, int _day, int _meal_type);
	void			showPlan();
	void			showAllMeal();
	bool			findPlan(Plan planToFind, int _month, int _day, int _meal_type);
};

#endif
