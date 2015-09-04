#include<iostream>
#include<csdlib>
using namespace std;
int year , mon , day;
bool bigger;
int days[] = {5 , 6 , 7 , 1 , 2 ,3 ,4};
int MON = {};
bool IsLeapYear(int year){
	return !(year % 400) || (year % 4 == 0) && year % 100 != 0;
}
bool Judge(){
	if(year != 2011)
	return year > 2011;
	if(mon != 11)
	return mon > 11;
	if(day != 11)
	return day > 11;
}

int GetDiff(){
}
int main(){
	cin >> year >> mon >> day;
	bigger = Judge();
	diff = GetDiff();
	result = bigger ? days[diff] : days[7 - diff];
	cout << result << endl;
	return 0;
}

