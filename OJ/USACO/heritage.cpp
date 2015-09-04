/*
ID: zhangsh35
PROG: heritage 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
const int MAXN=100;
struct node
{   char data;
    node *lchild,*rchild;
};
node *recovery(char *pre,char *in,int len);
void post(node *root);
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("heritage.in","r",stdin);
	freopen("heritage.out","w",stdout);
	#endif
     char pre[MAXN],in[MAXN];     
     node *root;
     while(cin>>in>>pre)
     {
        root=recovery(pre,in,strlen(pre));
        post(root);
        cout<<endl;
     }
     return 0;
}
void post(node *root)    
 { //后序遍历
     if(root)//不判断会无限递归，不科学 
     { 
         post(root->lchild);
         post(root->rchild);
         cout<<root->data;
     }
}
node *recovery(char *pre,char *in,int len) 
{ 
     if(len<=0) 
	 return NULL;
     node *t=new node;
     char *p;
     int pre_length=0;     
     t->data=*pre;
     for(p=in;p<in+len;p++)     
   	  {  
		 if(*p==*pre)  
		 break; 
	  } 
     pre_length=p-in;  
     t->lchild=recovery(pre+1,in,pre_length);
     t->rchild=recovery(pre+pre_length+1,p+1,len-pre_length-1);
     return t;
}

