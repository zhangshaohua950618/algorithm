#include<iostream>
#include<queue>
using namespace std;
priority_queue<int , vector<int> , greater<int> > q;
int cost , n , num;
int main(){
	int i;
	int a ,b , c;
	cin >> n;
	for(i = 0 ; i < n ; i++){
		cin >> num;
		q.push(num);
	}
	while(!q.empty()){
		a = 0 , b = 0;
		a = q.top();
		q.pop();
		b = q.top();
		q.pop(); 
		c = a + b;
		cost += c;
		if(q.empty())
		break;
		else
		q.push(c);
	}
	cout << cost << endl;
	return 0;
}
