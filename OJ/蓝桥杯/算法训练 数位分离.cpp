#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int num;
void GetDit(int num){
	while(num){
		s.push(num % 10);
		num /= 10;
	}
}
int main(){
	cin >> num;
	GetDit(num);
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}	
	cout << endl;
	return 0;
}
