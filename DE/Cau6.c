#include <stdio.h>
#include <math.h>
int main(){

    long long int N  ,a,b , store =0  ;
    printf("Nhap N  : ");
    scanf("%lld",&N);
    for(long long int i = 2 ; i<N ; i++){
        a =0; b=0;
        for(long long int j = 1 ; j<=i/2 ;j++){
            if(i%j ==0 ){
                b+= j ;

            }
        }
        for (long long int k=1 ; k<=b/2 ; k++){
            if(b%k ==0){
                a+=k;
            }
        }
        if(a==i && a!=b && store !=b ){
            printf ("So (a,b) = (%lld ,%lld) \n" , a,b);
            store = a ;    //TRANH IN HOAN VI 
        } 
    }

    return 0;

}
