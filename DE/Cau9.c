//Viết chương trình đếm số số nguyên tố nhỏ hơn hoặc bằng N với N được nhập vào từ bàn phím.
#include<stdio.h>

int main(){
    long long int n,dem=0 ;
    printf ("Nhap n :");
    scanf("%lld" , &n);
    int check[n+1];
    for(long long int i =2 ; i<=n ;i++){
        check[i]  =1 ;
    }
    for(long long int p =2 ; p<n ; p++){
        if(check[p]){
            for(long long int j= 2*p ; j<=n ; j+=p){
                check[j] =0;
            }
        }
    }

    for(long long int i= 2 ; i<=n ;i++){
        if(check[i]) {
            ++dem;
        }
    }
    printf("So cac SNT < n la :  %lld",dem);
    return 0;
}