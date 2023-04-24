//Viết chương trình tìm bốn số nguyên tố liên tiếp, sao cho tổng của chúng là số nguyên tố nhỏ hơn 
//hoặc bằng N (với N được nhập vào từ bàn phím).

#include <stdio.h>
#include <math.h>

int main (){
    long long int n ;
    scanf("%lld",&n);
    int check[n+1] ;
    for(long long int i =2 ; i<=n ;i++){
        check[i] =1;
        
    }
    for(long long int p=2 ; p<n ;p++){
        if(check[p]){
            for(long long int  j =2*p ; j <=n ; j+=p){
                check[j] = 0;
            }
        }
    }

    int dem = 0;
    long long int tong =0, store[5];
    for(long long int i =2 ; i<=n ;i++){
        if(check[i]==1){
            tong += i;
            ++dem;
            store[dem] =i;
            
        }
        if(dem==4 && tong <=n && check[tong]==1) {
            printf("tong =%lld+%lld+%lld+%lld = %lld\n",store[1],store[2],store[3],store[4],tong);
            dem =0 ;
            i = store[2];
            tong =0;
        }
        else if(dem ==4 && tong >n) break;
        else if(dem==4 && check[tong]!=1){
            dem = 0;
            i = store[2];

        }
    }
    

    return 0;
}