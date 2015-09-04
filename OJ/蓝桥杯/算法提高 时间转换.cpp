#include<iostream>
using namespace std;
int num,day,hour, minute ;
int main(){
	cin >> num;
	day = num / (24 * 60);
	num %= 24 * 60;
	hour = num / 60;
	num %= 60;
	minute = num; 
	cout << day << " " << hour << " " << minute << endl;
	return 0;
}
