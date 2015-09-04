#include<stdio.h>
struct Monkey
{
	int ID;
	Monkey*next;
} ;
int main()
{
	Monkey*link,*monkey,*lastMonkey;
	int totalMonkeys,stride,count;
	
	printf("输入猴子的总数：");
	scanf("%d",&totalMonkeys);
	printf("输入猴子报数的出队数字：");
	scanf("%d",&stride);
	
	link=NULL;//建立链表 
	for(int i=0;i<totalMonkeys;i++)
	{
		monkey=new Monkey;
		monkey->ID=i+1;
		if(link==NULL)//链表为空，加入第一只猴子 
		link=lastMonkey=monkey;
		else//链表有结点，将新猴子加入链表末尾 
		{
			lastMonkey->next=monkey;
			lastMonkey=monkey;
		}
	} 
	lastMonkey->next=link;//将链表的最后一个结点指向第一个结点 
	
	count=1;
	printf("猴子出队的顺序："); 
	while(link!=NULL)
	{
		if(link->next==link)//只剩最后一只猴子 
		{
			printf("%4d\n",link->ID);
			delete link;
			break;
		}
		if(count==stride-1)//link指向的猴子之后的那只猴子要出队 
		{
			monkey=link->next;
			link->next=monkey->next;//让monkey指向的猴子出队 
			printf("%4d",monkey->ID);
			delete monkey;//删除结点 
			count=0;
		}
		link=link->next;
		count++;
	} 
	return 0;
}
