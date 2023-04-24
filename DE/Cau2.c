#include <stdio.h>
#include <math.h>


int main() {
    long long int a ,b , dem=0;
    int n =5; 
    a = (long long int )ceil(pow(10,n-1)); // XAC DINH DOAN [a,b] co n c/s
    b = (long long int)ceil(pow(10,n) -1) ;
    // printf ("%lld",b);
    int check[b+1] ;
    for (long long int i= a; i<=b ; i++){
        check[i] = 1;
    }
    printf ("check [4] = %d\n",check[4]);
    for(long long int p=2 ; p <=b/2 ; p++){
        // if(check[p]!=0){
            for(long long int j = 2*p ; j <=b ; j+=p){
                check[j] =0;
            }
        // }
    }
    for(long long int i=a ; i<=b ; i++){
        if(check[i])
        {
            printf ("%lld ",i); ++dem;
        } 
    }
    printf  ("/n dem = %lld",dem);

    return 0;
}