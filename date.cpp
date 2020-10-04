#include"date.h"
/*
Date Class

-Control Month, Day, Comment

*/



Date::Date() {
	month = 0;
	day = 0;
	comment = "";
}
Date::Date(int _month, int _day, string _comment) {

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
		case 4: case 6: case 9: case 11:
			if (_day > 30 || _day <= 0) {
				throw out_of_range("Check Day Argument");
				break;
			}
		case 2:
			if (_day > 28 || _day <= 0) {
				throw out_of_range("Check Day Argument");
				break;
			}
		}
	}

	month = _month;
	day = _day;
	comment = _comment;


}


Date::~Date() {

}



//Getter and Setter of Private Value



int Date::getMonth() {
	return month;
}


void Date::setMonth(int _month) {
	if (_month > 12 || _month <= 0) {
		throw out_of_range("Check Month Argument");
	}
	else {
		month = _month;
	}
}
int Date::getDay() {
	return day;
}


void Date::setDay(int _day) {
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (_day > 31 || _day <= 0) {
			throw out_of_range("Check Day Argument");
			break;
		}
	case 4: case 6: case 9: case 11:
		if (_day > 30 || _day <= 0) {
			throw out_of_range("Check Day Argument");
			break;
		}
	case 2:
		if (_day > 28 || _day <= 0) {
			throw out_of_range("Check Day Argument");
			break;
		}
	}
	day = _day;
}


string Date::getComment() {
	return comment;
}


void Date::setComment(string _comment) {
	comment = _comment;
}