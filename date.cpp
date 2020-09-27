#include<iostream>
#include"date.h"
Date::Date() {
	month = 0;
	day = 0;
	comment = "";
}
Date::Date(int _month, int _day, string _comment) {
	if (_month > 12 || _month <= 0) {
		throw out_of_range("Check Month Argument");
	}
	else{
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
int Date::get_month() {
	return month;
}
void Date::set_month(int _month) {
	if (_month > 12 || _month <= 0) {
		throw out_of_range("Check Month Argument");
	}
	else {
		month = _month;
	}
}
int Date::get_day() {

}
void Date::set_day(int _day) {
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
string Date::get_comment() {
	return comment;
}
void Date::set_comment(string _comment) {
	comment = _comment;
}