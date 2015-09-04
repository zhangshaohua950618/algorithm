//#include<iostream>
#include<stdio.h>
//#include<iomanip>
//using namespace std ;
int n , t  ;
double e = 1.0   ;
int main(){
	int i , j ;
	printf("n e\n");
    printf("- -----------\n");
	t = 1 ;
	n = 1 ;
	while(n <= 10 ){
		printf("%d %.9lf\n",n - 1,e);
		t *= n ;
		e += 1.0 /  t ;
		n++ ;
	}
	return 0 ;
	
} 
