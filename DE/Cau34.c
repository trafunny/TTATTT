#include <stdio.h>
#include <math.h>
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

int checkSNT_Fermat(long long int n, long long int t){
    long long int a ,r ;
    
    for (long long int i= 0 , a=2 ; i<t&&a<n ; i++,a++ ){
        
        r = BP_lap(a,n-1,n);
    
        if(r!=1){
            printf ("\n%lld La Hop so",n);
            return 1;
        }
    }
    printf("\n%lld LA SNT ",n);
}

int main (){
    long long int n ,t;
    printf ("Nhap n va t :");
    scanf("%lld%lld",&n,&t);
    checkSNT_Fermat(n,t);
    

    return 0;
}