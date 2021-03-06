#include "../includes/date.h"

/*
Date Class

-Control Month, Day, Comment

*/

Date::Date() {
	year = 0;
	month = 0;
	day = 0;
	comment = "";
}

Date::Date(int _year, int _month, int _day, string _comment) {
	if (_year < 0) throw out_of_range("Check Year Argument");
	//Check Month Value
	if (_month > 12 || _month <= 0) {
		throw out_of_range("Check Month Argument");
	}
	//Check Day Value
	else {
		switch (_month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (_day > 31 || _day <= 0) {
				throw out_of_range("Check Day Argument");
				break;
			}
			break;
		case 4: case 6: case 9: case 11:
			if (_day > 30 || _day <= 0) {
				throw out_of_range("Check Day Argument");
				break;
			}
			break;
		case 2:
			if (_day > 28 || _day <= 0) {
				throw out_of_range("Check Day Argument");
				break;
			}
			break;
		}
	}
	year = _year;
	month = _month;
	day = _day;
	comment = _comment;
}

Date::~Date() { }

//Getter and Setter of Private Value

int				Date::getYear() {
	return (year);
}

void			Date::setYear(int _year) {
	year = _year;
}

int				Date::getMonth() {
	return (month);
}


void			Date::setMonth(int _month) {
	if (_month > 12 || _month <= 0) {
		throw out_of_range("Check Month Argument");
	}
	else {
		month = _month;
	}
}

int				Date::getDay() {
	return (day);
}


void			Date::setDay(int _day) {
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (_day > 31 || _day <= 0) {
			throw out_of_range("Check Day Argument");
			break;
		}
		break;
	case 4: case 6: case 9: case 11:
		if (_day > 30 || _day <= 0) {
			throw out_of_range("Check Day Argument");
			break;
		}
		break;
	case 2:
		if (_day > 28 || _day <= 0) {
			throw out_of_range("Check Day Argument");
			break;
		}
		break;
	}
	day = _day;
}

string Date::getComment() {
	return (comment);
}


void Date::setComment(string _comment) {
	comment = _comment;
}
