#include<iostream>
using namespace std;
int minNum , maxNum , mod;
int main(){
	cin >> minNum >> maxNum >> mod;
	
	
	for(int i = minNum ; i <= maxNum ; i++)
	if(i % mod == 0)
	cout << i << " ";
	cout << endl;
	
	
	return 0;
	
}
