#include<stdio.h>
int n;
int main(){
        scanf("%d",&n);
        int i;
        for(i = 2 ; n % i ; i++){
        }
        printf("%d\n", n /i);
        return 0;
}
