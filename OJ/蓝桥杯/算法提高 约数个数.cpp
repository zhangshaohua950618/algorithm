#include<iostream>
using namespace std;
int data , sum;
int main(){
	cin >> data ;
	for(int i = 1 ; i <=  data ; i++)
	if(data % i == 0)
	sum++;
	cout << sum << endl;
	return 0;
}
