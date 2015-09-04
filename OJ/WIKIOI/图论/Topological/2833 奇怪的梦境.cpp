#include<iostream>
using namespace std;
const int MAXN = 10000 + 10;
bool path[MAXN][MAXN] ;
int degree[MAXN] ; 
bool ok ; 
int totButton , totInf , before , after , pressedButton;
void Topological(){
	int i , j ;
	ok = true ; 
	while(ok){
		ok = false;
	for( i = 1 ; i <= totButton ; i++)
		if(!degree[i]){
			ok = true ;
			pressedButton++ ;
			degree[i] = -1;
			for( j = 1 ; j <= totButton ; j++)
			if(path[i][j]){
				path[i][j] = false;
				degree[j]--;
			}	
		}
	}
	return ;
}
int main(){
	int  i ; 
	cin>>totButton>>totInf ;
	for(i = 0 ; i < totInf ; i++){
		cin>>before>>after ;
		path[before][after] = true ;
		degree[after]++ ;
	}
	Topological();
	if(totButton - pressedButton)
	cout<<"T_T"<<endl<<totButton - pressedButton<<endl;
	else
	cout<<"o(n_n)o"<<endl;
}
