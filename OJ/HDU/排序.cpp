#include<iostream>
#include<queue>
#include<string.h>
#include<string>
using namespace std ;
string str ;
int n , p;
priority_queue<int, vector<int>, greater<int> > q ;
int main(){
	int i , j ;
	while( cin >> str ){
		for( i = 0 ;i <= str.length()  ; i++ ){
			if((str[i] == '5'&& str[i - 1] != '5'&& i >= 1) || (i == str.length() && str[i - 1] != '5')){
				n = 0 ;
				p = 1 ;
				for( j = i - 1 ; str[j] != '5' && j >= 0; j--){
					n += (str[j] - '0') * p;
					p *= 10 ;
				}
				q.push(n) ;
			}
		}
		while(!q.empty()){
			cout << q.top()  ;
			q.pop() ;
			if(q.size() >= 1)
			cout << " " ;
			else
			cout << endl ;
		}
	}
	return 0 ;
}
