#include<iostream>
#include<vector>
using namespace std ;
const int MAXN = 9973 ;
int snow[100000 + 10][7] , T ;
bool  ok ;
typedef vector<int> hashtable ;
hashtable table[MAXN] ;
int getHash(int a[]){
	int i , hash = 0 ;
	for(i = 1 ; i  <= 6 ; i++)
	hash = (hash + a[i]) % MAXN ;
	return hash ;
}
bool Judge(int a[] , int b[]){
	int i , j , k  ;
	for(i = 1 ; i <= 6 ; i++)
	if(b[i] == a[1]){
		for(j = i , k = 1 ; a[k++] == b[j--] ;  ){
              if(k == 7) return true;  
              if(j == 0)
              j = 6 ;
		}
        for(j = i ,k = 1 ; a[k++] == b[j++] ; ){ 
              if(k == 7) return true;   
              if(j == 7)
              j = 1 ;
        }
	}
	return false ;
}
bool insert(int cur){
	int hash = getHash(snow[cur]) ;
	int i  ;
	for(i = 0 ; i < table[hash].size() ; i++)
	if(Judge(snow[cur] , snow[table[hash][i]]))
	return false ;
	table[hash].push_back(cur) ;
	return true ; 	
}
int main(){
	int i , j ;	
	cin >> T ;
	for(i = 1 ; i <= T ; i++){
		for(j = 1 ; j <= 6 ; j++)
		scanf("%d" , &snow[i][j]) ;
		if(!ok && !insert(i))
		ok = true ;
	}
	if(ok)
	cout << "Twin snowflakes found." << endl ;
	else
	cout << "No two snowflakes are alike." << endl ;
	return 0 ;
}


