/*
ID: zhangsh35
PROG: contact 
LANG: C++
*/
#include<fstream>
#include<algorithm>
#include<math.h>
using namespace std ;
ifstream cin("contact.in") ;
ofstream cout("contact.out") ;
const int MAXN = 20 ;
struct Contact{
	int value ;
	int length ;
	int amount ;
	bool shortMessage[MAXN] ;
} ;
Contact contact[(1 << 14)] ;
bool message[ 200000 + 10 ] ;
int totContact , maxLength , minLength , totOutPut , totMessage , currentOutPut , cnt ;
string input ;
void GetContact( int length ){
	int number ;
	int i , j ;
	for( i = 0 ; i  < ( 1 << length) ; i++){
		number = i ; 
		contact[totContact].length = length ;
		contact[totContact].value = i ;
		for( j = length - 1 ; j >= 0 ; j--){
			contact[totContact].shortMessage[j] = ( number & 0x1 ) ;
			number = number >> 1 ;
		}
		totContact++ ;
	}
	
}
void Mate( int position , int length ){
	int value = 1 , sum = 0  , pos = 0 ;
	int i ;
	for( i = position ; i >= ( position - length + 1 ) ; i-- ){
		if( message[i] )
		sum += value ;
		value *= 2 ;
	}
/*	cout << "length = " << length << endl ;
	cout << "position = " << position << endl ;
	cout << "sum = " << sum << endl ; 
	cout << "pos = " << pos << endl ;*/
	for( i = minLength ; i <= length - 1 ; i++ )
	pos += pow( 2 , i ) ;
	pos += sum ;
//	cout << "pos = " <<pos << endl ;
	contact[pos].amount++ ;	
}
void Matching( int position ){
	int i ;
	for( i = minLength ; i <= maxLength ; i++ )
	if( position >= ( i - 1 ))
	Mate( position , i ) ;
}
bool cmp( Contact front , Contact rear ){
	if( front.amount != rear.amount )
	return front.amount > rear.amount ;
	if( front.length != rear.length )
	return front.length < rear.length ;
	return front.value < rear.value ;
}
void OutPut(){
	int i = 0 , j ;
	while( true ){
		if( contact[i].amount == 0 ){
			cout << endl ;
			break ;
		}
		if( contact[i].amount != contact[ i - 1 ].amount ){
			cnt = 0 ;
			currentOutPut++ ;
			if( currentOutPut != 1 )
			cout << endl ;
			if( currentOutPut > totOutPut)
			break ;
			cout << contact[i].amount << endl ;	
		}
		else{
			cnt++ ;
			if( cnt % 6 == 0 )
			cout << endl ;
			else
			cout << " " ;
		}
		for( j = 0 ; j < contact[i].length ; j++ )
			cout << contact[i].shortMessage[j] ;
		i++ ;
	}
	
}
int main(){
	std::ios::sync_with_stdio( false ) ;
	int i , j ;
	cin >> minLength >> maxLength >> totOutPut ;
	for( i = minLength ; i <= maxLength ; i++ )
	GetContact(i) ;
	while(getline( cin , input )){
		for( i = 0 ; i < input.length() ; i++ ){
			if(input[i] == '1')
				message[totMessage] = true ;
			else
				message[totMessage] = false ;
				Matching(totMessage) ;
				totMessage++ ;
		}
	}		
	sort( contact , contact + totContact , cmp ) ;
	OutPut() ;
	return  0 ;
	
	
}
