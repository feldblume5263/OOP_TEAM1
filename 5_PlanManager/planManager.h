#ifndef PLANMANAGER_H
# define PLANMANAGER_H

//# include "plan.h"
# include <iostream>
# include <vector>
# include <algorithm>
# include <cstring>
# include <ctime>

using namespace std;

class				Plan
{
private:
	int				month;
	int				day;
	string			meal;
	int				meal_type;

public:
	Plan(int _month = 0, int _day = 0, string _meal = "", int _meal_type = 0)
	{
		this->month = _month;
		this->day = _day;
		this->meal = _meal;
		this->meal_type = _meal_type;
	}

	void			makePlan() {}
	bool			findPlan(int _month, int _day, int _meal_type)
	{
		if (month == _month && day == _day && meal_type == _meal_type)
			return (true);
		return (false);
	}
	void			printPlan()
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
	bool			operator < (Plan plan) const
	{
		if (this->month == plan.month)
		{
			if (this->day == plan.day)
				return (this->meal_type < plan.meal_type);
			else
				return (this->day < plan.day);
		}
		else
			return (this->month < plan.month);

	}
};

class				PlanManger
{
private:
	vector<Plan>	plan_array;

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
