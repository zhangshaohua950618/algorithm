#include<iostream>
using namespace std ;
const int  MAXN =  10000 + 10 ;
int par[MAXN] ;
int totText , totCriminals  , totMessages ,jack , simmon  ;
char command ;
int main(){
	int  i , j ;
	cin >> totText ;
	for( i = 0 ; i < totText ; i++ ){
		cin >> totCriminals >> totMessages ;
		for( j = 1 ; j <= totCriminals ; j++ ){
			par[j] = 0 ;
		}
		for( j = 0 ; j < totMessages ; j++  ){
			cin >> command >> jack >> simmon ;
			switch(command){
				case 'A' :{
					if(par[jack] * par[simmon] == 0){
						cout << "Not sure yet." << endl ;
						break ;
					}
					else if( par[jack] == par[simmon]){
						cout << "In the same gang." << endl ;
						break ;
					}
					else if(par[jack] != par[simmon]){
						cout << "In different gangs." << endl ;
						break ;
					}
				}
				case'D' :{
					if(par[jack] == 0 && par[simmon] == 0){
						par[jack] = 1 ;
						par[simmon] = 2 ;
						break ;
					}
					else if(par[jack] == 0 && par[simmon] != 0 ){
						par[jack] = 3 - par[simmon] ;
						break ;
					}
					else if(par[jack] != 0 && par[simmon] == 0 ){
						par[simmon] = 3 - par[jack] ;
						break ;
					}
					else if( par[jack] != 0 && par[simmon] != 0){
						break ;
					}
					
				}
			}
		}
	}
	
}
