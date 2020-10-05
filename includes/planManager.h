#ifndef PLANMANAGER_H
# define PLANMANAGER_H

# include "plan.h"
# include <iostream>
# include <vector>
# include <algorithm>
# include <cstring>
# include <ctime>

using namespace std;

class				PlanManger
{
private:
	vector<Plan>	planData;

public:
	PlanManger();
	~PlanManger();

	void			addPlan(Plan planToAdd);
	void			deletePlan(int _month, int _day, int _meal_type);
	void			revisePlan(int _month, int _day, int _meal_type);
	void			showAllMeal();
	bool			findPlan(Plan planToFind, int _month, int _day, int _meal_type);
};

#endif
