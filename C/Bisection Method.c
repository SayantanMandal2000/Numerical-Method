#include<stdio.h>
#include<math.h>
#define E 0.0001
double f(float x)
{
	//return ((x*x*x)-(9*x)+1);
	return (cos(x)-x*exp(x));
	//return ((9*x*x*x)+(18*x*x)-(37*x)-70);
	//return ((x*x*x)-(3*x)+1.06);
	//return ((x*x*x)-2);
  // enter any function
}
void Bisection(float a, float b)
{
	int i=0;
	if(f(a)*f(b)>=0)
		printf("\nNot correct boundary values");
	else
	{
		float c;
		do
		{
			c=(a+b)/2;
			if(fabs(f(c))<E)
				break;
			else if(f(c)*f(a)<0)
				b=c;
			else
				a=c;
			i++;
			printf("\nRoot after %d iteration=%f and a=%f,b=%f,c=%f",i,f(c),a,b,c);
		}while((b-a)>=E);	
		printf("\nRoot of the equation is: %f",c);
   	}
}
int main()
{
 float a,b;
 printf("\nEnter the value of a:");
 scanf("%f",&a);
 printf("\nEnter the value of b:");
 scanf("%f",&b);
 Bisection(a,b);
 return 0;
}
