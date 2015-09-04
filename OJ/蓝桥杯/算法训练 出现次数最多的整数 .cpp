#include<iostream>
using namespace std;
int pre , cur , maxNum , curNum , tot , number;
int main(){
	int i , j;
	cin >> tot;
	if(tot > 0){
		cin >> number;
		pre = number;
		curNum = 1;
	for(i = 1 ; i < tot ; i++){
		cin >> cur;
		if(cur == pre){
			curNum++;
			if(curNum > maxNum){
				maxNum = curNum;
				number = cur;
			}
		}else{
			curNum = 1;
		}
		pre = cur;
		
	}
	cout << number << endl;
	}
	return 0;
}
