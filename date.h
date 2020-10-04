#ifndef DATE_H
#define DATE_H
#include <stdexcept> 
#include<string>
using namespace std;

class Date {
private:
	int month;
	int day;
	string comment;
public:
	Date();
	Date(int _month, int _day, string _comment);
	~Date();
	int getMonth();
	void setMonth(int _month);
	int getDay();
	void setDay(int _day);
	string getComment();
	void setComment(string _comment);
};



#endif