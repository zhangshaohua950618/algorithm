/*
ID: zhangsh35
PROG: castle 
LANG: C++
*/
#include<fstream>
using namespace std ;
ifstream cin("castle.in") ;
ofstream cout("castle.out") ;
const int MAXN = 50 + 2 ;
bool direction[MAXN][MAXN][4] ;
int castle[MAXN][MAXN] , width , height , input , mark = 1 , roomSize[MAXN * MAXN] , maxRoom , maxI , maxJ ;
char maxDirection ;
void GetDirection( int i , int j , int input){
	if(input&1)
	direction[i][j][0] = true ;
	if(input&2)
	direction[i][j][1] = true ;
	if(input&4)
	direction[i][j][2] = true ;
	if(input&8)
	direction[i][j][3] = true ;
}
bool FloodFill( int i , int  j ){
	if(castle[i][j] != 0  )
	return false ;//不需要填充 
	castle[i][j] = mark ;
	roomSize[mark]++ ;
	if(!direction[i][j][0])
	FloodFill( i , j - 1 ) ;
	if(!direction[i][j][1])
	FloodFill( i - 1 , j ) ;
	if(!direction[i][j][2])
	FloodFill( i , j + 1 ) ;
	if(!direction[i][j][3])
	FloodFill( i + 1 , j ) ;
	return true ;//需要填充，并且使用mark填充 
}
#define MAX( a , b ) ((a) > (b) ? (a) : (b))
int main(){
	int i , j ;
	cin >> width >> height ;
	for( i = 1 ; i <= height ; i++ )
	for( j = 1 ; j <= width ; j++ ){
		cin >> input ;
		GetDirection( i , j , input ) ;
	}
	for( i = 1 ; i <= height ; i++ )
	for( j = 1 ; j <= width ; j++ )
	if(FloodFill( i , j ))
	mark++ ;
	for( i = 0 ; i < mark ; i++ )
	maxRoom = MAX( maxRoom , roomSize[i]) ;
	cout << mark - 1 << endl << maxRoom << endl ;
	for( j = 1 ; j <= width ; j++ )
	for( i = height ; i >= 1 ; i-- ){
		if((direction[i][j][1]) && (castle[i][j] != castle[i - 1][j]) ){
			if( roomSize[castle[i][j]] + roomSize[castle[i - 1][j]] > maxRoom ){
				maxI = i ;
				maxJ = j;
				maxDirection = 'N' ;	
				maxRoom = roomSize[castle[i][j]] + roomSize[castle[i - 1][j]] ;
			}
		}
		if((direction[i][j][2]) && (castle[i][j] != castle[i][j + 1]) ){
			if( roomSize[castle[i][j]] + roomSize[castle[i][j + 1]] > maxRoom ){
				maxI = i ;
				maxJ = j;
				maxDirection = 'E' ;	
				maxRoom = roomSize[castle[i][j]] + roomSize[castle[i][j + 1]] ;
			}
		}
		
	}
	cout << maxRoom << endl << maxI << " " << maxJ << " " << maxDirection << endl ;
	
}
