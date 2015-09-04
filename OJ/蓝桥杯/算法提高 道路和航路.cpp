#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int MAXN = 25000 + 10;
const int INF = (1<<30);
int t , r , p , s;
int start , end , len; 
int dis[MAXN];
struct Node{
	int end;
	int len;
};
vector<Node> path[MAXN];
bool vis[MAXN];
void spfa(int start){
	queue<int> q;
	int i , j;
	while(!q.empty())
	q.pop();
	for(i =0 ; i < MAXN ; i++){
		dis[i] = INF;
		vis[i] = false;
	}
	dis[start] = 0;
	vis[start] = true;
	q.push(start);
	while(!q.empty()){
		int i , j;
		int temp = q.front();
		vis[temp] = false;
		for(i = 0 ; i <= path[temp].size() ; i++){
			if(dis[temp] + path[temp][i].len < dis[i]){
				dis[i] = dis[temp] + path[temp][i];
				if(!vis[i]){
					q.push(i);
					vis[i] = true;
				}
			}
		}
		vis[temp] = false;
	}
	
}
int main(){
	
	Init(); 
	
	
	int i , j;
	cin >> t >> r >> p >> s;
	
	//¹«Â·
	for(i = 0 ;i < r ; i++){
		cin >> start >> end >> len;
		path[start].push_back((Node){end , len});
		path[end].push_back((Node){start , len});
	}
	//º½µÀ 
	for(i = 0 ; i < p ; i++){
		cin >> start >> end >> len;
		path[start][end] = len;
	}
	
	spfa(s);
	for(i = 1 ; i <= t ; i++){
		if(dis[i] == INF)
		cout << "NO PATH";
		else
		cout << dis[i];
		cout << " ";
	}
	cout << endl;
	return 0;
	
}
