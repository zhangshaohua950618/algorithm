#include <stdio.h>
long sum = 0, upperlim = 1;
void test(long row, long ld, long rd)
{
   if (row != upperlim)
   {
 	 long pos = upperlim & ~(row | ld | rd);
 	 printf("%d\n",pos) ;
 	 while (pos)
 	 {
 		long p = pos & -pos;
 		pos -= p;
 		test(row + p, (ld + p) << 1, (rd + p) >> 1);
 	 }
   } else
 	sum++;
}
int main()
{
   int n ;
   scanf("%d",&n) ;
   upperlim = (upperlim << n) - 1;
   test(0, 0, 0);
   printf("共有%ld种排列 \n", sum);
}
