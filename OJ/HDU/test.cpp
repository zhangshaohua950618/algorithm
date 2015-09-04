#include<stdio.h>
int main(){
	int a,result;
	scanf("%d",&a);
	result = 1 ;
	for(int i=1;i<= a;i++)
		result *= i ;
	printf("%d\n" , result) ;
	return 0 ;
}
