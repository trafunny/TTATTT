//Viết chương trình đếm số ước và số ước nguyên tố của một số N nhập vào từ bàn phím
#include <stdio.h>
#include <math.h>
int checkSNT(long long int n){
    if(n<2) return 0;
    for(long long int j =2 ; j<= sqrt(n) ; j++){
        
        if(n%j ==0 ) return 0;
    }

    return 1;
}

int main(){
    long long int  n ,k =0 , s =0;   //k :so uoc nguyen to , s :so uoc cua N
    printf("Nhap n :");
    scanf("%lld",&n);
    for(long long int i =1 ; i<=n; i++){
        if(n%i==0){
            ++s;
            if(checkSNT(i)==1){
                ++k;
            }

        }
    }

    printf ("So cac uoc cua n la : %lld \nSo cac uoc la SNT la : %lld",s,k);
    return 0;
}