#include<iostream>
using namespace std ;
void sift( int R[] , int low , int high){
	int  i = low ,j = 2 * i ;
	int temp = R[i] ;
	while( j <= high ){
		if( j < high && R[j] < R[j+1])
		j++ ;
		if(temp < R[j]){
			R[i] = R[j] ;
			i = j ;
			j = 2 * i ;
		}
		else
		break ;
	}
	R[i] = temp ;
}
void HeapSort(int R[] , int  n){
	int i ;
	int temp ;
	for( i = n / 2; i >= 1 ; i-- )
	sift(R , i, n) ; 
	for( i = n / 2 ; i >= 1 ; i-- ){
		temp = R[1] ;
		R[1] = R[i] ;
		R[i] = temp ;
		sift(R,1,i - 1) ;
	}
}
int main(){
	int a[] = { 2 ,3, 44, 0} ;
	HeapSort(a,3) ;
	for( int i= 0 ; i < 4 ; i++ )
	cout << a[i] << endl ;
	return 0 ;
}
