#include <stdio.h>


int main(){
    long long int n ;
    printf("Nhap n (n>=2) : ");
    scanf("%lld" ,&n);
    int check[n+1] ;
    for(long long int i=2; i<=n ;i++){
        check[i] =1;
    }
    for(long long int p=2 ; p<n ;p++){
        if(check[p]==1){
            for(long long int j =2*p ; j<=n ; j+=p){
                check[j] =0;
            }
        }
    }
    
    for(long long int i =2 ; i<=n ; i++){
        if(check[i]&&check[i+2]){
            printf ("(%lld ,%lld) la cap SNT can tim !\n",i,i+2);
        }
    }


    return 0;
}