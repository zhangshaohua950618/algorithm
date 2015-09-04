#include<iostream>
using namespace std ;
const int MAXN  = 100 ;
int num[MAXN] , temp[MAXN] ;
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;
	
	while (i <= m && j <= n)
			temp[k++] = a[i] <= a[j] ? a[i++] : a[j++];
	while (i <= m)
		temp[k++] = a[i++];
	while (j <= n)
		temp[k++] = a[j++];
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
	if(first < last){
		int mid = (first + last) / 2 ;
		mergesort(a , first , mid , temp) ;
		mergesort(a , mid + 1 , last , temp) ;
		mergearray(a , first , mid , last ,temp) ;
	}
}

bool MergeSort(int a[], int n)
{
	int *p = new int[n];
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
}
int main(){
	int n ;
	cin >> n ;
	for(int i = 0 ;i < n ; i++)
	cin >> num[i] ;
	MergeSort(num , n) ;
	for(int i = 0 ; i < n ; i++)
	cout << num[i] << " "  ;
	cout << endl ;
	return 0 ;
}