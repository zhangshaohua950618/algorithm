/*
ID: zhangsh35
PROG: calfflac 
LANG: C++
*/
#include<fstream>
#include<string.h>
using namespace std ;
ifstream cin("calfflac.in") ;
ofstream cout("calfflac.out") ;
#define MAX( a , b ) ( (a) > (b) ? (a) : (b) )
int len , maxLen , maxPosition ;
string str , temp ;
bool IsSymbol( char symbol ){
	if( (symbol >= 'A' && symbol <= 'Z') || ( symbol >= 'a' && symbol <= 'z'))
	return true ;
	return false ;
}
char Translate( char symbol ){
	if( symbol >= 'A' && symbol <= 'Z')
	symbol  += 32 ;
	return symbol ;
}
int GetMaxCalfflac( int num ){
	//ÆæÊý
	int front , rear , oddLength , evenLength , maxLen ;
	front  = num , rear = num , oddLength = 1 ;
	while(true){
		front-- ;
		rear++ ;
		while(!IsSymbol(str[front]))
		front-- ;
		while(!IsSymbol(str[rear]))
		rear++ ;
		if(( front < 0 ) || ( rear >= str.length()))
			break ; 
		if( Translate( str[front] ) == Translate( str[rear] ) ) 
		oddLength += 2  ;
		else
		break ;
	}
	front  = num , rear = num + 1  ;
	while(!IsSymbol(str[rear]))
		rear++ ;
	if( str[front] != str[rear])
	return oddLength ;
	evenLength = 2 ;
	while(true){
		front-- ;
		rear++ ;
		while(!IsSymbol(str[front]))
		front-- ;
		while(!IsSymbol(str[rear]))
		rear++ ;
		if(( front < 0 ) || ( rear >= str.length()))
			break ; 
		if( Translate( str[front] ) == Translate( str[rear] ) ) 
		evenLength += 2  ;
		else
		break ;	
	}
	maxLen  = MAX( oddLength , evenLength ) ;
	return maxLen ;
}
void OutPut( int num ){
	int i ;
	int front , rear , length , amount ;
	if( maxLen % 2){
		length = ( maxLen - 1 ) / 2 ;
		front = num - 1  ,  rear = num + 1 ;
		amount = 0 ;
		while(amount < length){
			if(IsSymbol(str[front]))
			amount++ ;
			front-- ;
		}
		amount = 0 ;
		while(amount < length){
			if(IsSymbol(str[rear]))
			amount++ ;
			rear++ ;
		}
	}
	else{
		length = num / 2 ;
		front = num  ,  rear = num + 1 ;
		amount = 0 ;
		while(amount < length){
			if(IsSymbol(str[front]))
			amount++ ;
			front-- ;
		}
		amount = 0 ;
		while(amount < length){
			if(IsSymbol(str[rear]))
			amount++ ;
			rear++ ;
		}
		
	}
	for( i = front + 1  ; i <= rear - 1 ; i++ )
	cout << str[i] ;
	cout << endl ;
	
}
int main(){
	int i ;
	while(!cin.eof()){
		temp = cin.get() ;
		str += temp ;
	}
/*	for( i = 0 ; i < str.length() ; i++ ){
		if(IsSymbol(str[i]))
		len = GetMaxCalfflac(i) ;
		if( len > maxLen ){
			maxLen = len ;
			maxPosition = i ;
		}
	}
	cout << maxLen << endl ;
	OutPut(maxPosition) ;
	return 0 ;*/
}
