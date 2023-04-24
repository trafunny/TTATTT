#include <stdio.h>
#include <math.h>
int checkSNT (int n ){
    if(n<2) return 0;
    for(int i=2 ; i<= sqrt(n) ;i++){
        if(n%i ==0) return 0;
    }
    return 1;

}


int main(){
    int n ;
    printf ("nhap n : ");
    scanf("%d", &n);
    for(int i =2 ; i<=n ; i++ ){
        if(checkSNT(i)){
            for(int j =i ; j<=n ;j++ ){
                if(checkSNT(j) && checkSNT(i+j) && checkSNT(j-i)) {
                    printf ("2 SNT can tim la :(%d , %d) \n",i,j);
                } 
            }
        }
    }
    
    return 0;
}
