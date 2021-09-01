#include <stdio.h>
#include <string.h>

int a;

int main (){
	scanf("%d",&a);
	char s[100]= "*";
	for(int i =1; i<=a; i++){
		printf("%s\n", s);
		strcat(s,"*");
	}
	
	return 0;
}
