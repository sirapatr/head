#include <stdio.h>
int x,y;

int main (){
	scanf("%d %d",&x,&y);
	x=x+y;
	y=x-y;
	x=x-y;
	printf("%d %d",x,y);
}
