#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    int m=3;
    printf("Nhap n ");
    scanf("%d",&n);
    // printf("Nhap vao m ");
    // scanf("%d",&m);
    int arrayPrime[100];  //MANG SNT
    int k=0;              // dem pt
    int sum=0;
    for(int i=2;i<=n; i++)
    {
        int count=0;     
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                count++;
                break;
            }
        }
        if(count ==0)
        {
            k++;
            arrayPrime[k] = i;
            // printf("%d\t",i);
        }
    }
    int dem;
    for(int i=1; i<=n-2;i++)
    {
        sum =0;
        for(int j=i+1 ; j<=n-1 ;j++){
            for(int k = j+1 ;k<=n ; k++){
                sum = arrayPrime[i] +arrayPrime[j] + arrayPrime[k] ;
                if(sum == n){
                    printf ("%d  %d  %d",arrayPrime[i],arrayPrime[j],arrayPrime[k]);
                    return 0;
                }

            }
        }
        
    }
    // if(sum==n)
    // {
    //     for(int i=1;i<=m;i++)
    //     {
    //     printf("%d\t",arrayPrime[i]);
    //     }
    // }
    return 0;
}