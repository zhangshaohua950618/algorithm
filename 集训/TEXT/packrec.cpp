#include<iostream>
#include<set>
using namespace std;
void dfs(int num);
int max(int a,int b);
bool cc[4];
struct Rectangle
{
	int p;
	int q;
};
int Min=100000;
set<int> res; 
Rectangle temp_rectangle[4];
Rectangle rectangle[4];
int main()
{
	
	int i,j;
	int width,height;
	for(i=0;i<4;i++)
	{
	//	cin>>width>>height;
		cin>>rectangle[i].p;//=width<height?width:height;
		cin>>rectangle[i].q;//=width>height?width:height;
	}
	dfs(0);
/*	for(i=0;i<4;i++)
	{
		int temp;
		temp=rectangle[i].p;
		rectangle[i].p=rectangle[i].q;
		rectangle[i].q=temp;
	}
	dfs(0);*/
	cout<<Min<<endl;
	set<int>::iterator it;
	for(it=res.begin();it!=res.end();it++)
	{
		cout<<*it<<" "<<Min/(*it)<<endl;
	}
	
}
int max(int a,int b)
{
	return a>b?a:b;
}
void dfs(int num)
{
	if(num==4)
	{
		int min_p,min_q,square;
		//方案一
		min_p=temp_rectangle[0].p+temp_rectangle[1].p+temp_rectangle[2].p+temp_rectangle[3].p;
		min_q=max(temp_rectangle[0].q,max(temp_rectangle[1].q,max(temp_rectangle[2].q,temp_rectangle[3].q)));	
	/*	cout<<"min_p="<<min_p<<" min_q="<<min_q<<endl;  
		cout<<temp_rectangle[0].p<<" "<<temp_rectangle[0].q<<endl;
		cout<<temp_rectangle[1].p<<" "<<temp_rectangle[1].q<<endl;
		cout<<temp_rectangle[2].p<<" "<<temp_rectangle[2].q<<endl;
		cout<<temp_rectangle[3].p<<" "<<temp_rectangle[3].q<<endl;*/
		square=min_p*min_q;
		if(square<=Min)
		{
		
			if(square<Min)
			res.clear();
			res.insert(min_p<min_q?min_p:min_q);
		//	cout<<"方案一"<<endl;
			Min=square;
		}
		//方案二
		min_p=max(temp_rectangle[3].q,temp_rectangle[0].p+temp_rectangle[1].p+temp_rectangle[2].p);
		min_q=temp_rectangle[3].p+max(temp_rectangle[0].q,max(temp_rectangle[1].q,temp_rectangle[2].q));
		square=min_p*min_q;
		if(square<=Min)
		{
			
			if(square<Min)
			res.clear();
			res.insert(min_p<min_q?min_p:min_q);
		//	cout<<"方案二"<<endl;
			Min=square;	
		}
		//方案三
		min_p=max(temp_rectangle[0].p+temp_rectangle[1].p,temp_rectangle[2].q)+temp_rectangle[3].p;
		min_q=max(temp_rectangle[3].q,max(temp_rectangle[0].q,temp_rectangle[1].q)+temp_rectangle[2].q);
		square=min_p*min_q;
		if(square<=Min)
		{
			
			if(square<Min)
			res.clear();
			res.insert(min_p<min_q?min_p:min_q);	
		//	cout<<"方案三"<<endl;
			Min=square;
		}
		//方案四
		 min_p=max(temp_rectangle[1].p,temp_rectangle[2].p)+temp_rectangle[0].p+temp_rectangle[3].p;
		 min_q=max(temp_rectangle[0].q,max(temp_rectangle[1].q+temp_rectangle[2].q,temp_rectangle[3].q));
		square=min_p*min_q;
		if(square<=Min)
		{
		
			if(square<Min)
			res.clear();
			res.insert(min_p<min_q?min_p:min_q);
		//	cout<<"方案四"<<endl;	
			Min=square;
		}
		//方案五 
		min_p=max(temp_rectangle[0].p,temp_rectangle[1].p)+temp_rectangle[2].p+temp_rectangle[3].p;
		min_q=max(temp_rectangle[3].q,max(temp_rectangle[2].q,temp_rectangle[1].q+temp_rectangle[0].q));
		square=min_p*min_q;
		if(square<=Min)
		{
			//cout<<square<<Min<<endl;
			cout<<min_p<<" "<<min_q<<endl;
			if(square<Min)
			res.clear();
			res.insert(min_p<min_q?min_p:min_q);	
		//	cout<<"方案五"<<endl;
			Min=square;
		}
		//方案六
		min_p=max(temp_rectangle[0].p+temp_rectangle[3].q,temp_rectangle[1].p+temp_rectangle[2].q);
		min_q=max(temp_rectangle[0].q+temp_rectangle[1].q,temp_rectangle[2].q+temp_rectangle[3].p); 
		square=min_p*min_q;
		if(square<=Min)
		{
		//		cout<<square<<Min<<endl;
			cout<<min_p<<" "<<min_q<<endl;
			if(square<Min)
			res.clear();
			res.insert(min_p<min_q?min_p:min_q);	
	//		cout<<"方案六"<<endl; 
			Min=square;
		}	
	}
	else//搜索全排列 
	{
		int i;
		for(i=0;i<4;i++)
		{
			if(!cc[i])
			{
				temp_rectangle[num].p=rectangle[i].p;
				temp_rectangle[num].q=rectangle[i].q;
				cc[i]=true;
				dfs(num+1);
				cc[i]=false;	
				temp_rectangle[num].p=rectangle[i].q;
				temp_rectangle[num].q=rectangle[i].p;
				cc[i]=true;
				dfs(num+1);	
				cc[i]=false;
			}
		}
		
	}
}
