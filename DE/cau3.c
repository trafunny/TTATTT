#include <stdio.h>
#include <math.h>
int checkSNT(long long int n){
    if(n<2) return 0;
    else for(long long int i =2 ; i<= sqrt(n); i++){
        if(n%i ==0){
            return 0;
        }
    }
    return 1;
}

int main() {
    long long int n;
    printf ("Nhap N : ");
    scanf("%lld",&n);
    while(n<=0){
        printf ("Nhap lai N : ");
        scanf("%lld",&n);

    }
    long long int k=0,q=0,p=0,s =0 ;
    
    
    for (long long int i =1 ; i<= n ; i++){
        if(n%i == 0){
            ++s;       //Dem uoc
            p+=i;      // Tong uoc
            
            if(checkSNT(i)==1) {
                ++k;   // DEM UOC SNT
                q+= i;
            }
            

        }

    }
    long long int result = n + p +s - q - k ;
    printf ("result =%lld+%lld+%lld - %lld -%lld = %lld ",n,p,s,q,k, result);


    return 0;
}