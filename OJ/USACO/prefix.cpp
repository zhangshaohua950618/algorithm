/*
ID:		zhangsh35
PROG:	prefix
LANG:	C++
*/
#include<iostream>  
#include<fstream>
#include<string.h>
using namespace std ;
string str ;
string sub[200 + 10] ;
int cnt = 0 ;
int prefix[200000 + 10] ;
bool Match( int pos , string subStr){
	int i ;
	for( i = 0 ; i < subStr.length() ; i++ )
		if( subStr[i] != str[ pos + i ])
		return false ;
	return true ;
}
int Max( int a , int  b ){
	return a > b ? a : b ;
}
int main(){
	ifstream cin("prefix.in") ;
	ofstream cout("prefix.out") ;
	int  i , j ;
	while(cin>>sub[cnt] && sub[cnt] != ".")
	cnt++ ;
	string temp ;
	while(cin>>temp){
		str += temp ;
		if(temp == " ")
		break ;
	}
//	cout<<str<<endl; ;
	for( j = str.length() - 1 ; j >= 0 ; j-- ){
		for( i = 0 ; i < cnt ; i++ )
		if( Match( j , sub[i] ))
		prefix[j] = Max( prefix[j] , prefix[j + sub[i].length()] + sub[i].length() ) ;
	//	cout<<" j = "<<i<<" "<<prefix[j]<<endl;
	}
	cout<<prefix[0]<<endl ;
	return 0;
}
