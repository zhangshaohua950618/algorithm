/*
ID:		zhangsh35
PROG:	preface
LANG:	C++
*/
#include<iostream>
#include<fstream>
#include<map>
using namespace std ;
int f[4000][10] ;
int count[10] ;
map< int , char > m ;
void Initial(){
	int i ;
	m[0] = 'I' ;
	m[1] = 'V' ;
	m[2] = 'X' ;
	m[3] = 'L' ;
	m[4] = 'C' ;
	m[5] = 'D' ;
	m[6] = 'M' ;
	f[1][0] = 1 ;
	f[2][0] = 2 ;
	f[3][0] = 3 ;
	f[4][0] = 1 ; f[4][1] = 1 ;
				  f[5][1] = 1 ;
	f[6][0] = 1 ; f[6][1] = 1 ;
 	f[7][0] = 2 ; f[7][1] = 1 ;
	f[8][0] = 3 ; f[8][1] = 1 ;
	f[9][0] = 1 ; f[9][2] = 1 ;
	f[1000][6] = 1 ;
	f[2000][6] = 2 ;
	f[3000][6] = 3 ;
	for( i = 1 ; i < 10 ; i++){
		f[ i * 10 ][2] = f[i][0] ;
		f[ i * 10 ][3] = f[i][1] ;
		f[ i * 10 ][4] = f[i][2] ;
		f[ i * 100 ][4] = f[i][0] ;
		f[ i * 100 ][5] = f[i][1] ;	
		f[ i * 100 ][6] = f[i][2] ;
	}
}
void Add( int s ,int  t ){
	int i  ;
	for( i = 0 ; i <= 6 ; i++ ){
		f[s][i] +=f[t][i] ;
	}
}
void Calculate( int  num ){
	int i ;
	for( i = 0 ; i  <= 6 ; i++ )
	if(f[num][i])
	return ;
		int digit ;
		int value  = 1;
		int temp = num ;
	while(temp){
		digit = temp % 10 ;
		Add( num , digit * value ) ;
		value *= 10 ;
		temp /= 10 ;
	}
}
int main(){
	//f[i][j]  i用罗马数字表示第j个元素的个数 
	int i , j , k ;
	int totPage ;
	ifstream cin("preface.in") ;
	ofstream cout("preface.out") ;
	Initial() ;
	cin>>totPage ;
	for( i = 1 ; i <= totPage ; i++){
		Calculate(i) ;
		for( j = 0 ; j <= 6 ; j++)
			count[j] +=f[i][j] ;
	}
	for( i = 0 ; i <= 6 ; i++)
	if(count[i])
	cout<<m[i]<<" "<<count[i]<<endl;
	
	
}
