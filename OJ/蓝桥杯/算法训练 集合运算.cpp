#include<iostream>
#include<set>
using namespace std;

set<int> a , b , c ,d;
int numA , numB , data;
int main(){
	int i , j;
	cin >> numA;
	for(i = 0 ; i < numA ; i++){
		cin >> data;
		a.insert(data);
		c.insert(data);
	}
	cin >> numB;
	for(i = 0 ; i < numB ; i++){
		cin >> data;
		b.insert(data);
		c.insert(data);
	}
	d = b;

	pair<set<int>::iterator, bool> p;
	for(set<int>::iterator it = a.begin() ; it != a.end() ; it++){
		p = b.insert(*it);
		if(!p.second)
		cout << *it << " ";
	}
	cout << endl;

	for(set<int>::iterator it = c.begin() ; it != c.end() ; it++)
	cout << *it << " ";
	cout << endl;


	for(set<int>::iterator it = a.begin() ; it != a.end() ; it++){
		p = d.insert(*it);
		if(p.second)
		cout << *it << " ";
	}
	cout << endl;
	
}
