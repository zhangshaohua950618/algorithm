#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int  num;
int main(){
	cin >> num;
	cout << (int)pow(num , 2) << " ";
	printf("%.2lf " , sqrt(num));
	printf("%.2lf\n" , 1 / (double)num);
	return 0;
}
