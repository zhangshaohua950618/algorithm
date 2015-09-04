#include<iostream>
#include<stack>
using namespace  std;
stack<int> s;
int num;
int main(){
	cin >> num;
	while(num){
		s.push(num % 8);
		num /= 8;
	}
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}
