#include<iostream>
#include<set>
using namespace std;
set<int> s;
set<int>::iterator it;
int data;
int main(){
	while( cin >> data && data)
		s.insert(data);
	it = s.end();
	it--;
	it--;
	cout << *it << endl;
	return 0;
}
