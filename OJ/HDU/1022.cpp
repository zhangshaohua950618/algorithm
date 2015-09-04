#include<iostream>
#include<stack>
#include<string.h>
#include<string>
#include<vector>
using namespace std ;
string  in , out  ;
stack<char> s ;
vector<int> t ;
int n  ;
int main(){
	int i , j ;
	while( cin >> n ){
		//Initial
		cin >> in >> out ;
		while(!s.empty())
		s.pop() ;
		t.clear() ;
		for( i = 0 , j = 0  ; i < in.length() ; i++ ){
			s.push(in[i]) ;
			t.push_back(1) ;
			while(s.top() == out[j] && !s.empty() && j < out.length() ){
				s.pop() ;
				t.push_back(0);
				j++ ;
			
			}
		}
		if(!s.empty())
		cout << "No." << endl ;
		else{
			cout << "Yes." << endl ;
		for( i = 0 ; i < t.size() ; i++ )
		if(t[i])
		cout << "in" << endl ;
		else
		cout << "out" << endl ;
		}
		cout << "FINISH" << endl ;
	}
	return 0 ;
}
