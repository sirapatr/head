#include <stdio.h>

char a[100];

int main (){
	char* ptr;
	ptr = a;
	scanf("%s",a);
	while(*ptr != '\0'){
		if(*(ptr+1)=='\0'){
			printf("%c",*ptr);
		}
		ptr++;
	}

	return 0;
}
