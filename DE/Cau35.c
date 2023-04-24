#include <stdio.h>
#include <math.h>
long long int BP_lap(long long int a , long long int k , long long int n){
    long long int c,A;
    c=1 ; A =a%n ;
    
    if(k%2==1){
        c =a;
    }
    k = k/2 ; 
    while(k>0){
        A = (A*A)%n;
        if(k%2==1){
            c = (c*A)%n;
        }
        k/=2;
    }
    return c; 
}


int checkSNT_MR(long long int n , long long int t, long long int a ){
    long long int s,r, j,y ;
    s=0; r= n-1;
    // ptich n = 2^s.r
    while(r%2 == 0){
        ++s;
        r = r/2;
    }
    
    for(long long int i=1 ;i<=t && a<n;i++, a++){
        y = BP_lap(a,r,n);
        
        if(y!=1 && y!= n-1){
            j=1;
            while(j<= s-1 && y!= n-1){
                y= BP_lap(y,2,n);
               

                if(y==1){
                    printf("n= %lld la Hop so ",n);
                    return 0;
                }
                ++j;

            }

            if(y!= n-1){
                printf("n= %lld la hop so",n);
                return 0;
            }
        }       
    }
    printf("n = %lld la SNT !",n);
    return 1;
}

int main(){
    long long int n , t ;
    printf ("Nhap n ,t: ");
    scanf("%lld%lld",&n,&t);
    checkSNT_MR(n,t,2);
    return 0;
}