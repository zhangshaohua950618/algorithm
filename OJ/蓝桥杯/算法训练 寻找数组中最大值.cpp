#include<iostream>
using namespace std;
int maxNum , index , num , data;
int main(){
	int i;
	
	cin >> num;
	
	
	for(i = 0 ;i < num ; i++){
		cin >> data;
		if(data > maxNum){
			maxNum = data;
			index = i;
		}
	}
	
	
	cout << maxNum << " " << index << endl;
	
	
	return 0;
}
