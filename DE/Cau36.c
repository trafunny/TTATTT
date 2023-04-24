#include <stdio.h>
#include <string.h>

int main(){
    char t[1000],p[1000];
    int l[127] ,i; 
    printf("\nNhap T: "); fgets(t,sizeof(t),stdin);
    printf("\nNhap P: "); fgets(p,sizeof(p),stdin); 
    // int lap=0;
    for( i=0;i<127;i++)        //KHOI TAO  L[]
    { 
        l[i]=-1;
    } 
    for( i=0;i<(int)strlen(p)-1;i++)    // ANH XA CHUOI P thanh SO
    {
        l[(int)p[i]]=i; 
    }
    int cong_them,j,d=0;                // i -> T , j-> P , d -> dem so ki tu trung T=P
    for(i=0;i<(int)strlen(p)-1;i++)
    { 
        printf("%c ",p[i]);
        printf("%d \n",l[(int)p[i]]);
    } 
    i=strlen(p)- 2 ;    j=strlen(p)- 2; d=0;    //d: dem ki tu trung 
            //    printf("i=%d j=%d\n",i,j); 

    while(i<strlen(t)-1)
    {   d=0; 
        while(d!=strlen(p)-1)
        { 
        if(t[i]==p[j])
        {
            // printf("t[%d] = p[%d] = %c\n",i,j,t[i]); 
            i--;j--; 
            d++;
            // lap++; 
            // printf("i=%d j=%d\n",i,j);
 
        }
        else
        { 
            int min;
            if (j > 1 + l[(int)t[i]]) // ki tu trung nam ve phia ben phai cua P 
            {
                min = 1 + l[(int)t[i]]; 
            }
            else                      // Ki tu trung nam ve phia trai cua P
            { 
                min = j;
            } 
            //  printf("Chu cai t la %c\n",t[i]);
            // printf("i=%d j=%d min=%d\n",i,j,min);
        //   printf("1+ l=%d\n",l[(int)t[i]]+1); 
          if(min==0)
           i = i + strlen(p) -1 - min; 
           if(min!=0)
            i = i + strlen(p) -1 - min;
           j = strlen(p) - 1 -1; 
        //    printf("=> i=%d j=%d\n",i,j);
        //    lap++; 
           break;
        } 
        }
        if (d == strlen(p)-1)
        { 
            printf("P co trong T, bat dau tai vi tri %d\n", i+2 );
            // printf("\nLap: %d",lap); 
            return 1;
        }
    } 
    printf("P khong co trong T\n");
    return 0;
    // printf("\nLap: %d",lap); 
}