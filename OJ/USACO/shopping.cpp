/*
ID:    zhangsh35
PROG:    shopping
LANG:    C++
*/
#include<fstream>
#include<iostream>
#include<map>
using namespace std ;
const int INF = 0x7fffffff ;
const int MAXN = 10 ;
int pack[102][MAXN] ;
int limit[MAXN]  ;
int totPack , totDis , num , number , totGood , rate , cnt = 1 ;
int  f[MAXN][MAXN][MAXN][MAXN][MAXN] ;
map< int , int > M ;
map< int , int >::iterator it ;
int Translate( int  num){//num编号，number数量 
	if(M.find(num) != M.end())
			num = M[num] ;
	else{
			M[num] = cnt++ ;
			num = M[num] ;
	}
	return num ;
}
int Min( int a , int b ){
	return a < b ? a : b ;
}
int main(){
	ifstream cin("shopping.in") ;
	ofstream cout("shopping.out") ;
	int i , j , k , l , m , n ;
	cin >> totPack ;
	for( i = 1 ; i <= totPack ; i++ ){
		cin >> totDis ;
		for( j = 1 ; j <= totDis ; j++ ){
			cin >> num >> number ;
			num = Translate(num) ;
			pack[i][num] = number ;
		}
		cin >> pack[i][0] ;//记录优惠价格 
	}
	cin >> totGood ;
	for( i = 1 ; i <= totGood ; i++ ){
		cin >> num >> number >> rate;
		num = Translate(num) ;
		limit[num] = number ;
		pack[++totPack][num] = 1 ;
		pack[totPack][0] = rate ;
		limit[num] = number ;
	}
	for( j = 0 ; j <= 6 ; j++ )//1号物品 
	for( k = 0 ; k <= 6 ; k++ )//2号物品 
	for( l = 0 ; l <= 6 ; l++ )//3号物品 
	for( m = 0 ; m <= 6 ; m++ )//4号物品 
	for( n = 0 ; n <= 6 ; n++ )//5号物品 
	f[j][k][l][m][n] = INF ;
	f[0][0][0][0][0] = 0 ;
//	for( i = 1 ; i <= totPack ; i++ )
//	cout << "优惠价" << pack[i][0]  << " " << pack[i][1] << " " <<pack[i][2] << " " << pack[i][3] << " " << pack[i][4] << " " << pack[i][5] << endl ; 
	for( i = 1 ; i <= totPack ; i++ )
		for( j = pack[i][1] ; j <= limit[1] ; j++ )//1号物品 
		for( k = pack[i][2] ; k <= limit[2] ; k++ )//2号物品 
		for( l = pack[i][3] ; l <= limit[3] ; l++ )//3号物品 
		for( m = pack[i][4] ; m <= limit[4] ; m++ )//4号物品 
		for( n = pack[i][5] ; n <= limit[5] ; n++ )//5号物品
		if(f[j - pack[i][1]][k - pack[i][2]][l - pack[i][3]][m - pack[i][4]][n - pack[i][5]] != INF)
		f[j][k][l][m][n] = Min( f[j][k][l][m][n] , f[j - pack[i][1]][k - pack[i][2]][l - pack[i][3]][m - pack[i][4]][n - pack[i][5]] + pack[i][0] ) ;
/*	for( i = 1 ; i <= 5 ; i++ )
	cout << limit[i] << endl ;*/
	cout << f[limit[1]][limit[2]][limit[3]][limit[4]][limit[5]] << endl ;
	return 0 ;
}
