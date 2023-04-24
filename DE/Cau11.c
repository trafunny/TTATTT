#include <stdio.h>

int main(){
    long long int n ,tong =0 ;
    printf ("Nhap n :");
    scanf("%lld",&n);
    int check[n+1] ;
    for(long long int i =2 ; i<=n; i++){
        check[i] =1;

    }

    for(long long int p=2 ; p<n ;p++ ){
        if(check[p]==1){
            for(long long int j = 2*p ; j<=n ; j += p){
                check[j] =0;
            }
        }
    }

    for(long long int i =2 ; i<=n ; i++){
        if(check[i]==1){
            tong = tong +i;

        }  
    }

    printf ("Tong cac SNT < n : %lld" , tong);
    return 0;
}