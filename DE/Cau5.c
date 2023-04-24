#include <stdio.h>

int main (){
    long long int a,b, i,p, sum =0;
    printf ("Nhap a , b : ");
    scanf("%lld%lld",&a,&b);
    int check[b+1];
    for (i =a  ; i<=b ; i++){
        check[i] = 1;

    }
    for (p=2 ; p< b ;p++){
        for(i = 2*p ; i<=b ; i+=p){
            check[i] = 0;
        }
    }

    for(i= a ; i <=b ; i++){
        if(check[i]&&i!=1){
            sum+= i;
        }
    }

    printf  ( "Sum = %lld", sum);


    return 0;
}