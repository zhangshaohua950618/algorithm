/*
ID:		zhangsh35
PROG:	kimbits
LANG:	C++
*/
#include<iostream>
#include<fstream>
using namespace std ;
long long totBit , maxOne , num ;
bool result[30 + 5] ;
long long number[40][40] ;
long long Cnk( long n , long k ){
	long i ;
	if( k > n / 2 )
	k = n - k ;
	long long sum = 1 , temp = 1 ;
	for( i = 1 ; i <= k ; i++){
		temp *= i ;
		sum *= ( n - i + 1 ) ;
		if( sum % temp == 0 ){
			sum /= temp ;
			temp = 1 ;
		}
	}
	return sum ;
}
void GetNumber(){
	int  i , j ;
	for( i = 0 ; i <= 31 ; i++)
	for( j = 0 ; j <= i ; j++)
		number[i][j] = number[i][j - 1] + Cnk(i , j);
}
int main(){
	ifstream cin("kimbits.in") ;
	ofstream cout("kimbits.out") ;
	GetNumber() ;
	cin>>totBit>>maxOne>>num ;
	long i ;
	while( num != 0){
		for( i = 0 ; i <= totBit ; i++ ){
			int min = i < maxOne ? i : maxOne ;
			if(number[i][min] >= num){
				result[i] = true ;
				if(i == 0)
				num--;
				else{
					min = ( i - 1 )< maxOne ? ( i - 1 ) : maxOne ;
					num -=number[i - 1][min] ;
				}
				maxOne-- ;	
				break ;
			}
		}
	}
	for( i = totBit ; i >= 1 ; i--){
		cout<<result[i];
}
	cout<<endl;

}
