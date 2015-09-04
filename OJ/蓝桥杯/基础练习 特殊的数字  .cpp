#include<iostream>
#include<cmath>
using namespace std;
int num , dig , ten , hun;
int main(){
	for(num = 100 ; num <= 999 ; num++){
		dig = num % 10;
		hun = num / 100;
		ten = (num % 100) / 10;
		if(num == pow(dig , 3) + pow(ten , 3) + pow(hun , 3))
		cout << num << endl; 
	}
	return 0;
}
