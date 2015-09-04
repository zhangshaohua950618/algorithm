/*
ID: zhangsh35
PROG: cowtour
LANG: C++
*/
#include<fstream>
#include<math.h>  
#include <iomanip>
#define MIN( a , b ) ( (a) < (b) ? (a) : (b) )
#define MAX( a , b ) ( (a) > (b) ? (a) : (b) )
using namespace std ;
ifstream cin("cowtour.in") ;
ofstream cout("cowtour.out") ;
const int MAXN = 150 + 10 ;
const int INF = 99999.000 ;
struct Node{
	int x ;
	int y ;
} ;
string input ;
double dis[MAXN][MAXN]  , maxDis[MAXN] , minDis = INF , maxFild[MAXN] ; // 直接距离 ， 最短距离 
int nodeMark[MAXN] , fild[MAXN][MAXN] , mark = 1 , totMark[MAXN] , totNode  ;
Node node[MAXN] ;
double GetDis( Node a , Node b ){
	int sum =(b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y) ;
	double res = sqrt((double)(sum)) ;
	return res ;
}
void Floyd(){
	int i , j , k ;
	for( k = 0 ; k < totNode ; k++ )
	for( i = 0 ; i < totNode ; i++ )
	for( j = 0 ; j < totNode ; j++ )
		dis[i][j] = dis[j][i] = MIN( dis[i][j] , dis[i][k] + dis[k][j] ) ;
}
bool FloodFill( int num ){
	if(nodeMark[num])
	return false ;
	nodeMark[num] =  mark ;
	fild[mark][totMark[mark]++] = num ;
	for( int i = 0 ; i  < totNode ; i++ ){
		if(dis[num][i] != INF)
		FloodFill(i) ;
	}
	return true ;
}
void Input(){
	int i  , j  ;
	cin >> totNode ;
	for( i = 0 ; i  < totNode ; i++ )
		cin >> node[i].x >> node[i].y ;
	getline( cin , input ) ;
	for( i = 0 ; i < totNode ; i++ ){
		getline( cin , input ) ;
		for( j = 0 ; j < totNode ; j++ ){
			if( i == j )
			dis[i][j] = 0.0 ;
			else
			dis[i][j] = input[j] == '1' ? GetDis( node[i] , node[j] ) : INF ;
		}
	}	
}
int main(){
	int i , j , k , m ; 
	Input() ;
	Floyd() ;	
	for( i = 0 ; i < totNode ; i++ ){
		if( FloodFill( i ))
		mark++ ;
	}	
	for( k = 1 ; k < mark ; k++ )
		for( i = 0 ; i < totMark[k] ; i++ )
			for( j = 0 ; j < totMark[k] ; j++ )
			maxDis[fild[k][i]] = MAX( maxDis[fild[k][i]] , dis[fild[k][i]][fild[k][j]] ) ;
	for( i = 1 ; i < mark ; i++ )
		for( j = 0 ; j < totMark[i] ; j++)
			maxFild[i] = MAX( maxFild[i] , maxDis[fild[i][j]] ) ;
	for( k = 1 ; k < mark ; k++ )
	for( m = k + 1 ; m < mark ; m++ )
	for( i = 0 ; i < totMark[k] ; i++ )//k号农场 
	for( j = 0 ; j < totMark[m] ; j++ ){//m号农场 
		minDis = MIN( minDis , MAX(GetDis( node[fild[k][i]] , node[fild[m][j]] ) + maxDis[fild[k][i]] + maxDis[fild[m][j]]  , MAX( maxFild[k] , maxFild[m]))) ;
	}
	 cout<<setprecision(6)<<setiosflags(ios::fixed)<<minDis<<endl;	
}

