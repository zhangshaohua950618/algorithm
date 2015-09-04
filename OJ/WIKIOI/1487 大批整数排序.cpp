#include<stdio.h>
long num[11] , N  , number ;
int main(){
	int i ;
	scanf("%d" , &N) ;
	for(i = 0 ; i < N ; i++){	
		scanf("%d" , &number) ;
		num[number]++ ;
	}
	for(i = 1 ; i  <= 10 ; i++){
		while(num[i]--)
		printf("%d\n" , i) ;
	}
	return 0 ;
}
