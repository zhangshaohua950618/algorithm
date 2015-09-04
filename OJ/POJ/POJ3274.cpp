#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<vector>
#define MAX(a , b) ((a) > (b) ? (a) : (b))
using namespace std ;
const int MAXN = 100000 + 10 ;
int power[40] , charactor[MAXN][40] , n , k ,ch , ans ;
typedef vector<int> v ;
v T[MAXN] ;
void initial(){
	int i , p = 1 ;
	for(i = 0 ; i <= 30 ; i++){
	   power[i] = p ;
	   p *= 2 ;
	}
}
void getSum(int row , int ch){
	int i , j ; 
	for(i = 0 ;i < k ;i++)
	charactor[row][i] = charactor[row - 1][i] + ch & power[i] ? 1 : 0 ;
}
void getDif(){
	int i , j ;
	for(i = 1 ; i <= n ; i++)
	for(j = 0 ; j < k ; j++)
	charactor[i][j] -= charactor[i][0] ;  
}
int getHash(int row){
	int i , hash = 0 ;
	for(i = 0 ; i < k ; i++)
	hash += charactor[row][i] ;
	return (hash > 0 ? hash : -hash) % MAXN ;
}
bool cmp(int row1 , int row2){
	int i ;
	for(i = 0 ; i < k ; i++)
	if(charactor[row1][i] != charactor[row2][i])
	return false ;
	return true ;
}
void insert(int row){
	int i , j ;
	int hash = getHash(row) ;
	bool ok = false ;
	for(i = 0 ; i < T[hash].size() ; i++)
	if(cmp(row , T[hash][i])){
		ok = true ;
		ans = MAX(ans , row - T[hash][i] + 1) ;
		break ;
	}
	if(!ok)
	T[hash].push_back(row) ;
}
int main(){
	int i , j ; 
	initial() ;
	while(cin >> n >> k){
	memset(charactor , 0 , sizeof(charactor)) ;	
	ans = 0 ;	
	for(i = 1 ; i <= n ; i++){
	     scanf("%d" ,&ch) ;
	      getSum(i , ch) ;
	   }
     getDif();
     for(i = 1 ; i <= n ; i++)
       insert(i) ;
     cout << ans << endl ;
     for(i = 1 ; i <= n ; i++)
     T[i].clear() ;
	}
	return 0 ;
}
