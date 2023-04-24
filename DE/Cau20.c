#include <stdio.h> 

long long int UCLN(long long int a, long long int b){
    if(b==0) return a;
    else return UCLN(b,a%b);
    
}

int main(){
    long long int m,n,d ;
    printf ("Nhap n,m,d >0 : ");
    scanf ("%lld%lld%lld",&n,&m,&d);
    while (n>=m || m < 0 || n<=0 || m >= 1000 || n>=1000){
        printf("Nhap 0 <= n < m < 1000\n");
        scanf("%lld%lld", &n, &m);
    }
    
    long long int result ;
    for (long long int i = n ; i<=m ; i++ ){
        for(long long int j = i; j<=m ;j++){
            if(UCLN(i,j) == d &i!= 0 && j!=0){
                printf ("(a,b) = (%lld ,%lld)\n ",i,j);
            }

        }
    }


    return 0;
}