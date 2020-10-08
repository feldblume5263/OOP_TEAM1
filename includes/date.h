#pragma once
#ifndef DATE_H
# define DATE_H

#include "iikh.hpp"

using namespace std;

class			Date
{
private:
	int			year;
	int			month;
	int			day;
	string		comment;

public:
	Date();
	Date(int _year, int _month, int _day, string _comment);
	~Date();

	int			getYear();
	void		setYear(int _year);
	int			getMonth();
	void		setMonth(int _month);
	int			getDay();
	void		setDay(int _day);
	string		getComment();
	void		setComment(string _comment);
};



#endif
