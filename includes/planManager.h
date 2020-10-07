#ifndef PLANMANAGER_H
# define PLANMANAGER_H

# include "plan.h"
# include "iikh.hpp"

using namespace std;

class				PlanManager : Plan
{
private:
	vector<Plan>	planData;

public:
	PlanManager();
	~PlanManager();

	
	void			addPlan(Plan planToAdd);

	
	void			deletePlan(int _year, int _month, int _day, int _meal_type);


	void			reviseMeal(int _year, int _month, int _day, int _meal_type);
	void			reviseYear(int _year, int _month, int _day, int _meal_type);
	void			reviseMonth(int _year, int _month, int _day, int _meal_type);
	void			reviseDay(int _year, int _month, int _day, int _meal_type);
	void			reviseMealType(int _year, int _month, int _day, int _meal_type);

	Plan			*searchPlan(int _year, int _month, int _day, int _meal_type);
	Plan			*searchPlan(Plan plan);

	void			showSpecificPlan(int _year, int _month, int _day, int _meal_type);
	void			showAllPlan();



};

#endif
