#include<stdio.h>
#include<math.h>
#define MAX 10
#define e 0.0001
int main()
{
	int i,j,n;
	float a[MAX][MAX],x[MAX],sum=0.0,m;
	printf("\nEnter the no of equation=");
	scanf("%d",n);
	printf("\nEnter the augmented matrix:");
	for(i=0;i<=n;i++)
	{
		for(j=0;i<=n+1;j++)
		{
			printf("\A[%d][%d]=",i+1,j+1);
			scanf("%f",a[i][j]);
		}
	}
	printf("\nEnter initial guess:");
	for(i=0;i<=n;i++)
		scanf("%f",x[i]);
	do
	{
		m=0;
		for(i=0;i<=n;i++)
		{
			sum=a[i][n+1];
			for(j=1;j<=n;j++)
			{
				if(i!=j)
					sum=sum-a[i][j]*x[j];
			}
			sum=sum/a[i][i];
			if(fabs(x[i]-sum)>m)
				m=fabs(x[i]-sum);
			x[i]=sum;
		}
	}while(m>=e);
	printf("\nThe solution:");
	for(i=1;i<=n;i++)
		printf("\nx[%d]=%f",i+1,x[i]);
	return 0;
}

