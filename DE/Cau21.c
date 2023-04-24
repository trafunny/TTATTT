#include <stdio.h>
#include <math.h>
int isPrime(long long int n){
	long long int i;
    if(n<2) return 0;
    for(long long int i =2 ; i<= sqrt(n) ; i++){
        if(n%i ==0) return 0;
    }
    return 1;
}

int countPrime(long long int n){
    int d = 0,i;
    for( i = 2; i<n;i++)
        if(isPrime(i)==1)
            d+=1;
    return d;
}
int main(){
    long long int a, b, d=0,x;
    scanf("%lld%lld", &a, &b);
    while (a >= b || a < 0 || b <= 0){
        printf("Nhap 0 <= A < B!\n");
        scanf("%lld%lld", &a, &b);
    }
    for ( x = a; x < b; x++)
        if(isPrime(countPrime(x))==1){
            d++;
            // printf("\nSo %ld la sieu nguyen to vi co %ld SNT nho hon %ld",x,countPrime(x),x);
        }
    printf("%lld",d);
    return 0;
}