#include <stdio.h>
#include <math.h>


void dectoArr(long long int a, int arr[100] ,long long int p , int w ,int t){
    int i,x;
    for (i=t ; i>=0 ;i --){
        arr[i] = a/pow(2,w*i);
        a = a% (long)pow(2,w*i);
    }
}

long long int arrtoDec(int arr[] ,long long int p ,int w,int t ){
    long long int c=0;
    for (int i=t ; i>=0 ;i--){
        c += arr[i]*pow(2,w*i);
    }
    return c;
}   

int cong_CXboi(int arr[], int brr[] , int crr[] , long long int p , int w ,int t){
    int epsilon =0 ,x ;
    
    for (int i=0 ; i <=t ; i++){
        x = arr[i] + brr[i] +epsilon;
        if(x > 255) epsilon =1;
        else epsilon =0;
        crr[i] = x%256 ;
    }
    // printf ("\nc = a+b = %lld , epsilon = %d",arrtoDec(crr,p,w,t),epsilon);
    

    return epsilon;

}

int tru_CXboi(int arr[] , int brr[] , int crr[],long long int p,int w, int t ){
    int epsilon=0 ,x ;
    for (int i=0 ; i<=t ;i++){
        x = arr[i] - brr[i] -epsilon ;
        if(x<0){
            epsilon =1 ;
            x+= 256;
        }else
            epsilon =0 ;
        crr[i] = x ;

    }
    // printf("c =a-b = %lld , epsilon = %d" , arrtoDec(crr,p,w,t) , epsilon);
    return epsilon ;
}

int main(){
    int carr[100] ,aarr [100] ,barr[100],parr[100], w=8, e;
    long long int a=2147483646 ,b=2147483643 ,p=2147483647 ,c;
    //NHAP p ,a,b = ?
    printf ("nhap a ,b <p = ");
    scanf("%lld%lld",&a,&b);
    int  m =log(p)/log(2) , t = m/w; 

    // CHUYEN p,a,b  THANH MANG 
    dectoArr(p,parr,p,w,t);
    
    dectoArr(a,aarr,p,w,t);
    
    dectoArr(b,barr,p,w,t);
    
    // CONG CXB 
    e = cong_CXboi(aarr,barr,carr,p,w,t);
    printf("(e,Ccxb) = (%d,(",e);
    for(int i=t ;i>=0 ;i--){
        printf("  %d ",carr[i]);
    }
    printf (" ))");
    c = arrtoDec(carr,p,w,t) ;
    printf ("\nCcxb = %lld",c);
    // CONG TREN FP
    if(e ==1){
        tru_CXboi(carr,parr,carr,p,w,t);
        c = arrtoDec(carr,p,w,t);

    }else
    if(c>=p){
        tru_CXboi(carr,parr,carr,p,w,t);
        c = arrtoDec(carr,p,w,t);
    }
    printf("\n(e,Carr) = (%d,(",e);
    for(int i=t ;i>=0 ;i--){
        printf("  %d ",carr[i]);
    }
    printf ("))");
    printf("\nc= %lld",c);

    
    return 0;
}