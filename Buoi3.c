#include <stdio.h>
#include <math.h>
int gcd(int a , int b){
    if(b==0) return a;
    else 
        gcd(b,a%b);

    // while(a!=b){
    //     if(a>b){
    //         a =a-b;
    //     }else 
    //      b= b-a;
    // } Tra github 
}
void UCLN(){
    int a, b;
    printf("Nhap a ,b = ");
    scanf("%d%d", &a,&b);
    if(a>b){
        printf("gcd(%d,%d) = %d ", a,b,gcd(a,b));
    }else
        printf("gcd(%d,%d) = %d ", a,b,gcd(b,a));

}

int gcdPro(long long int a, long long int b, int x,int  y, int x2 , int x1 , int y2, int y1){
    //NOTE : KHONG IN DUOC a^-1 =x  , b^-1 =y
    if(b==0){
        return a; 
    }else return gcdPro(b,a%b ,x2-((int)(a/b))*x1, y2 -((int)(a/b))*y1, x1, x,y1,y );

}

int UCLNpro(){

    long long int a= 1759 ,b =550 ,q,r,x2,x1,y2,y1,x,y,d;

    printf ("Nhap a , b : ");
    scanf("%lld%lld" ,&a,&b);
    if(b==0) {
        printf("gcd = %d",a); 
        return 0; //d =a  , x= 1, y=0;
    }
    long long int a1 =a , b1= b;
     x2=1; x1=0 ; y2=0 ; y1 =1;
    while(b>0){
        q = a/b ; r = a%b ; a = b ; b=r ; x= x2 - q*x1; y =y2 - q*y1 ; 
        x2 = x1 ; x1= x ; y2= y1 ; y1= y;
        // printf ("q= %d  r =%d x = %d ,y=%d ,x2 =%d ,x1 =%d ,y2= %d ,y1= %d \n" ,q,r,x,y,x2,x1,y2,y1);
    }
    d = a; x= x2 , y= y2;
    if(x<0){
        x = x + b1;
    }
    if(y <0){
        y = y +a1;
    }
    printf ("gcd = %lld  x = %lld  y= %lld " ,d,x,y);

}

void BP_lap(){
    long long int a = 41, k= 101 , n=211 ,x ,c ;
    printf ("Nhap n ,a ,k (c= a^k mod n) :  ");
    scanf("%lld%lld%lld",&n,&a,&k);
    int t = ceil(log(k)/log(2)) ;
    long long int  A[100] , K[100];
    x = k;
    //CHUYEN DOI k THANH K[t bit]
    for( int i =0 ; i<=t ; i++){
        K[i] = x %2 ;
        x= x/2;
        printf ("K[%d] = %lld  ",i,K[i]);
    } 
    // KHOI TAO GT MANG A[0] , c 
    A[0] = a; 
    if (K[0] ==1 ) c = a; 
    else c =1;
    
    for (int i=1 ; i<=t-1 ; i++){
        A[i] = (A[i-1]*A[i-1]) % n ;
        
        if(K[i] ==1){
            c = A[i]*c %n;
        }
        
    }

    printf("c = %lld ",c%n );
}
int main(){
    //UCLN();
    UCLNpro();   //Tinh nghich dao
    // BP_lap();
    
    



    


    				 



    
    return 0;
}
