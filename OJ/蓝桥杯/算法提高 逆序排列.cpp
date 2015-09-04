#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int data;
int main(){
	while(cin >> data && data)
	s.push(data);
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	return 0;
}
