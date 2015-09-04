/*
ID: zhangsh35
PROG: castle 
LANG: C++
*/
#include<fstream>
#include<string.h>
using namespace std ;
ifstream cin("castle.in") ;
ofstream cout("castle.out") ;
const int MAXN = 50 + 10 ;
int totRoom = 1  , maxRoom , roomSize[ MAXN * MAXN ] , width , height , head[MAXN * MAXN] ;
int input , castle[MAXN][MAXN] , headRoom , sonRoom , size[MAXN * MAXN] , amount , maxI , maxJ , maxNewRoom  , curNewRoom;
char maxDirection ;
bool direction[MAXN][MAXN][4] ;//西  北 东 南  
void GetDirection( int i , int j , int num ){
	if( num & 0x1 ){
		direction[i][j][0] = true ;
		num-- ;
	}
	if( num >= 8 ){
		direction[i][j][3] = true ;
		num -= 8 ;
	}
	if( num >= 4 ){
		direction[i][j][2] = true ;
		num -= 4 ;
	}
	if( num >= 2 ){
		direction[i][j][1] =true ;
		num -= 2 ;
	}
}
#define MIN( a , b ) ((a) < (b) ? (a) : (b))
#define MAX( a , b ) ((a) > (b) ? (a) : (b))
int main(){
	int i , j , k ;
	cin >> width >> height ;
	for( i = 1 ; i <= height ; i++ )
		for( j = 1; j <= width ; j++ ){
			cin >> input ;
			GetDirection( i , j , input ) ;
			if(direction[i][j][1] && direction[i][j][0]){
				castle[i][j] = totRoom++ ;
				roomSize[castle[i][j]]++ ;
			}
			else if (!direction[i][j][1]){
				castle[i][j] = castle[i - 1][j] ;
				roomSize[castle[i][j]]++ ;
				continue ;
			}
			else{
				castle[i][j] = castle[i][j - 1] ;
				roomSize[castle[i][j]]++ ;	
			}
		}
	for( i = 1 ; i < totRoom ; i++ )
		head[i] = i ;
	for( i = 1 ; i <= height ; i++ ){//并查集 
		for( j = 1 ; j <= width ; j++ ){
		//	cout << castle[i][j] << " ";
			if( (!direction[i][j][2]) && (castle[i][j] != castle[i][j + 1])){
				headRoom = MIN( castle[i][j] , castle[i][j + 1]) ;
				sonRoom = MAX(castle[i][j] , castle[i][j + 1]) ;
				head[sonRoom] = headRoom ;
				for( k = 1 ; k < totRoom ; k++ )
				if(head[k] == sonRoom)
				head[k] = headRoom ;
			}
			if( (!direction[i][j][3]) && (castle[i][j] != castle[i + 1][j])){
				headRoom = MIN( castle[i][j] ,castle[i + 1][j]) ;
				sonRoom = MAX(castle[i][j] , castle[i + 1][j]) ;
				head[sonRoom] = headRoom ;
				for( k = 1 ; k < totRoom ; k++ )
				if(head[k] == sonRoom)
				head[k] = headRoom ;
			}
		}
	//	cout << endl ;
	}	
	for( i = 1 ; i < totRoom ; i++ ){
		size[head[i]] += roomSize[i] ;
	}
		for( i = 1 ; i < totRoom ; i++ )
	cout << size[i] << endl ;
	for( i = 1 ; i < totRoom ; i++ ){
		if(size[i]){
			amount++ ;
			maxRoom = MAX( maxRoom , size[i]) ;
		}
	}
	cout << amount <<endl ;
	cout << maxRoom << endl ;
	for( j = 1 ;  j <= width ; j++ )
		for( i = height ; i >= 1 ; i-- ){
			if(direction[i][j][1] && (head[castle[i][j]] != head[castle[i - 1][j]])){
				curNewRoom = size[head[castle[i][j]]] + size[head[castle[i - 1][j]]] ;
				if( curNewRoom > maxNewRoom ){
					maxI = i ;
					maxJ = j ;
					maxNewRoom = curNewRoom ;
					maxDirection = 'N' ;
				}
			}
			if(direction[i][j][2] && (head[castle[i][j]] != head[castle[i][j + 1]])){
				curNewRoom = size[head[castle[i][j]]] + size[head[castle[i][j + 1]]] ;
				if( curNewRoom > maxNewRoom ){
					maxI = i ;
					maxJ = j ;
					maxNewRoom = curNewRoom ;
					maxDirection = 'E' ;
				}
			}
		}
	cout << maxNewRoom << endl ;
	cout << maxI << " " << maxJ << " " << maxDirection << endl ;
}
