#include<iostream>
#include<vector>
#define MAX(a , b) ((a) > (b) ? (a) : (b))
using namespace std ;
struct Pack{
	int price ;
	int importance ;
	int parent ;
} ;
typedef vector<Pack> v ;
v p[60 + 10] ;
int f[32000 + 10] , N , M ;
void GetPack(int price , int importance , int parent , int i){
	importance *= price ;
	p[i].push_back((Pack){price , importance , parent}) ;
	if(parent){
	p[parent].push_back((Pack){price + p[parent][0].importance , importance + p[parent][0].importance ,parent});
	if(p[parent].size() == 3)
	p[parent].push_back((Pack){price + p[parent][1].importance , importance + p[parent][1].importance ,parent});
	}
}
int SlovePack(){
	for(int i = 1 ; i <= N ; i++){
		if(p[i][0].parent == 0){
		for(int j = M ; j >= 0 ; j--)
			for(int k = 0 ; k < p[i].size() ; k++)
			if(j - p[i][k].price >= 0)
			f[j] = MAX(f[j] , f[j - p[i][k].price] + p[i][k].importance) ;
		}
	}	
	return f[M] ;
}
int main(){
	int  pri , imp , par ;
	while(cin >> M >> N){
		for(int i = 1 ; i <= N ; i++){
			p[i].clear() ;
			cin >> pri >> imp >> par ; 
		   GetPack(pri , imp , par , i) ;
		}
		cout << SlovePack() << endl ;
	}
}

