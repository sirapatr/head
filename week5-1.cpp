#include <stdio.h>

int a,b=1;

int main(){
	scanf("%d",&a);
	for(int i =1;i<=a;i++){
		b=b*i;
	}
	printf("%d",b);

	return 0;
}
