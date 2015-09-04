#include<fstream>
using namespace std;
const int MAXN = 800+10;
const int MAX = 1 << 30;
int cows[MAXN];
int route[MAXN][MAXN];
int totCow , totFarm , totRoute ;
#define MIN(a , b) ((a) < (b) ? (a) : (b))
int main(){
	ifstream cin("butter.in");
	ofstream cout("butter.out");
	int i , j , k ;
	int farm , farmStart , farmEnd , distance , minDistance , tempDistance;
	cin>>totCow>>totFarm>>totRoute;
	for(i = 1 ; i <= totCow ; i++){
		cin>>farm;
		cows[farm]++;
	}
	for(i = 1 ; i <= totFarm ; i++)
	for(j = 1 ; j <= totFarm ; j++)
		route[i][j] = route[j][i] = i == j ? 0 : MAX ;
	for(i = 1 ; i <= totRoute ; i++){
		cin>>farmStart>>farmEnd>>distance;
		route[farmStart][farmEnd] = route[farmEnd][farmStart] = distance;
	}
	//Floyd
	for(k = 1 ; k <= totFarm ; k++)
	for(i = 1 ; i <= totFarm ; i++)
	for(j = 1 ; j <= totFarm ; j++)
	if(route[i][k] != MAX && route[k][j] != MAX)
	route[i][j] =  MIN(route[i][j] , route[i][k] + route[k][j]);
	minDistance  = MAX ;
	for(i = 1 ; i <= totFarm ; i++){
		tempDistance = 0;
			for(j = 1 ; j <= totFarm ; j++){
				if(route[i][j] != MAX)
				tempDistance += route[i][j] * cows[j] ;
		}
		if(tempDistance < minDistance)
		minDistance = tempDistance;
	}
	cout<<minDistance<<endl;
	return 0;
}
