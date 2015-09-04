/*
ID: zhangsh35
PROG: buylow 
LANG: C++
*/
#include<fstream>
#include<set>
using namespace std;
const int MAXN=5000+10;
long  days[MAXN];//��¼���� 
int len[MAXN];//��¼��󳤶�״̬ 
int  plans[MAXN][100+10];//��¼���ȷ��� ��Ŀ 
ifstream cin("buylow.in");
ofstream cout("buylow.out");
void equals(int num1[],int num2[]){
	int i;
	for(i=0;i<=num2[0]+2;i++){
		num1[i]=num2[i];
	}
}
void add(int num1[],int num2[]){
	int i,index=0,temp;
	int len=num1[0]>num2[0]?num1[0]:num2[0];
	for(i=1;i<=len+2;i++){
		temp=num1[i]+num2[i]+index;
		num1[i]=temp%10;
		index=temp/10;
	}
	for(i=len+2;i>=0;i--){
		if(num1[i]){
			num1[0]=i;
			break;
		}
	}
}
void display(int num[]){
	for(int i=num[0];i>=1;i--)
	cout<<num[i];
	cout<<endl;
}
int main(){

	std::ios::sync_with_stdio(false);
	pair <set<long>::iterator,bool> p;
	set<long> s;
	int Days,max_len,max_plans;
	int i,j;
	cin>>Days;
	days[0]=0x7fffffff;
	len[0]=0;
	plans[0][0]=1;//��¼���� 
	plans[0][1]=1;
	days[Days+1]=-0x7fffffff;
	for(i=1;i<=Days+1;i++){
		if(i<=Days)
		cin>>days[i];
		s.clear();
		max_len=0;
		for(j=i-1;j>=0;j--){//����	
			if(days[i]<days[j]){//��ִ�� 
				if(len[j]>max_len){
					s.clear();
					s.insert(days[j]);
					max_len=len[j];
					equals(plans[i],plans[j]);//plans[i]=plans[j];
				}
				else if(len[j]==max_len){
					p=s.insert(days[j]);
					if(p.second)
					add(plans[i],plans[j]);//plans[i]+=plans[j];
				}
			}
		}
		len[i]=max_len+1;
	//	cout<<"i= "<<i<<" "<<len[i]<<" "<<plans[i]<<endl;
	}
	cout<<len[Days+1]-1<<" ";
	display(plans[Days+1]);
	return 0;
}
