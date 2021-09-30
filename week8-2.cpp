#include <stdio.h>
int x,y;

int main (){
	scanf("%d %d",&x,&y);
	if (x==0){
		x=y;
		y=0;
	}
	else if(y==0){
		y=x;
		x=0;
	}
	else{
		x=x*y;
		y=x/y;
		x=x/y;
	}
	printf("%d %d",x,y);
}
