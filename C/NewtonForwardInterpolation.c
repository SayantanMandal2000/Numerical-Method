#include<stdio.h>
void NewtonForward(int n,float x[10],float y[10],float X)
{
	float f[10][10],h,S,sum=0,t=sum;
	int i,j;
	h=x[1]-x[0];
	S=(X-x[0])/h;
	sum=y[0];
	t=sum;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		   f[i][j]=0;
	}
	for(j=0;j<n;j++)
	{
		f[0][j]=y[j];
	}
		for(i=1;i<n;i++)
		{
			for(j=0;j<n-i;j++)
			{
				f[i][j]=f[i-1][j+1]-f[i-1][j];
			}
		}
		printf("x:\t");
			for(i=0;i<n;i++)
		{
			printf("%f\t",x[i]);
		}
		printf("\nf:\t");
		for(i=0;i<n;)
		{
			for(j=0;j<n;j++)
			{
				if(f[i][j]!=0)
				printf("%f\t",f[i][j]);
			}
			i++;
			printf("\n");
			if(i==1)
			printf("\t\t");
			else if(i==2)
			printf("\t\t\t");
			else if(i==3)
			printf("\t\t\t\t");
			else
			printf("\t\t\t\t\t");
		}
		t=1;
		for(i=1;i<n;i++)
		{
			t=t*(S-i+1)/i;
			sum=sum+t*f[i][0];
		}
		printf("\nf[%.3f]=%.5f",X,sum);
}
int main()
{
	float x[10],y[10],X;
	int n,i;
	printf("\t----NEWTON FORWARD INTERPOLATION METHOD----\n");
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
		printf("%.3f\t",x[i]);
	}
	printf("\nf\t");
	for(i=0;i<n;i++)
	{
		printf("%.5f\t",y[i]);
	}
	printf("\nEnter the value of x for which we need to find the function value: ");
	scanf("%f",&X);
	printf ("\n");
	NewtonForward(n,x,y,X);
}

