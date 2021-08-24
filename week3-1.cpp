#include <stdio.h>

int a,b=1,c,d,e;

int main()
{
	scanf("%d",&a);
	while(b>0){
		e=a%10;
		a=a/10;
		d=a%10;
		a=a/10;
		c=a;
		b=c*d*e;
		printf("%d.%d.%d=%d\n",c,d,e,b);
		a=b;
	}
	return 0;
}
