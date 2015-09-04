#include<queue>
#include<iostream>
using namespace std;
struct Node{
	int x;
	int y;
};
priority_queue<Node> q;
bool operator <(Node a , Node b){
	return a.x > b.x;
}
int main(){
	q.push((Node){3 , 4});
	q.push((Node){2 , 4});
	q.push((Node){1 , 4});
	q.push((Node){0 , 4});
	while(!q.empty()){
		Node temp =  q.top();
		cout << temp.x << " " << temp.y << endl;
		q.pop();
	}
	return 0;
}
