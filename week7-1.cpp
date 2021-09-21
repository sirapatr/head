#include <stdio.h>

char a[50],b[50],c[50],d[50],e[50];
int i=0,j=0,k=0,l=0,m,n=0,o;

int main(){
	scanf("%s",a);
	while(a[i] !=','){
		i++;
	}
	o=i+1;
	while(a[o] !='\0'){
		b[j]=a[o];
		j++;
		o++;
	}
	while(i>0){
		c[k]=a[i-1];
		k++;
		i--;
	}
	while(j>0){
		d[l]=b[j-1];
		l++;
		j--;
	}
	int p=0;
	for(int x =0;x<50;x++){
		if(c[x]!='\0' && d[x] !='\0'){
			m=c[x]-'0'+d[x]-'0'+n;
			e[x]=m%10 +'0';
		}
		
		if(c[x]=='\0' && d[x]=='\0'){
		}
		else if(c[x]=='\0'){
			m= d[x]-'0'+n;
			e[x]=m%10+ '0';
		}
		else if(d[x]=='\0'){
			m= c[x]-'0'+n;
			e[x]=m%10 +'0';	
		}
		else if(c[x]=='\0' && d[x]=='\0'&&n==1){
			e[x]='1';
		}
		
		if(m>9){
			n=1;
			m=0;
		}
		else{
			n=0;
			m=0;
		}
		
	}

	while(e[p] !='\0'){
		p++;
	}
	while(p>0){
		printf("%c",e[p-1]);
		p--;
	}	
	return 0;
}
