#include<stdio.h>
#include<math.h>
const double PI = atan(1.0) * 4 ;
int r ;
int main(){
	scanf("%d" , &r) ;
	printf("%.7lf\n" , PI * r *r) ;
	return 0 ;	
}