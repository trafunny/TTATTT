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
int main(){
    long long int a, b, d=0;
    printf ("Nhap a , b : ");
    scanf("%lld%lld", &a, &b);
    while (a >= b || a < 0 || b <= 0){
        printf("Nhap 0 <= A < B!\n");
        scanf("%lld%lld", &a, &b);
    }
    for(long int i = a; i<b;i++)
        if(isPrime(i)==1)
            d+=i;
    if(isPrime(d)==1)
        printf("YES %lld",d);
    else printf("NO %lld",d); 
    return 0;
}