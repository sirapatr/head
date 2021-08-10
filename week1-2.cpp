#include <stdio.h>

int a,b,c,d;

int main()
{
	scanf("%d %d %d",&a,&b,&c);
	d=a;
	if (b>d)
		d=b;
	if (c>d)
		d=c;
	printf("%d",d);
	return 0;
}
