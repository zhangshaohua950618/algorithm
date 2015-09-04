#include<iostream>
using namespace std ;
const int MAXN = 8 +  10;
int chess[MAXN][MAXN] ,LeftBlack[MAXN* 2] , LeftWhite[MAXN* 2] , RightBlack[MAXN * 2], RightWhite[MAXN * 2] , result ,chessLength  ;
void putBlackQueen( int step ){
	if( step == chessLength){
		result++ ;
	}
	else{
		for( int  i = 0 ; i < chessLength ; i++ ){
			if(chess[i][step] && (RightBlack[i + step] == 0) && (LeftBlack[chessLength + step - i ] == 0)){//Black
				chess[i][step] = 0 ;
				RightBlack[i + step] = 1 ;
				LeftBlack[chessLength + step - i ] = 1 ;
				putBlackQueen(step + 1) ;
				chess[i][step] = 1 ;
				RightBlack[i + step] = 0 ;
				LeftBlack[chessLength + step - i ] = 0 ;
				}
			}
		}
}
void putWhiteQueen( int step ){
	if( step == chessLength){
		putBlackQueen(0) ;
		return ;
	}
	else{
		for( int  i = 0 ; i < chessLength ; i++ ){
			if(chess[i][step] && (RightWhite[i + step] == 0) && (LeftWhite[chessLength + step - i ] == 0)){//Black
				chess[i][step] = 0 ;
				RightWhite[i + step] = 1 ;
				LeftWhite[chessLength + step - i ] = 1 ;
				putWhiteQueen(step + 1) ;
				chess[i][step] = 1 ;
				RightWhite[i + step] = 0 ;
				LeftWhite[chessLength + step - i ] = 0 ;
				}
			}
		}
}
int main(){
	cin >> chessLength ;
	for( int  i = 0 ; i  < chessLength ; i++ )
	for( int  j = 0 ; j  < chessLength ; j++ )
	cin >> chess[i][j] ;
	putWhiteQueen(0) ;
	cout << result ;
	
}
