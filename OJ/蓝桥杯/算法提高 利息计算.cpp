#include<iostream>
#include<stdio.h>
using namespace std;
double money , rate , result;
int main(){
	cin >> money >> rate;
	result = money + money / 100 * rate * 0.8;
	printf("%.2lf\n" , result);
	return 0;
}
