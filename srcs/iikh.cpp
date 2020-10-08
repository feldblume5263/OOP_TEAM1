#include "../includes/iikh.hpp"

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

void enterDate(int* _year, int* _month, int* _day) {
	string s_year;
	string s_month;
	string s_day;
	cout << "Enter year:";
	getline(cin, s_year);
	*_year = atoi(s_year.c_str());
	cout << "Enter month:";
	getline(cin, s_month);
	*_month = atoi(s_month.c_str());
	cout << "Enter day:";
	getline(cin, s_month);
	*_day = atoi(s_month.c_str());
}
bool checkDate(int _year, int _month, int _day) {
	if (_year <= 0) {
		cout << "Invalid Year" << endl;
		return false;
	}
	else {
		if (_month > 12 || _month < 0) {
			cout << "Invalid Month" << endl;
			return false;
		}
		else {
			switch (_month) {
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				if (_day > 31 || _day <= 0) {
					cout << "Invalid Day" << endl;

					return false;
				}
				break;
			case 4: case 6: case 9: case 11:
				if (_day > 30 || _day <= 0) {
					cout << "Invalid Day" << endl;

					return false;
				}
				break;
			case 2:
				if (_day > 28 || _day <= 0) {
					cout << "Invalid Day" << endl;

					return false;
				}
				break;
			}
		}
	}
	return true;
}
