#include<iostream>
using namespace std;
const int MAXN = 1000 + 10;
int data[MAXN];
int n ,goal;
int main(){
	int i;
	cin >> n;
	for(i = 1 ; i <= n ; i++)
	cin >> data[i];
	cin >> goal;
	for(i = 1 ; i <= n ; i++)
	if(data[i] == goal){
		cout << i << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}
