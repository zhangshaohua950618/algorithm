#include<iostream>
#include<string.h>
using namespace std ;
string str ;
void dfs(int step){
	if(step == 5)
		cout << str << endl ;
	else
	for(int i= '0' ; i < '2' ; i++ ){
		str[step] = i ;
		dfs(step + 1) ;
	}
}
int main(){
	str = "00000" ;
	dfs(0) ;
	return 0 ;
}
