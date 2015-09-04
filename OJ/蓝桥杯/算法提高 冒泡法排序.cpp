#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int num[20];
int main(){
	int i;
	for(i =0 ; i < 10 ; i++)
		cin >> num[i];
	sort(num , num + 10 );
	for(i = 0 ;i < 10 ; i++)
	cout << num[i] << " ";
	cout << endl;
	return 0;
	
}
