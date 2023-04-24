#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void SNT_simple(long long int n){
    long long int i,j;
    long dem =0 ;
    
    for( i=2 ; i<=n; i++){
        int check = 1;
        for( j=2 ; j<i ; j++){
            if(i%j == 0){
                check =0;
                break;
            }
        }
        if(check){ printf ("%d la so nguyen to \n",i); ++dem;}
    }
    printf ("Co %d  SNT tu 1-n !",dem);
}

void SNT_E(long long int n){
    
    int check[n]; //KT vs 2 GT 0 vs 1
    for(long long int i=2 ;i <=n;i++){
        check[i] =1;
    }
    for(long long int i=2; i<=n;i++){
        if(check[i]==1){
            for(long long int j = 2*i ; j<=n; j+=i){
                check[j] =0;
            }

        }
        
    }
    long long int dem =0;
    for(long long int i=2; i<=n ;i++){
        if(check[i] ==1) {
            printf("%lld\n" ,i);
            ++dem;
        }
        
    }
    printf ("dem = %lld",dem);
}

void SNT_phandoan(long long int n){
    long long int delta = sqrt(n) , m ,top ,bot ,i,j,h,count =0;
    long long int check[n+1];
    // KHOI TAO MANG CHECK SNT
    for ( i = 2; i <=n; i++){
        check[i] =1 ;
    }
    // SANG E CHO DOAN  DAU TIEN
    for(i =2 ; i<= delta +1 ;i++){
        if(check[i] == 1){
            for(long long int j =2*i ; j<=delta+1 ; j += i){
                check [j] =0;   
            }
        }
    }
    // SANG PHAN DOAN CHO CAC DOAN TIEP THEO
    bot = delta +2 ; top = bot + delta -1 ;
    while(bot <=n && top <=n){
        m = sqrt(top);
        for( i=2 ; i<=m ; i++ ){
            if(check[i] ==1){
                for(j=bot ; j <= top ; j++){
                    if(check[j]){
                        for(h = 2*i ; h <= top ; h+=i){
                            if(h==j){ check[j] =0 ;}
                        }
                    }
                }
            }
        }

        bot+= delta ; top +=delta ;
        if(top> n) top =n;
    }
    // IN RA SNT
    
    for( i=2 ; i<=n ; i++){
        if(check[i] == 1){
        count = count +1 ;
        printf("%lld  ",i);
        }
    }
    printf("\ncount = %lld",count);
}

long long int gcd (long long int a, long long int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

void pTichthanhthuaso(long long int n){
    long long int a ,b,d;
    a=2 ; b=2 ;d =0;
    for(;;){
        a= (a*a +1)%n ; 
        b= (b*b +1)%n ; 
        b= (b*b +1)%n ;
        if(b-a>0)
        d = gcd(b-a,n);
        else d = gcd(a-b,n);
        
        if(d>1 && d <n){
            printf("Phan tich thanh cong  thua so n = %lld*b",d);
            break;
        }else if(d==n) {
            printf("THAT BAI !!!!");
            break;
        }
    }
}

void checkSNT(long long int n){
     
    int check =1;
    for (long long int i=2 ; i<sqrt(n) +1 ; i++){
        if(n%i==0){
            check =0 ;
        }
    }
    if(check)  printf(" Vay %lld La SNT ^_^ " , n);
    else printf ("vay %lld Khong Phai SNT +_+",n);
}

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

int checkSNT_Fermat(long long int n, long long int t){
    long long int a ,r ;
    
    for (long long int i= 0 , a=2 ; i<t&&a<n ; i++,a++ ){
        
        r = BP_lap(a,n-1,n);
    
        if(r!=1){
            printf ("\n%lld La Hop so",n);
            return 1;
        }
    }
    printf("\n%lld LA SNT ",n);
}

int checkSNT_MR(long long int n , long long int t, long long int a ){
    long long int s,r, j,y ;
    s=0; r= n-1;
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

int random(int index , int k){
    int r;
    srand((int) index);
    r = rand() ;
    int n = 2 + r %((int)pow(2,k) -2 +1);
    // printf("so ngau nhien r = %d",r);
    return n;
}

int sinhSNT(int k, int index){
    int n;
    int A[10] = {2,3,5,7,11,13,17,19,23,29};
    // Random So N ngau nhien k bit
    n = random(index,k);
    // Test voi mang A nho
    for(int i =0 ; i<10 ;i++){
        if(n %A[i] ==0 && n!=A[i] ){
            printf("%d La Hop So\n" ,n);
            return sinhSNT(k,index +1);
            
        }
    }
    // Dung thuat toan MR check N la SNT hay k ?

    int check = checkSNT_MR(n,1,2);
    if(check) return 1;
    else {
        return sinhSNT(k,index+1);
    }
}

int main(){ // Bai 10 , 11,12,13 ,14,15 )

    // SNT_simple(150);             //10_1: SANG SNT THONG THUONG
    // SNT_E(61);                  //10_2: SANG SNT Erosthenes
    // SNT_phandoan();           //10_3: SANG PHAN DOAN
    // pTichthanhthuaso(455459);
    // checkSNT(99109 );
    // checkSNT_Fermat(561,1);
    // checkSNT_MR(91,1,9);
    // sinhSNT(32,99999);
    // printf("n = %d",random(4,7));

    return 0;
}