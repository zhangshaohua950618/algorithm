/*
ID:    zhangsh35
PROG:    milk2
LANG:    C++
*/
#include<fstream>
using namespace std ;
int totFarmer , start , end , maxOn , maxOff , maxTime , minTime = 0x7fffffff , currentTimeOn , currentTimeOff;
bool milk[1000000 + 10] ;
int main(){
	ifstream cin("milk2.in") ;
	ofstream cout("milk2.out") ;
	int i  , j ;
	cin >> totFarmer ;
	for( i = 1 ; i <= totFarmer ; i++ ){
		cin >> start >> end ;
		if( start < minTime)
		minTime = start ;
		if( end > maxTime )
		maxTime = end ;
		for( j = start + 1 ; j <= end ; j++ )
		milk[j] = true ;
	}
//	cout << minTime << " " << maxTime << endl ;
	for( i = minTime + 1 ; i <= maxTime ; i++ ){
	//	cout << " i = " << i << " " << milk[i] << endl ;
		if(milk[i]){
			if( currentTimeOff > maxOff )
				maxOff = currentTimeOff ;
				currentTimeOff = 0 ;
				currentTimeOn++ ;
		}
		else{
			if( currentTimeOn > maxOn )
				maxOn = currentTimeOn ;
				currentTimeOn = 0 ;
				currentTimeOff++ ;
		}
	}
	if( currentTimeOff > maxOff ){
			maxOff = currentTimeOff ;
		}
	if( currentTimeOn > maxOn ){
			maxOn = currentTimeOn ;
		}
	
	cout << maxOn << " " <<maxOff << endl ;
	return 0 ;
	
}
