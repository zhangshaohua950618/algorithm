#include<iostream>
#include<set>
using namespace std;
int n , data;
set<int> s;
int main(){
	int i;
	cin >> n;
	for(i = 0 ; i < n ; i++){
		cin >> data;
		s.insert(data);
	}
	cout << s.size() << endl;
	for(set<int>::iterator it = s.begin() ; it != s.end() ; it++)
	cout << *it << " ";
	cout << endl;
	return 0;
}
