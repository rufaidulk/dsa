#include <stdio.h>

int main(void)
{
   int x;
   double y;
   scanf("%d", &x);
   fflush(stdin);
   scanf("%lf", &y);
   printf("x=%d\n y=%lf\n",x, y);
   return 0;
}
