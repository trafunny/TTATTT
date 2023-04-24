
#include<stdio.h>
#include<math.h>
int isPrime(int n)
{
	int i;
	if (n < 2) return 0;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return 0;
	}
	return 1;
}
int main()
{
	int a,b,sb,i,j,k,Tong,check,count=0;
	printf("Nhap a: "); scanf("%d",&a);
	printf("Nhap b: "); scanf("%d",&b);
	sb=sqrt(b);
	int S1[b],S2[b];
	
	for(i=1;i<=sb;i++)
	{
		if(isPrime(i)){
				S1[i]=i*i;
				S2[i]=i*i;	

			
		}
//		S1[i]=i*i;
//		S2[i]=i*i;	
//	printf("%3d",S1[i]);
	}
	
	for(i=1;i<=sb;i++)
	{
		for(j=1;j<=sb;j++)
			{
			Tong = S1[i] + S2[j];
			if ((Tong>=a) && (Tong<=b))
				{
				if(isPrime(Tong)){
					count++;
				}
				}
			}
	}
	printf ("\n%d",count/2);

}

