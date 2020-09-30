#ifndef PLANMANAGER_H
# define PLANMANAGER_H

//# include "plan.h"
# include <iostream>
# include <vector>
# include <algorithm>
# include <cstring>

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
		month = _month;
		day = _day;
		meal = _meal;
		meal_type = _meal_type;
	}
	Plan() {}

	void			make_plan() {}
	bool			find_plan(int _month, int _day, int _meal_type)
	{
		if (month == _month && day == _day && meal_type == _meal_type)
			return (true);
		return (false);
	}
	void			print_plan()
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
};

class				PlanManger
{
private:
	vector<Plan>	plan_array;

public:
	PlanManger();
	~PlanManger();

	void			add_plan(Plan planToAdd);
	void			delete_plan(int _month, int _day, int _meal_type);
	void			revise_plan(int _month, int _day, int _meal_type);
	void			show_all_meal();
	bool			find_plan(Plan planToFind, int _month, int _day, int _meal_type);
};

#endif
