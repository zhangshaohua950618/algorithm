#include<iostream>
using namespace std; 
int N , num[20] ;
void qsort(int a[] , int l , int r){
	if(l < r){
		int i = l ;
		int j = r ;
		int x = a[i] ;
		while(i < j){
		while(i < j && a[j] > x)
		j-- ;
		if(i < j)
		a[i++] = a[j] ;
		while(i < j && a[i] <= x)
		i++ ;
		if(i < j)
		a[j--] = a[i] ;
		}
		a[i] = x ;
		qsort(a , l , i - 1) ;
		qsort(a , i + 1 , r) ;
	}
}
int main(){
	cin >> N ;
	for(int i = 0 ;i < N ; i++)
	cin >> num[i] ;
	qsort(num , 0, N - 1) ;
	for(int i = 0 ; i < N ; i++)
	cout << num[i] << endl ;
	return 0 ;
}