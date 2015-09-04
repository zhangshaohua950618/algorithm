#include<iostream>
#include<stdio.h>
using namespace std;
int hour , minute , second;
int time , t;
int main(){
	int i;
	cin >> t;
	for(i = 0 ;i < t ; i++){
	cin >> time;
	hour = time / (60 * 60);
	time %= 60 * 60;
	minute = time  / 60;
	time %= 60;
	second = time;
	printf("%02d:%02d:%02d\n", hour , minute , second);
	}
	return 0;
		
} 
