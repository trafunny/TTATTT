#include <stdio.h>
#include <math.h>

int main(){
    long long int n =101 ,dem =2; 
    scanf("%lld",&n);
    for(long long int i=2 ; i<= n ; i++){
        dem =2; 
        for(long long int j =2 ; j <= i/2 ; j++){
            if(i%j == 0){
                ++dem;
            }
            if(dem >3) break;
        }
        if(dem ==3) printf ("%lld  ",i);
    }
    
    return 0;
}