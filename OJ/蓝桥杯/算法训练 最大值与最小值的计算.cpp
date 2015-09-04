#include<iostream>
using namespace std;
int num , minNum , maxNum;
int main(){
	cin >> num;
	minNum = num;
	maxNum = num;
	for(int i = 1 ; i < 11 ; i++){
		cin >> num;
		if(num < minNum)
		minNum = num;
		if(num > maxNum)
		maxNum  = num;
	}
	cout << maxNum << " " << minNum << endl;
	return 0;
}
