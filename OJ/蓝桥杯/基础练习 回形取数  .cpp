#include<iostream>
#include<stdio.h>
using namespace std ;
const int MAXN = 200 + 10 ;
int rows , cols , count , maze[MAXN][MAXN];
int main(){
	int i , j ;
	cin >> rows >> cols ;
	for( i = 1 ; i <= rows ; i++ )
	for( j = 1 ; j <= cols ; j++ ){
		scanf("%d",&maze[i][j]) ;
	}
	i = 1 , j = 1 ;
	while( count <= rows * cols ){
		while( maze[i][j] ){//down
			printf("%d",maze[i][j]) ;
			count++ ;
			if(count < rows * cols)
			printf(" ") ;
			else{
				printf("\n") ;
				return 0 ;
			}
			maze[i][j] = 0 ;
			i++ ;
		}
		i--, j++ ;
		while( maze[i][j] ){//right
			printf("%d",maze[i][j]) ;
			count++ ;
			if(count < rows * cols)
			printf(" ") ;
			else{
			printf("\n") ;
				return 0 ;
			}
			maze[i][j] = 0 ;
			j++ ;
		}
		j-- , i-- ;
		while( maze[i][j] ){//up
		printf("%d",maze[i][j]) ;
			count++ ;
			if(count < rows * cols)
			printf(" ") ;
			else{
			printf("\n") ;
				return 0 ;
			}
			maze[i][j] = 0 ;
			i-- ;
		}
		i++ , j-- ;
		while( maze[i][j] ){//left
			printf("%d",maze[i][j]) ;
			count++ ;
			if(count < rows * cols)
			printf(" ") ;
			else{
			printf("\n") ;
				return 0 ;
			}
			maze[i][j] = 0 ;
			j-- ;
		}
		j++ , i++ ;
	}
}
