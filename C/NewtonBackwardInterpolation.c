#include<stdio.h>
void NewtonBackward(int n,float x[10],float y[10],float X)
{
	float f[10][10],h,S,sum=0,t=sum;
	int i,j,b;
	h=x[1]-x[0];
	S=(X-x[n-1])/h;
	sum=y[n-1];
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
			else if(i==4)
			printf("\t\t\t\t\t");
			else
			printf("\t\t\t\t\t\t");
		    }
		t=1;
		for(i=1;i<n;i++)
		{
			t=t*(S+i-1)/i;
			sum=sum+t*f[i][n-i-1];
		}
		printf("\nThe value of f[%.2f]=%.5f\n\n",X,sum);
}
int main()
{
	float x[10],y[10],X;
	int n,i;
	printf("\t----NEWTON BACKWARD INTERPOLATION METHOD----\n");
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	printf("Enter the values of x:\n");
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
	printf("\nValues entered\n");
	printf("x\t");
	for(i=0;i<n;i++)
	{
		printf("%.2f\t",x[i]);
	}
	printf("\nf\t");
	for(i=0;i<n;i++)
	{
		printf("%.4f\t",y[i]);
	}
	printf("\n\nEnter the value of x for which we need to find the function value: ");
	scanf("%f",&X);
	printf("\n");
	NewtonBackward(n,x,y,X);
	return 0;
}

