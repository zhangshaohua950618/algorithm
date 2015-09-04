#include<stdio.h>
#include<string.h>
#define INF 100000000
#define maxn 1001
bool vis[maxn];
int adj[maxn][maxn],dis[maxn],pre[maxn];//pre[]记录前驱
int n, m;
void dijkstra(int v)
{
    int i, j, u , min;
    for(i=0;i<=n;i++)
    {
        dis[i]=adj[v][i];
        vis[i]=0;
        //if(i!=v&&adj[v][i]!=INF)pre[i] = v;
       // else pre[i] = -1;
    }
    vis[v]=1;dis[v]=0;
    for(i=1;i<n;i++)
    {
        min = INF;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&min > dis[j])
            {
                min = dis[j];
                u = j;
            }
        }
        if(min == INF)break;
        vis[u]=1;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&adj[u][j]!=INF&&dis[u]+adj[u][j]<dis[j])
            {
                dis[j] = adj[u][j] + dis[u];
              //  pre[j] = u;
            }
        }
    }
}
int main()
{
    int i, j, x, y, w;
    while(~scanf("%d%d",&n,&m)&&n)
    {
    	
    	//Initial 
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
                if(i==j)adj[i][j]=0;
                else adj[i][j] = INF;
        }
        //Input
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&w);
            adj[x][y] = w;
            adj[y][x] = w;
        }
        dijkstra(0);
        printf("%d\n",dis[n]);  //以下为输出路径
        /*int p, len=0, ans[maxn];
        p = n-1;
        while(p!=0)
        {
            ans[len++] = p;
            p = pre[p];

        }
        printf("0->");
        for(i=len-1;i>=0;i--)
            printf("%d",ans[i]);
        puts("");  */
    }
    return 0;
}
