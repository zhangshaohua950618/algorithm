/*
ID:    zhangsh35
PROG:    friday
LANG:    C++
*/
#include<fstream>
using namespace std ;
int week[8] ;
int totYear , year , month ;
int isLeapYear( int year ){
	return (( year % 400 == 0 )|| ( year % 4 == 0 && year % 100 )) ? 1 : 0 ;
}
int Month[13] = { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31  } ;
int thisMonth ;
ifstream cin("friday.in") ;
ofstream cout("friday.out") ;
int main(){
	int i ;
	cin >> totYear ;
	thisMonth = 6 ;
	for( year = 1900 ; year < 1900 + totYear ; year++ ){
		Month[2] = 28 + isLeapYear(year) ;
		for( month = 1 ; month <= 12 ; month++ ){
			week[thisMonth]++ ;
			thisMonth = (Month[month] % 7 + thisMonth)  % 7 ;
		}
	}
	cout << week[6] << " ";
	for( i = 0 ; i < 5 ; i++ )
	cout << week[i] << " ";
	cout << week[i] << endl ;
	return 0 ;
}
