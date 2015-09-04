#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;
const int MAXN = 100000 + 10 ; 
const int MAXNUM = 499 ; 
int snow[MAXN][7] , t ;
vector<int> mark[49999] ;
bool Judge(int a[] , int b[]){
	int i , j  , start = 0;
	bool ok   ;
	for(i = 1 ; i <= 6 ; i++)
	if(b[i] == a[1]){
	start = i ;
	i = 1 ; 
	j = start ;
	while(a[i++] == b[j++]){
		if(i == 7)
		return true ;
		if(j == 7)
		j = 1 ;
	}
	i = 1 ; 
	j = start ;
	while(a[i++] == b[j--]){
		if(i == 7)
		return true ;
		if(j == 0)
		j = 6 ;
	}
	}
	return false ;
	
}
int main(){
	int i , j , hash ;
	cin >> t ;
	for(i = 1 ; i <= t ; i++){
		hash = 0 ;
	for(j = 1 ; j <= 6 ; j++){
		scanf("%d" , &snow[i][j]) ;
		hash = (hash + snow[i][j]) % MAXNUM  ;
	}
	mark[hash].push_back(i) ;
	for(j = 0 ; j < mark[hash].size() - 1 ; j++)
	if(Judge(snow[i] ,snow[mark[hash][j]])){
		cout << "Twin snowflakes found." << endl ;
		return 0 ;
		}
	}
	cout << "No two snowflakes are alike." << endl ;
	return 0 ;
} 
