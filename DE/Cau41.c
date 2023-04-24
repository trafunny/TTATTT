#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
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
int main(){
    srand((int)time(0));
    long long int a,k,n;
    
    printf ("Nhap a, k ,n :");
    scanf("%lld%lld%lld",&a,&k,&n);
    while (a<=0 || k<=0 || n<=0 || a>=1000 || n>=1000|| k>=1000  ){
        printf ("Nhap lai a,k,n = (0,1000): ");
        scanf("%lld%lld%lld",&a,&k,&n);


    }
    long long int x = BP_lap(a,k,n);
    if(checkSNT(x)==1)
        printf("%lld^%lld mod %lld = %lld la SNT",a,k,n,x);
    else printf("%lld^%lld mod %lld = %lld khong la SNT",a,k,n,x);
}