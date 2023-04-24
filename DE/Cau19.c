#include <stdio.h>
#include <math.h>

int check_SNT(long long int n){
    if(n<2) return 0;
    for( long long int i =2 ; i<= sqrt(n) ; i++){
        if(n%i ==0 ) return 0;
    }
    return 1; 

}



int main(){
    int A,B,C,n,m ;
   
    printf("Nhap A,B,C,n,m (n<m): ");
    scanf("%d%d%d%d%d",&A,&B,&C,&n,&m);
    while (n >= m){
        printf("Nhap lai n<m : \n");
        scanf("%d%d", &n, &m);
    }
    long long int result ;
   
    for ( long long int i =n ; i<= m ; i++){ // NOTE : 
        result = A*i*i + B*i + C;
        
        if(check_SNT(result)) {
            // printf ("result = %lld",result);
            printf ("x = %lld la so nho nhat t/m",i);
            return 1;
        }
       
        
    }
    printf("Khong tim thay x thoa man!");


    return 0;
}