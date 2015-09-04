#include<iostream>
using namespace std;
int year , mon;
bool isLeapYear(int year){
	return (year % 400 == 0) ||(year % 4 == 0) && (year % 100 != 0);
}
int data[] = {0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 , 30};
int main(){
	printf("Calendar %d-%02d%" , year , mon);
	printf("---------------------");
	printf("Su Mo Tu We Th Fr Sa");
	printf("---------------------");
}
