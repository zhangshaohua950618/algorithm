#include<iostream>
#include<string.h>
using namespace std ;
string str ;
int  subLength , totText , strLength , count , coverLength ;
int main(){
	int i , j , k ;
	cin >> totText ;
	for( i = 0 ; i < totText ; i++ ){
		count = 0 ;
		cin >> str >> subLength ;
		strLength = str.length() ;
		if( subLength * 2 <= strLength ){
		for( j = 0 ; j < subLength ; j++ )
			if( str[strLength - subLength + j] != str[j])
			count++ ;
		}
		else{
			coverLength = subLength * 2 - strLength   ;
			int dif = ( strLength - coverLength ) / 2;
		//	cout << dif << endl ;
			for( j = 0 ; j < coverLength ; j++ ){
				if((str[j] != str[j + dif]) && (str[j + dif] != str[j + dif * 2])){
					if(str[j] == str[j + dif * 2]){
						str[ j + dif] = str[j] ;
						count++ ;
					}
					else{
						str[j] = str[j + dif] ;
						str[j + dif * 2] = str[j + dif ] ;
						count += 2 ;
					}
				}
				else if( (str[j] == str[j + dif]) && (str[j + dif] != str[j + dif * 2])){
					str[j + dif * 2] = str[j] ;
					count++ ;
				}
				else if( (str[j] != str[j + dif]) && (str[j + dif] == str[j + dif * 2])){
					str[j] = str[j + dif] ;
					count++ ;
				}
				
			} 	
		}
		cout << count << endl ;
		
	}
}
