#include<iostream>
using namespace std;
int num , data , sum;
int main(){
	cin >> num;
	for(int i = 0 ; i < num ; i++){
		cin >> data;
		sum += data;
	}
	cout << sum / num << endl;
	return 0;
}
