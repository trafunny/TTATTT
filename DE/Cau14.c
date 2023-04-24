#include <stdio.h>
#include <math.h>

int reverse(int n){
    int rev =0;
    while(n>0){
        rev = rev*10 + n%10;
        n = n/10;
    }
    return rev ;

}

int checkSNT(int n){
    if(n<2) return 0;
    for(int i=2 ; i<= sqrt(n) ;i++){
        if(n%i ==0) return 0;
    }
    return 1;

}

int main (){
    
    for(int i = 100 ; i<1000 ;i++){
        if(checkSNT(i)){
            for(int j=5 ; j<10 ; j++){
                if(reverse(i) == j*j*j){
                    printf ("so can tim la %d \n",i);
                }
            }
        }
    }
    
    return 0;
}