#include <stdio.h>
#include <math.h>
int checkSNT(int n){
    if(n<2) return 0;
    for(int i=2 ; i<= sqrt(n) ; i++){
        if(n%i ==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n ;
    printf ("Nhap n : ");
    scanf("%d",&n);
    int A[n] ;
    for(int i =0 ; i<n ; i++){
        if(checkSNT(A[i])){
            printf("A[%d]=%d\n",i,A[i]);
        }
        
    }
    


    return 0;
}

