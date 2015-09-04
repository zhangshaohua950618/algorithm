#include<iostream>
#include<string.h> 
#include<stack>
using namespace std;
string a ,b ;
stack<int> na , nb , res ;
int ma , mb , step , temp ;
int main(){
	int i , j ;
	while( cin >> a >> b ){
		for( i = 0 ; i < a.length() ; i++ )
		na.push(a[i] - '0') ;
		for( i = 0 ; i < b.length() ; i++ )
		nb.push(b[i] - '0') ;
		step = 0 ;
		while(!na.empty() || !nb.empty() ){
			ma = mb = 0 ;
			if(!na.empty()){
				ma = na.top() ;
				na.pop() ;
			}
			if(!nb.empty()){
				mb = nb.top() ;
				nb.pop() ;
			}
			temp = ma  + mb  + step ;
			step = temp / 10 ;
			res.push( temp % 10 );
		}
		if(step)
		cout << step ;
		while(!res.empty()){
			cout << res.top() ;
			res.pop() ;
		}
		cout << endl ;
	}
	return 0 ;
	
} 
