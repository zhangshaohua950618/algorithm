#include<iostream>
using namespace std;
int tot ,data , sum;
int main(){
	int i;
	cin >> tot;
	for(i = 0 ;i < tot ; i++){
		cin >> data;
		if(data){
			cout << data <<" ";
			sum ++;
		}
	}
	cout << endl;
	cout << sum << endl;
}
