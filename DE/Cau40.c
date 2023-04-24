#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int isPrime(long long int n){
    if(n<2)
        return 0;
    if(n==2 || n==3)
        return 1;
    if(n%2==0 || n%3==0)
        return 0;
    for(long long int i=5;i<=sqrt(n);i+=6)
        if(n%i==0 || n%(i+2)==0)
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
    long long int n,d=0;
    printf("Nhap so phan tu cua mang: ");
    scanf("%lld",&n);
    long long int a[n];
    // srand((int)time(0));
    for(long long int i=0;i<n;i++){
         printf ("Nhap a[%lld] = ",i);
        scanf("%lld",&a[i]);
        while(a[i]<=0) {
            printf ("Nhap lai a[%lld] = ",i);
            scanf("%lld",&a[i]);
            
        }
    }   
    printf("\n");  
    for(long long int i=0;i<n-1;i++)
        for(long long int j=i+1;j<n;j++)
            if(isPrime(GCD(a[i],a[j]))==1){
                d+=1;
                // printf("a[%lld], a[%lld] , GCD(a[%lld],a[%lld]) = %lld\n",i,j,i,j,GCD(a[i],a[j]));
            }
    printf("Co tat ca %lld cap so thoa man!",d);          
}