#include <stdio.h>

int a;
int fac(int a){
	int b=1;
	for(int i =1;i<=a;i++){
		b=b*i;
	}
	printf("%d",b);
}

int main(){
	scanf("%d",&a);
	fac(a);

	return 0;
}
