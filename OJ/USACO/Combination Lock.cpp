/*
ID: zhangsh35
PROG: combo
LANG: C++
*/
#include<fstream>
#include<cstdlib>
using namespace std ;
ifstream cin("combo.in") ;
ofstream cout("combo.out") ;
int f1 , f2 , f3 ;
int m1 , m2 , m3 ;
int N , ans ; 
bool close(int f1 , int c1){
	if(abs(f1 - c1) <= 2 || abs(f1 - c1) >= N - 2) return  true ;
	return false ;
}
bool closeEnough(int f1 , int f2 , int f3 ,
                 int c1 , int c2 , int c3){
    return close(f1 , c1) &&  close(f2 , c2) && close(f3 , c3) ;
}
int main(){
	
	cin >> N ;
	cin >> f1 >> f2 >> f3 ;
	cin >> m1 >> m2 >> m3 ;


	for(int n1 = 1 ; n1 <= N ; n1++)
	 for(int n2 = 1 ; n2 <= N ; n2++)
	  for(int n3 = 1 ; n3 <= N ; n3++)
	  if(closeEnough(f1 , f2 , f3 , n1 , n2 , n3) || closeEnough(m1 , m2 , m3 , n1 , n2 , n3))
	  ans++ ;
	
	  
    cout << ans << endl ;
	  
    return 0 ;
}
