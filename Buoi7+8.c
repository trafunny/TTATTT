#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>


void TimP_vetcan(){
    char T[1000]  , P[1000] ;
    long long int sizeT , sizeP , dem ,m,n;
    // NHAP van ban T va mau P
    do{
    printf("Nhap T : ");
    fgets(T,sizeof(T) ,stdin);
    printf("Nhap P: ");
    fgets(P,sizeof(P),stdin);
    sizeT = strlen(T) -1;
    sizeP = strlen(P)-1;
    printf("sizeP = %d",sizeP);
    if(sizeP > sizeT) {
        printf("Mau P lon hon van ban T  !!!! NHAP LAI");
    }
    }while(sizeP > sizeT);
    
    // TIM 
    m=0 ; n=0;
    while(n <sizeT && m<sizeP){
        if(m==0) dem =n ;
        if(T[n]==P[m]){
            n+=1;
            m+=1;
        }else{
            m= 0;
            n+=1;
        }
    }
    if(m== sizeP){
        printf("Tim thay P trong T vi tri %lld",dem);
    }else{
        printf("K tim thay mau P trong T");
    }
}

int TimP_BM(){

    char t[1000],p[1000];
    int l[127] ,i; 
    printf("\nNhap T: "); fgets(t,sizeof(t),stdin);
    printf("\nNhap P: "); fgets(p,sizeof(p),stdin); 
    int lap=0;
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
    i=strlen(p)- 2 ;    j=strlen(p)- 2; d=0; 
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
           lap++; 
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


int soSanhChuoi(char p[], int j, int i){
    int check = 0;
    for(int k = 0; k < i; k++){  // kiem tra chuoi tien to voi chuoi tien to
        if(p[k] == p[j - i + k]){   // kiem tra tung ki tu cua chuoi tien to voi ki tu cua chuoi tien to
            check++;
        }
    }
    if(check == i){
        return 1;
    }
    return 0;
}

int kiemTra(char p[], int j){
    for(int i = j-1; i >= 1; i--){
        if(soSanhChuoi(p, j, i) == 1){
            return i;
        }
    }
    return 0;
}

void failureFunction(char p[], int f[]){
    f[0]=-1;
    f[1]=0;
    for(int j = 2; j < strlen(p); j++){
        f[j] = kiemTra(p, j);
    }
}

int xuLy(char t[], char p[], int f[]){
    int i = 0, j = 0, check = 0, sopheptinhlap = 0;
    while(i < strlen(t) - strlen(p) ){
        int checkp = j, k = i+j;
        while(checkp != strlen(p)){
            if(t[k] == p[j]){
                k++;
                j++;
                checkp++;
                sopheptinhlap++;
            } else {
                i = i + j - f[j];
                j = f[j] == -1 ? 0 : f[j];
                sopheptinhlap++;
                break;
            }
        }
        if(checkp == strlen(p)){
            printf("\nKQ: Vi tri %d", i);
            check = 1;
            j=0;
            i=i+strlen(p);
        }
    }
    if(check == 0){
        printf("\nKQ: Khong co chuoi can tim");
    }
    return sopheptinhlap;
}
void TimP_KMP(){
    char t[5000],p[100];
    printf("Nhap doan van ban T: ");
    fflush(stdin);
    gets(t);
    printf("Nhap chuoi P can tim: ");
    fflush(stdin);
    gets(p);
    int f[strlen(p)];
    failureFunction(p, f);
    int sopheptinhlap = xuLy(t, p, f);
    // printf("\nSo phep tinh lap la: %d", sopheptinhlap);
    getch();
}
int main(){
    // TimP_vetcan();
    // TimP_BM();
    // TimP_KMP();
    


    
return 0 ;

    
    
             
}