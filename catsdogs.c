#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
	    long c,d,l;
	    scanf("%ld %ld %ld",&c,&d,&l);
	    if((l%4!=0)||(l < 4*d)){
	        printf("no\n");
	    }else{
	        long remain = l - 4*d;
            long cats_on_top = c - remain/4;
            if(cats_on_top < 0){
                printf("no\n");
            }else{
                if((cats_on_top+1)/2 > d){
                    printf("no\n");
                }else{
                    printf("yes\n");
                }
            }
	    }
	}
	
	return 0;
}

