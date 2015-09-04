#include<iostream>
#include<string.h>
#include<algorithm>
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
using namespace std ;
const int MAXN = 2000 + 10 ;
int par[MAXN] , totText , totBugs , totSences , jack , mike ;
struct Node{
    int jack ;
    int mike ;
} ;
Node node[MAXN] ;
bool cmp(Node a, Node b){
    return a.jack < b.jack ;
    return a.mike < b.mike ;
}
int main(){
    int i , j ;
    while( cin >> totText ){
        for( i = 1 ; i <= totText ; i++ ){
            memset(par , 0 , sizeof(par)) ;
            bool ok = true ;
            cin >> totBugs >> totSences ;
            for( j = 0 ; j < totSences ; j++ ){
                cin >> jack >> mike ;
                node[j].jack = MIN(jack , mike) ;
                node[j].mike = MAX(jack , mike) ;
            }
            sort(node , node + totSences , cmp) ;
            for( j = 0 ; j < totSences ; j++ ){
                jack = node[j].jack ;
                mike = node[j].mike ;
                if( par[jack] == 0 && par[mike] == 0 ){
                    par[jack] = 1 ;
                    par[mike] = 2 ;
                }
                else if( par[jack] != 0 && par[mike] == 0){
                    par[mike] = 3 - par[jack] ;
                }
                else if( par[mike] != 0 && par[jack] == 0){
                    par[jack] = 3 - par[jack] ;
                }
                else if( par[mike] != 0 && par[jack] != 0){
                    if(par[mike] == par[jack])
                    ok = false ;
                }
            }
            cout << "Scenario #" << i << ":" << endl ;
            if(ok)
                cout << "No suspicious bugs found!" << endl << endl ;
                else
                cout << "Suspicious bugs found!" << endl  << endl ;
        }
    }
}  
