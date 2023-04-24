#include <stdio.h>
#include <math.h>

int isPrime(long long int n){
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (long int i = 5; i <= sqrt(n); i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}
long long int GCD(long long int a, long long int b){
    if(a<b)
        return GCD(b,a);
    if(a%b==0)
        return b;
    return GCD(b,a%b);
}
int main(){
    long long int a, b;
    printf("Nhap khoang (a,b) : ");
    scanf("%lld%lld", &a, &b);
    while (a >= b || a<= 0 || b <= 0 || b>=1000 || a>=1000){
        printf("Nhap 0 < A < B <1000!\n");
        scanf("%lld%lld", &a, &b);
    }   
    for(long long int i=a;i<b;i++)
        for(long long int j=i+1;j<=b;j++)
            if(isPrime(GCD(i,j))==1)
                printf("a = %lld, b = %lld, GCD(a,b) = %lld\n",i,j,GCD(i,j));
    return 0;
}