#include <stdio.h>
int a,b=2;

int main(){
	while (true){
		scanf("%d",&a);
		b=2;
		while(a>=b){
			if (a%b==0){
				if (a==b){
					return 0;
				}
				else
					a=1;
			}
			else
				b++;
		}		
	}

	
	return 0;
}
