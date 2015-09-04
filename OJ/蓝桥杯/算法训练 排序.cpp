#include<iostream>
#include<algorithm>
using namespace std;
int data[4];
int main(){
	int i;
	for(i = 0 ; i < 3 ; i++)
	cin >> data[i];
	sort(data , data + 3);
	for(i = 2 ; i > 0 ; i--)
	cout << data[i] << " ";
	cout << data[i] << endl;
}
