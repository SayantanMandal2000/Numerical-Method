#include<stdio.h>
#include<math.h>
#define e 0.0001
double func(float x)
{
	//return ((x*x*x)-(9*x)+1);
	//return (cos(x)-x*exp(x));
	//return ((9*x*x*x)+(18*x*x)-(37*x)-70);
	return (1-exp(-x)-(x/5));
}
void RegulaFalsi(float x0, float x1)
{
	if(func(x0)*func(x1)>=0)
		printf("\nNot correct boundary values");
	else
	{
		float x2=x0;
		int i=-1;
		printf("\nf(x0)=%f  \t  f(x1)=%f\n",func(x0),func(x1));
		printf("n \t\t x0 \t\t f(x0) \t\t x1 \t\t f(x1) \t\t c \t\t f(c)");
		do 
		{
			x2=x0-((x1-x0)*func(x0))/(func(x1)-func(x0));
			i++;
			printf("\n%d \t %f \t %f \t %f \t %f \t %f \t %f ",i,x0,func(x0),x1,func(x1),x2,func(x2));
			if(fabs(func(x2))<=e)
				break;
			else if(func(x2)*func(x0)<0)
				x1=x2;
			else if(func(x2)*func(x1)<0)
				x0=x2;
		}while((x1-x0)>=e);
		printf("\nRoot of the equation(by Regula Falsi method) is= %f",x2);
		printf("\nTotal number of iterations in Regula-Falsi method is= %d",i);	
	}
}
void Bisection(float a, float b)
{
	int i=0;
	if(func(a)*func(b)>=0)
		printf("\nNot correct boundary values");
	else
	{
		float c;
		do
		{
			c=(a+b)/2;
			if(fabs(func(c))<e)
				break;
			else if(func(c)*func(a)<0)
				b=c;
			else
				a=c;
			i++;
		}while((b-a)>=e);	
		printf("\n\nRoot of the equation(by Bisection method) is=%f",c);
		printf("\nThe no of iteration in Bisection method= %d",i);
   	}
}
int main()
{
 	float x0,x1;
 	printf("Enter the interval: ");
 	printf("\nx0=");
 	scanf("%f",&x0);
 	printf("x1=");
 	scanf("%f",&x1);
 	RegulaFalsi(x0,x1);
 	Bisection(x0,x1);
 	return 0;
}

