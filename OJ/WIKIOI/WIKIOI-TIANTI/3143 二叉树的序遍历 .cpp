#include<iostream>
using namespace std ;
const int MAXN = 16 + 5 ;
struct Node{
	int lch ;
	int rch ;
} ;
Node node[MAXN] ;
int n  , cou ;
void pre(int r){
	if(r){
		cout << r ;
		cou++ ;
		if(n - cou)
		cout << " " ;
		else
		cout << endl ;
		pre(node[r].lch) ;
		pre(node[r].rch) ;
	}
}
void in(int r){
	if(r){
		in(node[r].lch) ;
		cout << r ;
		cou++ ;
		if(n - cou)
		cout << " " ;
		else
		cout << endl ;
		in(node[r].rch) ;
	}
}
void aft(int r){
	if(r){
		aft(node[r].lch) ;
		aft(node[r].rch) ;
		cout << r ;
		cou++ ;
		if(n - cou)
		cout << " " ;
		else
		cout << endl ;
		
	}
}
int main(){
	int i , j ;
	cin >> n ;
	for(i = 1 ; i <= n ; i++)
	cin >> node[i].lch >> node[i].rch ;
	cou = 0 ;
	cou = 0 ;
	aft(1) ;
	return 0 ;
}
