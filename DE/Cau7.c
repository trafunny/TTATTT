#include <stdio.h>
#include <math.h>
long long int reverse(long long int a){
    long long int rev=0;
    while(a>0){
        rev = rev*10 + a%10;
        a = a/10;
    }
    return rev;
}
int checkSNT (long long int n){
    if(n <2) return 0;
    
    for(long long int i =2 ; i<= sqrt(n)  ; i++){
            if(n%i ==0 ) return 0;
        }
    
    return 1; 

}
int main(){
    long long int N ;
    printf("Nhap N :");
    scanf("%lld",&N);
    for (long long int i =2 ; i<=N ; i++){
        if(checkSNT(i)&&checkSNT(reverse(i))){
            printf ("%lld   ",i);
        }
    }
    return 0;
}