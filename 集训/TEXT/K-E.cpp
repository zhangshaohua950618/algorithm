#include <stdio.h>  
    #include <string.h>  
    #define INF 2100000000  
    #define MAXN 301  
      
    int SAP(int map[][MAXN],int v_count,int s,int t)      //�ڽӾ��󣬽ڵ�������ʼ�㣬���  
    {  
        int i;  
        int cur_flow,max_flow,cur,min_label,temp;         //��ǰ�������������ǰ�ڵ㣬��С��ţ���ʱ����  
char flag;                                        //��־��ǰ�Ƿ��п�����  
int cur_arc[MAXN],label[MAXN],neck[MAXN];         //��ǰ������ţ�ƿ���ߵ���㣨������ô�аɣ�  
int label_count[MAXN],back_up[MAXN],pre[MAXN];    //���Ϊi�ڵ��������cur_flow�ļ�¼,��ǰ��·����ǰ��  
      
        //��ʼ��  
        memset(label,0,MAXN*sizeof(int));  
        memset(label_count,0,MAXN*sizeof(int));  
      
        memset(cur_arc,0,MAXN*sizeof(int));  
        label_count[0]=v_count;                           //ȫ����ʼ��Ϊ����Ϊ0  
      
        neck[s]=s;  
        max_flow=0;  
        cur=s;  
        cur_flow=INF;  
      
        //ѭ������ݹ�  
while(label[s]<v_count)  
        {  
            back_up[cur]=cur_flow;  
            flag=0;  
      
            //ѡ������·�����˴��������ڽӱ��Ż���  
for(i=cur_arc[cur];i<v_count;i++)    //��ǰ���Ż�  
            {  
               if(map[cur][i]!=0&&label[cur]==label[i]+1)    //�ҵ�����·��  
               {  
                   flag=1;  
                   cur_arc[cur]=i;    //���µ�ǰ��  
if(map[cur][i]<cur_flow)    //���µ�ǰ��  
                   {  
                       cur_flow=map[cur][i];  
                       neck[i]=cur;     //ƿ��Ϊ��ǰ�ڵ�  
                   }  
                   else  
                   {  
                       neck[i]=neck[cur];     //ƿ�����ǰ���ڵ㲻��  
                   }  
                   pre[i]=cur;    //��¼ǰ��  
                   cur=i;  
                   if(i==t)    //�ҵ�������  
                   {  
                       max_flow+=cur_flow;    //���������  
      
                       //�޸Ĳ�������  
while(cur!=s)  
                       {  
                           if(map[pre[cur]][cur]!=INF)map[pre[cur]][cur]-=cur_flow;  
                           back_up[cur] -= cur_flow;  
                           if(map[cur][pre[cur]]!=INF)map[cur][pre[cur]]+=cur_flow;  
                           cur=pre[cur];  
                       }  
      
                       //�Ż���ƿ��֮��Ľڵ��ջ  
                       cur=neck[t];  
                       cur_flow=back_up[cur];   
                   }  
                   break;  
               }  
            }  
            if(flag)continue;  
      
            min_label=v_count-1;    //��ʼ��min_labelΪ�ڵ�����-1  
      
            //�ҵ����ڵı����С�Ľڵ�     
for(i=0;i<v_count;i++)  
            {  
                if(map[cur][i]!=0&&label[i]<min_label)  
                {  
                    min_label=label[i];  
                    temp=i;  
                }  
            }  
            cur_arc[cur]=temp;    //��¼��ǰ�����´δ��ṩ��С��ŵĽڵ㿪ʼ����  
            label_count[label[cur]]--;    //�޸ı�ż�¼  
if(label_count[label[cur]]==0)break;    //GAP�Ż�  
            label[cur]=min_label+1;    //�޸ĵ�ǰ�ڵ���  
            label_count[label[cur]]++;     //�޸ı�ż�¼  
if(cur!=s)  
            {  
               //��ջ�е���һ���ڵ�  
               cur=pre[cur];  
               cur_flow=back_up[cur];  
            }  
        }  
        return(max_flow);  
    }
