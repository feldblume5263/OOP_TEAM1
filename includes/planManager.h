#ifndef PLANMANAGER_H
# define PLANMANAGER_H
#include "plan.h"
#include "iikh.hpp"

using namespace std;

class				PlanManager : Plan
{
private:
	vector<Plan>	planData;

public:
	PlanManager();
	~PlanManager();

	// 만들어진 플랜을 Data에 추가
	void			addPlan(Plan planToAdd);

	// 연,월,일,식사로 검색하여, Data에서 특정 plan 삭제
	void			deletePlan(int _year, int _month, int _day, int _meal_type);

// 플랜 수정단계
	// 플랜
	void			reviseMeal(int _year, int _month, int _day, int _meal_type);
	void			reviseYear(int _year, int _month, int _day, int _meal_type);
	void			reviseMonth(int _year, int _month, int _day, int _meal_type);
	void			reviseDay(int _year, int _month, int _day, int _meal_type);
	void			reviseMealType(int _year, int _month, int _day, int _meal_type);


	bool			findPlan(Plan planToFind, int _month, int _day, int _meal_type);

	void			showSpecificPlan(int _year, int _month, int _day, int _meal_type);
	void			showAllPlan();



};

#endif
