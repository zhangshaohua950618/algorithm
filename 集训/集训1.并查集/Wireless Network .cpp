#include<iostream>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std ;
const int MAXN = 1001 + 10 ;
bool path[MAXN][MAXN] ;
struct Point{
	int x ;
	int y ;
	bool ok ;
};
double GetDis( Point a ,Point b ){
	return sqrt((double)pow(a.x - b.x,2) + (double)pow(a.y - b.y,2)) ;
}
Point point[MAXN] ;
int totPoint , maxDis ;
queue<int> que ;
char command ;
bool inque[MAXN] ;
int main(){
	int i , j , p ,q ; 
	while( cin >> totPoint >> maxDis){
		for( i = 1 ; i <= totPoint ; i++ ){
			cin >> point[i].x >> point[i].y ;
			point[i].ok = false ;
		}
		memset(path , false , sizeof(path)) ;
		while( cin >> command ){
			switch(command){
				case 'O':{
					cin >> p ;
					point[p].ok = true ;
					for( i = 1 ; i <= totPoint ; i++ ){
						if(point[i].ok && (GetDis(point[i],point[p])) <= maxDis)
						path[i][p] = path[p][i] = true ;
					}
					break ;
				}
				case 'S':{
					cin >> p >> q ;
					bool ok = false ;
					while(!que.empty()){
						que.pop() ;
					}
					memset(inque , false , sizeof(inque)) ;
					que.push(p) ;
					inque[p] = true ;
					while(!que.empty()){
						int  start = que.front() ;
						if(start == q){
							ok = true ;
							break ;
						}
						que.pop() ;
						for( j = 1 ; j <= totPoint ; j++ ){
							if(path[start][j] && inque[j] == false){
								que.push(j) ;
								inque[j] = true ;
							}
						}
					}
					if(ok)
					cout << "SUCCESS" << endl ;
					else
					cout << "FAIL" << endl ;
					break ;
				}
			}
		}
	}
}
