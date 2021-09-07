#include <stdio.h>

int a,b=1;

int factorial(int c){
	if(c==0)
		c=1;
	int f=c;
	if(c>1)
		return f*factorial(c-1);
	else
		return f;
}

int main(){
	scanf("%d",&a);
	printf("%d",factorial(a));
	return 0;
}
