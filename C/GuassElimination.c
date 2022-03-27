#include<stdio.h>
int Upper(int n,int a[10][10])
{
	int k,i,j;
	float m=1;
	a[n][n+1];
	for(k=0;k<=n-1;k++)
	{
		for(i=k+1;i<n;i++)
		{
			m=(float)a[i][k]/(float)a[k][k];
			for(j=0;j<n+1;j++)
			{
				a[i][j]=a[i][j]-m*a[k][j];
			}
		}
	}
	printf("The Upper triangular matrix is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
		    if(j==n)
		    printf(" : %d\n",a[i][n]);
		    else
			printf("%d ",a[i][j]);
		}
	}
	return 0;
}
int Compute(int a[10][10],int n)
{
	int k,sum=0,j;
	float x[n];
	for(k=0;k<n;k++)
		x[k]=(float)a[k][k+1]/(float)a[k][k];
	for(k=n-2;k>=0;k--)
	{
		sum=0;
		for(j=k+1;j<n;j++)
		{
			sum+=a[k][j]*x[j];
			x[k]=(float)(a[k][n]-sum)/(float)a[k][k];
		}
	}
	printf("\nGiven Equations are:\n5x-y=9\n-x+5y-z=4\n-y+5z=-6\nThe soluton matrix is:\n");
	for(j=0;j<n;j++)
	{
		printf("x[%d]=%f\n",j+1,x[j]);
	}
}
int main()
{
	int i=0,j=0,p;
	int a[10][10];
	printf("-----Guass Elimination Method----\n");
	printf("Enter the augmented matrix::\n");
	printf("Enter the number of rows: ");
	scanf("%d",&p);
	a[p][p+1];
	for(i=0;i<p;i++)
	{
		for(j=0;j<p+1;j++)
		{
		    printf("Enter the elemnt at [%d][%d]: ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("The augmented matrix is:\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<p+1;j++)
		{
		    if(j==p)
		    printf(": %d\n",a[i][p]);
		    else
			printf("%d ",a[i][j]);
		}
	}
	Upper(p,a);
	Compute(a,p);
	return 0;
}

