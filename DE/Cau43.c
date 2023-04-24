#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int checkSNT(long long int n){
    if(n<2) return 0;
    for(long long int i=2 ; i<= sqrt(n) ; i++){
        if(n %i ==0) return 0;
    }
    return 1;
}
long long int BP_lap(long long int a , long long int k , long long int n){
    long long int c,A;
    c=1 ; A =a%n ;
    
    if(k%2==1){
        c =a;
    }
    k = k/2 ; 
    while(k>0){
        A = (A*A)%n;
        if(k%2==1){
            c = (c*A)%n;
        }
        k/=2;
    }
    return c; 
} 
int main()
{
    int i,e,p,n,t,check;
    printf("\nNhap N (0<N<1000): "); scanf("%d",&n);
	while(n>=1000 || n<0 ){
		printf("\nNhap lai N (0<N<1000): "); scanf("%d",&n);
	}
		p:
		check=0;
		p= 2+rand()%(99);	// Min + Rand % (Max + 1 - Min)
		for(i=2;i<=sqrt(p);i++)
		{
			if (p%i==0) check=1;
		}
		if (check==1) goto p;
		
		printf("Gia tri cua p= %d\n",p);
		printf("Nhung so a thoa man de bai la: ");
		
		for(int i =1 ; i <=n ;i++){
            if(checkSNT(BP_lap(i,p,n))==1){
                printf ("%d   ",i);
            }

        }		
		
	
}