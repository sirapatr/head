#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a[50],b[50],i[5];
int h=0;

int main (){
  scanf("%s",a);
  char* c = strtok(a,",");
  char* d = strtok(NULL,",");
  int e = strlen(c);
  int f = strlen(d);
  while(e >0 || f>0){
  	int g=0;
  	if(e<=0){
  		g = (d[f-1]+ h-'0');
  	}
  	else if(f<=0){
  		g = (c[e-1]+ h-'0');
	}
	else{
		g = (c[e-1] +d[f-1]+ h-2*'0');
	}
  	if(g>9){
  		g %=10;
  		h=1;
	  }
	else{
		h=0;
	}
	itoa(g,i,10);
  	strcat(b,i);
	  e--;
	  f--;	
  }
  for(int i =strlen(b)-1; i>=0;i--){
  	printf("%c",b[i]);
  }
  return 0;
}
