/*
ID: zhangsh35
PROG: gift1 
LANG: C++
*/
#include<fstream>
#include<algorithm>
using namespace std;
struct Person
{
	string name;
	int money;
	int org;
};
const int MAXN=10+10;
int main()
{
	ifstream cin("gift1.in") ;
	ofstream cout("gift1.out") ;
	int tot,num;
	string person_out,person_in;
	int money_out;
	int i,j,k;
	Person person[MAXN];
	cin>>tot;
	for(i=0;i<tot;i++){
	
		cin>>person[i].name;
		person[i].money=0;
	}
	for(i=0;i<tot;i++){
	
		cin>>person_out;
		cin>>money_out>>num;
		for(k=0;k<tot;k++){
		
			if(person[k].name==person_out){
			
				person[k].org=money_out;
				if(num!=0)//不筛选掉0会报错的，除数不能为0.。 
				person[k].money+=money_out%num;
				break;
			}
		}
		for(j=0;j<num;j++){
			cin>>person_in;
			for(k=0;k<tot;k++){		
				if(person[k].name==person_in){		
					person[k].money+=money_out/num;
					break;
				}
			}
		}
	}
		for(j=0;j<tot;j++)
	{
		cout<<person[j].name<<" "<<person[j].money-person[j].org<<endl;
	}

}

