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
	
	printf("������ӵ�������");
	scanf("%d",&totalMonkeys);
	printf("������ӱ����ĳ������֣�");
	scanf("%d",&stride);
	
	link=NULL;//�������� 
	for(int i=0;i<totalMonkeys;i++)
	{
		monkey=new Monkey;
		monkey->ID=i+1;
		if(link==NULL)//����Ϊ�գ������һֻ���� 
		link=lastMonkey=monkey;
		else//�����н�㣬���º��Ӽ�������ĩβ 
		{
			lastMonkey->next=monkey;
			lastMonkey=monkey;
		}
	} 
	lastMonkey->next=link;//����������һ�����ָ���һ����� 
	
	count=1;
	printf("���ӳ��ӵ�˳��"); 
	while(link!=NULL)
	{
		if(link->next==link)//ֻʣ���һֻ���� 
		{
			printf("%4d\n",link->ID);
			delete link;
			break;
		}
		if(count==stride-1)//linkָ��ĺ���֮�����ֻ����Ҫ���� 
		{
			monkey=link->next;
			link->next=monkey->next;//��monkeyָ��ĺ��ӳ��� 
			printf("%4d",monkey->ID);
			delete monkey;//ɾ����� 
			count=0;
		}
		link=link->next;
		count++;
	} 
	return 0;
}
