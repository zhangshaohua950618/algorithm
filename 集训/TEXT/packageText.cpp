# include<stdio.h>
# include<string.h>

const int MAXN = 10000+5;	

double f[MAXN];
int a[MAXN];
double b[MAXN];
void pack(int n, int m)
{
  int i, j;
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for(i=1; i<MAXN; i++)
	  f[i] = 0;
  for(i=1; i<=m; i++)
	  scanf("%d%lf", &a[i], &b[i]);
  for(i=1; i<=m; i++)
	  for(j=n; j>=a[i]; j--)
	  {

		  if(1-(1-b[i])*(1-f[j-a[i]])>f[j])
		    f[j] = 1-(1-b[i])*(1-f[j-a[i]]);
	  }

}



int main(void)
{
	int n, m;
    while(scanf("%d%d", &n, &m)==2)
	{
		if(n==0 && m==0)
			break;
       pack(n, m);	
	   printf("%.1lf%%\n", 100*f[n]);
	}
  return 0;
}
