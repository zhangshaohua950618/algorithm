#include<iostream>
#include<stdio.h>
using namespace std;
const  double pi = 3.1415926;
double r;
int main(){
	cin >> r;
	printf("%.1lf\n" ,  pi * r * r + 2 * pi * r * 2);
	return 0;
}
