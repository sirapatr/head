#include <stdio.h>

int a,b=1;
int c[3];


int main()
{
	scanf("%d",&a);
	while(b>0){
	
		for (int i=2; i>=0; i--) {
			c[i] = a%10;
			a = a/10;
		}
		b=c[0]*c[1]*c[2];
		printf("%d.%d.%d = %d\n", c[0],c[1],c[2], b);
		a=b;
	}
	return 0;
}
