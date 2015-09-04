/*
ID: zhangsh35
PROG: ariprog 
LANG: C++
*/
#include<fstream>
#include<algorithm>
using namespace std ;
ifstream cin("ariprog.in") ;
ofstream cout("ariprog.out") ;
const int MAXN = 10000 + 10 ;
const int MAX = 1000000 ;//为什么250 * 250 * 2 + 10还是会超出边界，不解 
struct Result{
	int first ;
	int difference ; 
} ;
Result result[MAXN] ;
bool isAriprog[MAX]  , exist ;
int  ariprog[MAX] ;
int bound , len , num , dif , totResult , number  ;
bool Judge( int first , int difference ){
	int  i ;
	for( i = 1 ; i < len ; i++ ){
		if(!isAriprog[ first + difference * i ])
		return false ;
	}
	return true ;
}
bool cmp( Result a , Result b ){
	if( a.difference == b.difference)
	return a.first < b.first ;
	return a.difference < b.difference ;
}
int main(){
	int i , j , k ;
	cin >> len >> bound ;
	for( i = 0 ; i <= bound ; i++ )
		for( j = 0 ; j <= bound ; j++ ){
			number = i * i + j * j ;
			exist = false ;
			for( k = 0 ;  k < num ; k++ ){
				if(ariprog[k] == number){
					exist = true ;
					break ;
				}	
			}
			if(!exist){
				ariprog[num] = number;
				isAriprog[ariprog[num]] = true ;
				num++ ;
			}
	}
	sort( ariprog , ariprog + num ) ;
/*	for( i = 0 ; i  < num ; i++ )
	cout << ariprog[i] << endl ; */
	for( i = 0 ; i < num  ; i++ )
		for( j = i + 1 ; j < num ; j++ ){
			dif = ariprog[j] - ariprog[i] ;
			if(Judge( ariprog[i] , dif )){
				result[totResult].first = ariprog[i] ;
				result[totResult].difference = dif ;
				totResult++ ;
			}	
		}
	sort( result  , result + totResult , cmp ) ;
	for( i = 0 ; i < totResult ; i++ )
	cout << result[i].first << " " << result[i].difference << endl ;
	if(!totResult)
	cout << "NONE" << endl ;
	return 0 ;
	
	
}
