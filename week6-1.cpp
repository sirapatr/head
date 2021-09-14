#include <stdio.h>

char a[100];
bool IsBack;
int b=99;

int main (){
	scanf("%s",a);
	while(!IsBack){
		if(a[b]!='\0')
		{
			printf("%c",a[b]);
			IsBack = true;
		}
		else
			b--;
	}
	return 0;
}
