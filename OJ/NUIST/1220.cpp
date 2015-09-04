#include<fstream>
//#include<iostream>
using namespace std ;
ifstream cin("1.in") ;
ofstream cout("1.out") ;
const int MAXN = 20 ;
int result ;
/*
path记录棋盘状态
Right记录右对角线
Left记录左对角线
rows记录每行的状态，如果该行已经放过棋子则为true
cols记录每列的状态，如果该列已经放过棋子则为true
Right，Left不需要纠结，只要有标准能判定就可以了 
*/
bool path[MAXN][MAXN] , Right[MAXN * 2] , Left[MAXN * 2] , rows[MAXN] , cols[MAXN] ;
void dfs( int step ){//其实递归的是列~ 
	int i ;
	if(step == 8){
		result++ ;
		return ;
	}
	if(cols[step])
		dfs(step + 1) ;
		else{
		for( i = 0 ; i < 8 ; i++ )
			if(!rows[i] && !Right[ i - step + 8] && !Left[i + step]){//如果这个位置可以防止棋子，那么就更新它所有的状态 
				rows[i] = true ;
				Right[ i - step + 8] = true ;
				Left[i + step] = true ;
				dfs(step + 1) ;
				rows[i] = false ;
				Right[ i - step + 8] = false ;
				Left[i + step] = false ;
			}
	}
}
int main(){
	int i , j ;
	for( i = 0 ; i< 8 ; i++ )
		for( j = 0 ; j < 8 ; j++){
		cin >> path[i][j] ;
		if(path[i][j]){//输入的时候也要初始化 rows ，cols ，Right ，Left的状态 
			rows[i] = true ;
			cols[j] = true ;
			Right[ i - j + 8] = true ;
			Left[i + j] = true ;
		}
	}
	dfs(0) ;
	cout << result << endl ;
	return 0 ;
}
