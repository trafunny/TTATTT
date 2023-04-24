#include <stdio.h>
#include <math.h>
#include <String.h>

int main(){
    // long long int n =100,a;
    // printf ("Nhap n =  ");
    // scanf("%lld",&n);
    // for (a =2 ; a<=n ; a++ ){
    //     int dem =2 ;
    //     for (int j =2; j<= a/2 ; j++){
    //         if(a%j ==0 ) ++dem;

    //      }
    //      if(dem==4) printf ("%lld la so Q-prime !\n",a);

    // }
int num= 0;
while (num <=5) {                                  //0
    if(num <5) {                                   //0 <5
         printf(" %d < %d " ,num, 5);             // 0 <5
        num = num +1;
        printf("num = %d",num)  ;
        
    }
       
    else
         printf(" %d > %d " ,num, 5);
    printf("num = %d",num)  ;
    if( num ==1 || num ==2 || num ==3 || num==4 || num==5  ) 
    continue;
    break;
    
}
    return 0 ; 
}