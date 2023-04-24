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
    long long int n, i, j, check=0;
    printf ("Nhap n : ");
    scanf("%lld", &n);
    for(i = 4; i<n;i++)
        for(j=2;j<=sqrt(i);j++)
            if(isPrime(j)==1 && i%j==0 && i%(j*j)==0){
                check=1;
                printf("%lld chia het cho %lld va %lld^2\n",i,j,j);
            }
    if(check==0)    
        printf("Khong co so thoa man!");               
    return 0;
}