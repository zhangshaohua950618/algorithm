#include<iostream>
#include<algorithm>
using namespace std ;
int number[100000+10];
int main(){
	int totNumber ;
	int i ;
	cin>>totNumber;
	for(i = 0 ; i < totNumber ; i++)
		cin>>number[i];
	sort(number , number + totNumber);
	for(i = 0 ; i < totNumber - 1 ; i++)
	cout<<number[i]<<" ";
	cout<<number[i]<<endl;
	return 0;
}

