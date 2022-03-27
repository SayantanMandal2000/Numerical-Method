#include<stdio.h>
void Lagrange(int n,float x[100],float y[100],float X)
{
	int i,j;
	float p=0,term=0;
	for(i=0;i<n;i++)
	{
		term=1;
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				term=term*((X-x[j])/(x[i]-x[j]));
			}
		}
		p=p+term*y[i];
	}
	printf("The value of f(%.1f)= %.2f",X,p);
}
int main()
{
	float x[100],y[100],X;
	int n,i;
	printf("\t---LAGRANGE’S INTERPOLATION METHOD---\n");
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	printf("Enter the values of x:\n ");
	for(i=0;i<n;i++)
	{
		printf("x[%d]= ",i);
		scanf("%f",&x[i]);
	}
	printf("Enter the values of function f corresponding to the values of x: \n");
	for(i=0;i<n;i++)
	{
		printf("f[%d]= ",i);
		scanf("%f",&y[i]);
	}
	printf("Values entered\n");
	printf("x\t");
	for(i=0;i<n;i++)
	{
		printf("%.1f\t",x[i]);
	}
	printf("\nf\t");
	for(i=0;i<n;i++)
	{
		printf("%.2f\t",y[i]);
	}
	printf("\nEnter the value of x for which we need to find the function value: ");
	scanf("%f",&X);
	Lagrange(n,x,y,X);
}

