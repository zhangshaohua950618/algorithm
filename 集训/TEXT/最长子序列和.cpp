#include<iostream>
using namespace std;
int number[100];
int main()
{
	int num,i,sum,max,begin=0,end=0;
	while(cin>>num){
		begin=0;
		end=0;
		max=-0x7fffffff;
		sum=0;
		for(i=0;i<num;i++)
			cin>>number[i];
		for(i=0;i<num;i++){
			sum+=number[i];//sum记录非负前缀到j的和
			if(sum>max){
				max=sum;
				end=i;
			}
			if(sum<0){
				sum=0;
				begin=i+1;
			}
		}
		cout<<max<<endl;
		cout<<"begin = "<<begin<<" "<<endl;
		cout<<"end = "<<end<<" "<<endl;
	}
}
