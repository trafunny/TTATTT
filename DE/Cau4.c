#include <stdio.h>
#include <math.h>
int main(){
    long long int   i,p,j ,a=10, b=20, dem =0;
    printf ("Nhap a ,b:");
    scanf ("%lld%lld",&a,&b);
    long long int check[b+1];
   
    for(i = a ; i<=b ; i++){
        check[i] = 1;
        
    }
    for ( p = 2 ; p < b ; p++){
            for(j= 2*p; j <= b ; j+=p ){
                check[j] =0;
                
            }
        
    }

    for(i=a ; i<=b ; i++){
        if(check[i]==1&&i>1){
            ++dem;

        }
    }
    printf ("So cac SNT la : %lld", dem);
    return 0;
}