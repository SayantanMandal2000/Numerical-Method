#include<stdio.h>
#include<math.h>
#define e 0.00001
double f(float x)
{
	//return (pow(x,3)-9*x+1);
	//return (x*exp(x)-cos(x));
	//return ((9*x*x*x)+(18*x*x)-(37*x)-70);
	return (tan(x)+x); 
}
double df(float x)
{
	//return (3*pow(x,2)-9);
	//return x*exp(x)+exp(x)+sin(x);
	//return ((27*x*x)+(36*x)-37);
	return ((1/(cos(x)*cos(x)))+1);
}
void Newton(float a, float b)
{
	float x0,x1;
	int i=0;
	printf("f(a)=%f f(b)=%f \n\n",f(a),f(b));
	if(f(a)*f(b)>=0)
		printf("Not correct boundary values");
	else
	{
		x0=(a+b)/2.0;
		printf("n \t a \t\t b \t\t x0 \t\t f(x0) \t\t f'(x0) \t x1\n\n");
		do
		{
			i++;
			x1=x0-(f(x0)/df(x0));
			printf("%d\t %f\t %f\t %f\t %f\t %f\t %f\n",i,a,b,x0,f(x0),df(x0),x1);
			if(fabs(f(x1))<=e)
				break;
			else 
				x0=x1;	
		}while(fabs(f(x1))>=e);
		printf("Root of the equation is: %f\n",x1);
		printf("Total number of iterations is: %d",i);
   }
}
int main()
{
 	float a,b;
 	printf("Method used: Newton Ralphson\n");
 	printf("Enter the interval: ");
 	printf("\na=");
 	scanf("%f",&a);
 	printf("b=");
 	scanf("%f",&b);
 	Newton(a,b);
 	return 0;
}

